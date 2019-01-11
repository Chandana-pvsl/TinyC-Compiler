%{
	#include "ass5_16cs30026_translator.h"
	#include <stdio.h>
	void yyerror(string s);
	extern int yylex();
	#include <iostream>
	#include <cstdlib>
	#include <string>
	#include <sstream>
	extern string curr_type;
	#define YYDEBUG 1
    using namespace std;
%}
%union {
  int intval;
  char* charval;
  int instr;
  sym_det* symp;
  type* symtp;
  expr* E;
  statement* S;
  array* A;
  char un;
} 
%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token BOOL COMPLEX IMAGINARY
%token STRUCT UNION ENUM
%token BREAK CASE CONTINUE DEFAULT DO IF ELSE FOR GOTO WHILE SWITCH SIZEOF
%token RETURN
%token<symp> IDENTIFIER
%token<intval> INTEGER_CONSTANT
%token<charval> FLOATING_CONSTANT
%token<charval> CHAR_CONSTANT ENUM_CONSTANT 
%token<charval> STRING_LITERAL
%token ELLIPSE ASSIGN ASSIGN_RS ASSIGN_LS ASSIGN_ADD ASSIGN_SUB ASSIGN_MUL 
%token ASSIGN_DIV ASSIGN_MODULO ASSIGN_BIT_AND ASSIGN_BIT_XOR ASSIGN_BIT_OR RS LS 
%token INCREMENT DECREMENT  AND OR LTE GTE EQ NEQ LT GT ARROW
%token BIT_AND BIT_OR BIT_XOR

%start translation_unit
%right THEN ELSE

//declaring the type of grammar rules
%type <E> expression
	primary_expression 
	multiplicative_expression
	additive_expression
	shift_expression
	relational_expression
	equality_expression
	AND_expression
	exclusive_OR_expression
	inclusive_OR_expression
	logical_AND_expression
	logical_OR_expression
	conditional_expression
	assignment_expression
	expression_statement
	expression_opt

%type <intval> argument_expression_list

%type <A> postfix_expression
	unary_expression
	cast_expression

%type <un> unary_operator
%type <symp> constant initializer
%type <symp> direct_declarator init_declarator declarator
%type <symtp> pointer

//Auxillary non terminals M and N
%type <instr> M
%type <S> N
%type <S>  statement
	labeled_statement 
	compound_statement
	selection_statement
	iteration_statement
	jump_statement
	block_item
	block_item_list



%%
// To store the address of the next instruction for further use.
M 	: 
	/*epsilon*/{	
		$$ = nextinstr();
	}
;

// Non terminal to prevent fallthrough by emitting a goto
N 	: 
	/*epsilon*/{ 	 
			$$  = new statement();
			$$->nextlist = makelist(nextinstr());
			emit ("GOTO","");
		}
;

primary_expression:
			IDENTIFIER 
			{
				$$ = new expr();   
				$$->loc= $1;
				$$->tp = "NONBOOL";
			}					
			|constant 	
			{
				$$ = new expr();
				$$->loc = $1;
			}				
			|STRING_LITERAL
			{
				$$ = new expr();
				type* temp = new type("PTR");//a pointer to character array
				$$->loc = gentemp(temp,$1);
				$$->loc->tp->p = new type("CHAR"); 
			} 			
			|'(' expression ')'
			{
				$$ = $2;
			} 		
;

constant:
		INTEGER_CONSTANT 
		{
			stringstream strs;
    		strs << $1;
    		string temp_str = strs.str();
    		char* intStr = (char*) temp_str.c_str();
			string str = string(intStr);
			$$ = gentemp(new type("INTEGER"), str);
			emit("ASSIGN", $$->name, $1,"");
		}		
		|FLOATING_CONSTANT
		{
			$$ = gentemp(new type("FLOAT"),string($1));
			emit("ASSIGN",$$->name,string($1));
		} 		
		|ENUM_CONSTANT
		{

		}		

		|CHAR_CONSTANT	
		{
			$$ = gentemp(new type("CHAR"), $1);
			emit("ASSIGN",$$->name, string($1));
		}		
;

postfix_expression:
			primary_expression 								
			{
				$$ = new array();
				$$->array = $1->loc;
				$$->loc = $$->array;
				$$->tp = $1->loc->tp;
			}
			|postfix_expression '[' expression ']' 
			{
				$$ = new array();
				$$->array = $1->loc;  // copy the base
				$$->tp = $1->tp->p;	  // type = type of element
				$$->loc = gentemp(new type("INTEGER"),"null");//store computed address

				// New address = already computed + $3 * new width
				if($1->cat=="ARR")// if something already computed
				{
					sym_det* t = gentemp(new type("INTEGER"),"null");
					stringstream strs;
		    		strs <<size_type($$->tp);
		    		string temp_str = strs.str();
		    		char* intstr = (char*) temp_str.c_str();
					string str = string(intstr);				
 					emit ("MULT", t->name, $3->loc->name, str);
					emit ("ADD", $$->loc->name, $1->loc->name, t->name);
				}
				else {
 					stringstream strs;
		    		strs <<size_type($$->tp);
		    		string temp_str = strs.str();
		    		char* intStr1 = (char*) temp_str.c_str();
					string str1 = string(intStr1);		
	 				emit("MULT", $$->loc->name, $3->loc->name, str1);
		 		}
		 		// Mark that it contains array address and first time computation is done
		 		$$->cat = "ARR";

			}	
			|postfix_expression '(' ')' 
			{
				$$ = new array();
				$$->array = gentemp($1->tp,"null");
				$1->loc->update(new type("FUNC"));
				emit("CALL", $$->array->name, $1->array->name, "0");

			}	        
			|postfix_expression '(' argument_expression_list')'
			{
				$$ = new array();
				$$->array = gentemp($1->tp,"null");
				$1->loc->update(new type("FUNC"));
				stringstream strs;
				strs <<$3;
	    		string temp = strs.str();
	    		char* s = (char*) temp.c_str();
				string str = string(s);		
				emit("CALL", $$->array->name, $1->array->name, str);
			}
			|postfix_expression '.' IDENTIFIER 	
			{

			}				
			|postfix_expression ARROW IDENTIFIER 
			{

			} 				
			|postfix_expression INCREMENT 	
			{
				$$ = new array();
				// copy $1 to $$
				$$->array = gentemp($1->array->tp,"null");
				emit("ASSIGN",$$->array->name,$1->array->name);
				// Increment $1
				emit("ADD",$1->array->name,$1->array->name,"1");
			}					
			|postfix_expression DECREMENT 
			{
				$$ = new array();
				// copy $1 to $$
				$$->array = gentemp($1->array->tp,"null");
				emit("ASSIGN",$$->array->name,$1->array->name);
				// Decrement $1
				emit("SUB",$1->array->name,$1->array->name,"1");
			}					
			|'(' type_name ')' '{' initializer_list '}'
			{
				$$ = new array();
				$$->array = gentemp(new type("INTEGER"),"null");
				$$->loc = gentemp(new type("INTEGER"),"null");
			} 	
			|'(' type_name ')' '{'initializer_list ',' '}' 	
			{
				$$ = new array();
				$$->array = gentemp(new type("INTEGER"),"null");
				$$->loc = gentemp(new type("INTEGER"),"null");
			} 
;


argument_expression_list:
			assignment_expression 						
			{	
				emit("PARAM", $1->loc->name);
				$$ = 1;
			}
			|argument_expression_list ',' assignment_expression  
			{
				emit("PARAM", $3->loc->name);
				$$ = $1+1;
			}
;

unary_expression:
			postfix_expression 	
			{
				$$ = $1;
			}					
			|INCREMENT unary_expression
			{
				// Increment $1
				emit("ADD",$2->array->name,$2->array->name,"1");
				// Use the same value
				$$ = $2;
			} 			
			|DECREMENT unary_expression 
			{
				// Decrement $1
				emit("SUB",$2->array->name,$2->array->name,"1");
				// Use the same value
				$$ = $2;
			}			
			|unary_operator cast_expression 
			{
				$$ = new array();
				if($1=='&')
				{
					$$->array = gentemp(new type("PTR"),"null");
					$$->array->tp->p = $2->array->tp; 
					emit ("ADDRESS", $$->array->name, $2->array->name);
				}
				else if($1=='*')
				{
					$$->cat = "PTR";
					$$->loc = gentemp($2->array->tp->p,"null");
					emit ("ASSIGN_PTR", $$->loc->name, $2->array->name);
					$$->array = $2->array;
				}
				else if($1=='+')
				{
					$$ =$2;
				}
				else if($1=='-')
				{
					$$->array = gentemp(new type($2->array->tp->sym_type),"null");
					emit ("U_MINUS", $$->array->name, $2->array->name);
				}
				else if($1=='~')
				{
					$$->array = gentemp(new type($2->array->tp->sym_type),"null");
					emit ("BIT_NOT", $$->array->name, $2->array->name);
				}
				else if($1=='!')
				{
					$$->array = gentemp(new type($2->array->tp->sym_type),"null");
					emit ("NOT", $$->array->name, $2->array->name);
				}
			}		
			|SIZEOF unary_expression
			{

			} 				
			|SIZEOF '(' type_name ')'
			{

			} 				
;

unary_operator:
			BIT_AND  
			{
				$$ = '&';
			}								
			|'*'
			{
				$$ = '*';
			}									
			|'+'
			{
				$$ ='+' ;
			} 									
			|'-'
			{
				$$ = '-' ;
			} 									
			|'~'
			{
				$$ = '~' ;
			}									
			|'!'
			{
				$$ = '!';
			}									
;

cast_expression:
			unary_expression 	
			{
				$$ = $1;
			}					
			|'(' type_name ')' cast_expression
			{
				$$ = $4;
			} 		
;

multiplicative_expression:
			// Now the cast expression can't go to LHS of assignment_expression
		// So we can safely store the rvalues of pointer and arrays in temporary
		// We don't need to carry lvalues anymore
			cast_expression 
			{
				$$ = new expr();
				if($1->cat=="ARR")// Array
				{
					$$->loc = gentemp($1->loc->tp,"null");
					emit("ARR_RT", $$->loc->name, $1->array->name, $1->loc->name);
				}
				else if($1->cat=="PTR")// Pointer
				{
					$$->loc = $1->loc;
				}
				else // otherwise
				{
					$$->loc = $1->array;
				}
			}						
			|multiplicative_expression'*' cast_expression
			{
				if(typecheck($1->loc,$3->array))
				{
					$$ = new expr();
					$$->loc = gentemp(new type($1->loc->tp->sym_type),"null");
					emit("MULT",$$->loc->name,$1->loc->name,$3->array->name);
				}
				else
				cout <<"type error"<<endl;
			} 		
			|multiplicative_expression '/' cast_expression 
			{
				if(typecheck($1->loc,$3->array))
				{
					$$ = new expr();
					$$->loc = gentemp(new type($1->loc->tp->sym_type),"null");
					emit("DIV",$$->loc->name,$1->loc->name,$3->array->name);
				}
				else
				cout <<"type error"<<endl;
			}		
			|multiplicative_expression '%' cast_expression 
			{
				if(typecheck($1->loc,$3->array))
				{
					$$ = new expr();
					$$->loc = gentemp(new type($1->loc->tp->sym_type),"null");
					emit("MOD",$$->loc->name,$1->loc->name,$3->array->name);
				}
				else
				cout <<"type error"<<endl;
			}		
;

additive_expression:
			multiplicative_expression 						
			{
				$$ = $1;
			}
			|additive_expression '+' multiplicative_expression
			{
				if(typecheck($1->loc,$3->loc))
				{
					$$ = new expr();
					$$->loc = gentemp(new type($1->loc->tp->sym_type),"null");
					emit("ADD",$$->loc->name,$1->loc->name,$3->loc->name);
				}
				else
				cout <<"type error"<<endl;
			}
			|additive_expression '-' multiplicative_expression 
			{
				if(typecheck($1->loc,$3->loc))
				{
					$$ = new expr();
					$$->loc = gentemp(new type($1->loc->tp->sym_type),"null");
					emit("SUB",$$->loc->name,$1->loc->name,$3->loc->name);
				}
				else
				cout <<"type error"<<endl;
			}	
;

shift_expression:
			additive_expression 							
			{
				$$=$1;
			}
			|shift_expression LS additive_expression 
			{
				if($3->loc->tp->sym_type == "INTEGER")
				{
					$$ = new expr();
					$$->loc = gentemp(new type("INTEGER"),"null");
					emit("LEFT_SHIFT",$$->loc->name,$1->loc->name,$3->loc->name);
				}
				else cout<<"TYpe error"<<endl;
			}
			|shift_expression RS additive_expression
			{
				if($3->loc->tp->sym_type == "INTEGER")
				{
					$$ = new expr();
					$$->loc = gentemp(new type("INTEGER"),"null");
					emit("RIGHT_SHIFT",$$->loc->name,$1->loc->name,$3->loc->name);
				}
				else cout<<"Type error"<<endl;
			} 		
;

relational_expression:
			shift_expression 
			{
				$$ =$1;
			}								
			|relational_expression LT shift_expression  
			{
				if(typecheck($1->loc,$3->loc))// New bool
				{
					$$=new expr();
					$$->tp = "BOOL";
					$$->truelist=makelist(nextinstr());
					$$->falselist= makelist(nextinstr()+1);
					emit("LT","",$1->loc->name,$3->loc->name);
					emit("GOTO","");
				}
				else cout<<"type error"<<endl;
			}	
			|relational_expression GT shift_expression 	
			{
				if(typecheck($1->loc,$3->loc))
				{
					$$=new expr();// New bool
					$$->tp = "BOOL";
					$$->truelist=makelist(nextinstr());
					$$->falselist= makelist(nextinstr()+1);
					emit("GT","",$1->loc->name,$3->loc->name);
					emit("GOTO","");
				}
				else cout<<"type error"<<endl;
			}
			|relational_expression LTE shift_expression 
			{
				if(typecheck($1->loc,$3->loc))
				{
					// New bool
					$$=new expr();
					$$->tp = "BOOL";
					$$->truelist=makelist(nextinstr());
					$$->falselist= makelist(nextinstr()+1);
					emit("LTE","",$1->loc->name,$3->loc->name);
					emit("GOTO","");
				}
				else cout<<"type error"<<endl;
			}	
			|relational_expression GTE shift_expression
			{
				if(typecheck($1->loc,$3->loc))
				{
					// New bool
					$$=new expr();
					$$->tp = "BOOL";
					$$->truelist=makelist(nextinstr());
					$$->falselist= makelist(nextinstr()+1);
					emit("GTE","",$1->loc->name,$3->loc->name);
					emit("GOTO","");
				}
				else cout<<"type error"<<endl;
			} 	
;

equality_expression:
			relational_expression 
			{

				$$=$1;
			}							
			|equality_expression EQ relational_expression 
			{
				// If any is bool get its value
				if(typecheck($1->loc,$3->loc))
				{
					convertBool2Int($1);  
					convertBool2Int($3);
					$$=new expr();
					$$->tp = "BOOL";
					$$->truelist=makelist(nextinstr());
					$$->falselist= makelist(nextinstr()+1);
					emit("EQ","",$1->loc->name,$3->loc->name);
					emit("GOTO","");
				}
				else cout<<"type error"<<endl;
			}	
			|equality_expression NEQ relational_expression 	
			{
				if(typecheck($1->loc,$3->loc))
				{
					// If any is bool get its value
					convertBool2Int($1);
					convertBool2Int($3);
					$$=new expr();
					$$->tp = "BOOL";
					$$->truelist=makelist(nextinstr());
					$$->falselist= makelist(nextinstr()+1);
					emit("NEQ","",$1->loc->name,$3->loc->name);
					emit("GOTO","");
				}
				else cout<<"type error"<<endl;
			}
;

AND_expression:
			equality_expression
			{

				$$=$1;
			} 							
			|AND_expression BIT_AND equality_expression 
			{
				if(typecheck($1->loc,$3->loc))
				{
					convertBool2Int($1);
					convertBool2Int($3);
					$$=new expr();
					$$->tp = "NONBOOL";
					$$->loc = gentemp(new type("INTEGER"),"null");
					emit("BIT_AND",$$->loc->name,$1->loc->name,$3->loc->name);
					}
				else cout << "Type Error"<< endl;
			}	
;

exclusive_OR_expression:
			AND_expression 	
			{

				$$=$1;
			}								
			|exclusive_OR_expression BIT_XOR AND_expression 
			{
				// If any is bool get its value
				if(typecheck($1->loc,$3->loc))
				{
					convertBool2Int($1);
					convertBool2Int($3);
					$$=new expr();
					$$->tp = "NONBOOL";
					$$->loc = gentemp(new type("INTEGER"),"null");
					emit("XOR",$$->loc->name,$1->loc->name,$3->loc->name);

				}
				else cout << "Type Error"<< endl;
			};

inclusive_OR_expression:
			exclusive_OR_expression 
			{
				$$=$1;
			}						
			|inclusive_OR_expression BIT_OR exclusive_OR_expression
			{
				// If any is bool get its value
				if(typecheck($1->loc,$3->loc))
				{
					convertBool2Int($1);
					convertBool2Int($3);
					$$=new expr();
					$$->tp = "NONBOOL";
					$$->loc = gentemp(new type("INTEGER"),"null");
					emit("BIT_OR",$$->loc->name,$1->loc->name,$3->loc->name);

				}
				else cout << "Type Error"<< endl;
			}; 	
;

logical_AND_expression:
			inclusive_OR_expression
			{
				$$ = $1;
			} 					
			|logical_AND_expression N AND M inclusive_OR_expression
			{
					// If any is bool get its value
					convertInt2Bool($5);
					backpatch($2->nextlist,nextinstr());
					convertInt2Bool($1);
					$$=new expr();
					$$->tp = "BOOL";
					//$$->loc = gentemp(new type($1->loc->tp->sym_type),"null");
					//$$->loc = gentemp(new type("BOOL"));
					backpatch($1->truelist,$4);
					$$->truelist = $5->truelist;
					$$->falselist = merge($1->falselist,$5->falselist);
			} 		
;

logical_OR_expression:
			logical_AND_expression 
			{
				$$ = $1;
				//backpatch($$->falselist,nextinstr());
				//backpatch($$->truelist,nextinstr());
			}			
			|logical_OR_expression N OR M logical_AND_expression 	
			{
				convertInt2Bool($5);
					// N to convert $1 to bool
					backpatch($2->nextlist,nextinstr());
					convertInt2Bool($1);
					$$=new expr();
					$$->tp = "BOOL";
					//$$->loc = gentemp(new type($1->loc->tp->sym_type));
					//$$->loc = gentemp(new type("BOOL"));
					backpatch($1->falselist,$4);
					$$->truelist = merge($1->truelist,$5->truelist);
					$$->falselist = $5->falselist;
			}	
;

conditional_expression:
			logical_OR_expression 
			{
				$$=$1;
				//backpatch($$->falselist,nextinstr());
				//backpatch($$->truelist,nextinstr());
			}			
			|logical_OR_expression N '?' M expression N ':' M conditional_expression 	
			{
				$$->loc = gentemp($5->loc->tp,"null");
				$$->loc->update($5->loc->tp);
				emit("ASSIGN", $$->loc->name, $9->loc->name);
				list<int> l = makelist(nextinstr());
				emit ("GOTO", "");

				backpatch($6->nextlist, nextinstr());
				emit("ASSIGN", $$->loc->name, $5->loc->name);
				list<int> m = makelist(nextinstr());
				l = merge (l, m);
				emit ("GOTO", "");

				backpatch($2->nextlist, nextinstr());
				convertInt2Bool($1);
				backpatch ($1->truelist, $4);
				backpatch ($1->falselist, $8);
				backpatch (l, nextinstr());
			}
;


assignment_expression:
			conditional_expression 
			{
				$$=$1;
			}			
			|unary_expression assignment_operator assignment_expression 
			{
				if($1->cat=="ARR")
				{
					$3->loc = conv($3->loc, $1->tp->sym_type);
					sym_det* t = gentemp(new type("INTEGER"),"null");
					sym_det* t1 = gentemp(new type("INTEGER"),"null");
					emit("ADDRESS",t->name,$1->array->name,"");
					emit("ADD",t1->name,t->name,$$->loc->name);
					emit("PTR_ASSIGN",t1->name,$3->loc->name);
					
				}
				else if($1->cat=="PTR")
				{
					emit("PTR_ASSIGN", $1->array->name, $3->loc->name);	
				}
				else
				{
					if(!$3->loc)
					{
						//cout <<$3->type <<endl; //Changed
						convertBool2Int($3);
					}
					$3->loc = conv($3->loc, $1->array->tp->sym_type);
					emit("ASSIGN", $1->array->name, $3->loc->name,"");
				}
				$$ = $3;
			}		
;

assignment_operator:
			ASSIGN 	{}			
			|ASSIGN_MUL{} 		
			|ASSIGN_DIV {} 		
			|ASSIGN_MODULO{} 		
			|ASSIGN_ADD		{}	
			|ASSIGN_SUB		{}	
			|ASSIGN_LS		{}	
			|ASSIGN_RS 		{}	
			|ASSIGN_BIT_AND {}	
			|ASSIGN_BIT_XOR {}	
			|ASSIGN_BIT_OR 	{}	
;


expression:
			assignment_expression 
			{
				$$=$1;
			}	
			|expression ',' assignment_expression 
			{
				//
			}

constant_expression:
			conditional_expression 
			{
			}			
;

declaration:
			declaration_specifiers init_declarator_list ';'
			{

			} 
			|declaration_specifiers ';'{} 		
;


declaration_specifiers:
			storage_class_specifier declaration_specifiers {}
			|storage_class_specifier 		{}				
			|type_specifier declaration_specifiers {}	
			|type_specifier 	{}							
			|type_qualifier declaration_specifiers {}		
			|type_qualifier 	{}							
			|function_specifier declaration_specifiers {}	
			|function_specifier {}								
;

init_declarator_list:
			init_declarator 
			{
				//
			}								
			|init_declarator_list ',' init_declarator {}		
;

init_declarator:
			declarator 
			{
				$$=$1;
			}										
			|declarator ASSIGN initializer
			{
				if($3->init_value!="")
					$1->init_value=$3->init_value;
				emit("ASSIGN",$1->name,$3->name);
			} 					
;

storage_class_specifier:
			EXTERN {}							
			|STATIC {}						
			|AUTO   {}						
			|REGISTER{}						
;

type_specifier:
			VOID 	{curr_type = "VOID";}		
			|CHAR 	{curr_type = "CHAR";}	
			|SHORT 			
			|INT 	{curr_type = "INTEGER";}		
			|LONG 			
			|FLOAT 		{curr_type = "FLOAT";}	
			|DOUBLE 		
			|SIGNED 		
			|UNSIGNED 		
			|BOOL 			
			|COMPLEX
			|IMAGINARY
			|enum_specifier
;


specifier_qualifier_list:
			type_specifier specifier_qualifier_list{}
			|type_specifier	{}	
			|type_qualifier specifier_qualifier_list{}
			|type_qualifier {}
;


enum_specifier:
			ENUM '{' enumerator_list '}' 	{}
			|ENUM IDENTIFIER'{' enumerator_list '}'{} 
			|ENUM '{' enumerator_list ',' '}'	{}
			|ENUM IDENTIFIER '{' enumerator_list ',' '}'{}  
			|ENUM IDENTIFIER {}
;

enumerator_list:
			enumerator 		{}		
			|enumerator_list ',' enumerator{} 	

enumerator:
			IDENTIFIER {}				
			|IDENTIFIER ASSIGN constant_expression{} 
;

type_qualifier:
			CONST 	{}				
			|RESTRICT{}
			|VOLATILE {}			
;

function_specifier:
			INLINE 	{}			
;

declarator:
			pointer direct_declarator 
			{
				type *t = $1;
				while(t->p!=NULL) t = t->p;
				t->p = $2->tp;
				$$ =$2->update($1);
			}
			|direct_declarator
			{
				
			}
;


direct_declarator:
			IDENTIFIER 	
			{
				$$=$1->update(new type(curr_type));
				currentsymbol = $$;
			}				
			|'(' declarator ')' 
			{
				$$=$2;
			}		

			|direct_declarator '[' type_qualifier_list assignment_expression ']' 	 {}
			|direct_declarator '[' type_qualifier_list ']'{}
			|direct_declarator '['assignment_expression ']' 	 
			{
				type *t = $1->tp;
				type *prev = NULL;
				while(t->sym_type=="ARR")
				{
					prev = t;
					t = t->p;
				}
				if(prev==NULL)
				{
					int temp = atoi($3->loc->init_value.c_str());
					type* s = new type("ARR",$1->tp, temp);
					$$ = $1->update(s);
				}
				else 
				{
					prev->p =  new type("ARR", t, atoi($3->loc->init_value.c_str()));
					$$ = $1->update ($1->tp);
				}
			}
			 	
			|direct_declarator '[' STATIC type_qualifier_list assignment_expression']' {}

			|direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'{} 
			|direct_declarator '[' type_qualifier_list '*' ']' {}

			
			|direct_declarator '[' ']'	
			{
				type *t = $1->tp;
				type * prev = NULL;
				while (t->sym_type == "ARR")
				{
					prev = t;
					t = t->p;
				}
				if (prev==NULL)  //if the identifier is not declared as an array
				{
					type* s = new type("ARR", $1->tp, 0);
					$$ = $1->update(s);
				}
				else
				{
					prev->p=  new type("ARR", t, 0);
					$$ = $1->update($1->tp);
				}
			} 
				
			|direct_declarator '[' STATIC assignment_expression']'{} 
				 
				
			|direct_declarator '[' '*' ']' {}
			|direct_declarator '(' CT parameter_type_list ')' 
			{
				table->name = $1->name;
				if($1->tp->sym_type!="VOID")
				{
					sym_det *s = table->lookup("return");
					s->update($1->tp);
				}
				sym_det *s1 = glbl_table->lookup($1->name); //updating the type of identifier as function
				s1->update(new type("FUNC"));
				$1->nest_table=table;
				table->parent = glbl_table;
				changeTable (glbl_table);		// Come back 
				currentsymbol = $$;
			}	
			|direct_declarator '('identifier_list ')'{}
			|direct_declarator '(' CT ')'
			{
				table->name = $1->name;

				if ($1->tp->sym_type !="VOID") 
				{
					sym_det *s = table->lookup("return");
					s->update($1->tp);		
				}
				sym_det *s1 = glbl_table->lookup($1->name);  //updating the type of identifier as function
				s1->update(new type("FUNC"));
				$1->nest_table=table;   // Update function symbol table name
				table->parent = glbl_table;
				changeTable (glbl_table);				
				currentsymbol = $$;
			}  	 
;

CT:
			/*epsilon*/
			{ 														
				if (currentsymbol->nest_table==NULL)
				 changeTable(new sym_table(""));
				else 
				{
					changeTable (currentsymbol->nest_table);
					emit ("LABEL", table->name);
				}
			}
;


pointer:
			'*' type_qualifier_list{}
			|'*' 	
			{
				$$=new type("PTR");
			}	
			|'*' type_qualifier_list pointer {}
			|'*' pointer 
			{
				$$ = new type("PTR",$2);
			}
;


type_qualifier_list:
			type_qualifier 			{}		
			|type_qualifier_list type_qualifier {} 	
;

parameter_type_list:
			parameter_list 				{}	
			|parameter_list ',' ELLIPSE {}	

parameter_list:
			parameter_declaration 	{}		
			|parameter_list ',' parameter_declaration 	{}
;

parameter_declaration:
			declaration_specifiers declarator {}		
			|declaration_specifiers  	{}			
;



identifier_list:
			IDENTIFIER 				{}			
			|identifier_list ',' IDENTIFIER {}	
;

type_name:
 			specifier_qualifier_list 	{}		
;

initializer:
			assignment_expression 	
			{
				$$=$1->loc;
			}			
			|'{' initializer_list '}' 		{}	
			| '{' initializer_list ',' '}'		{}
;

initializer_list:
			initializer 	{}					
			|designation initializer 	{}		 
			|initializer_list ',' initializer    {}
			|initializer_list ',' designation initializer {}	
;

designation:
			designator_list ASSIGN 	{}	
;

designator_list:
			designator 			{}			
			|designator_list designator {}		
;

designator:
			'[' constant_expression ']' {}		 
			|'.' IDENTIFIER 	{}				
;

statement:
			labeled_statement 					
			|compound_statement	
			{
				$$=$1;
			}	
			|expression_statement	
			{
				$$ = new statement();
				$$->nextlist=$1->nextlist;
			}
			|selection_statement
			{
				$$=$1;
			} 	
			|iteration_statement
			{
				$$ = $1;
			} 	
			|jump_statement 
			{
				$$=$1;
			}		
;

labeled_statement:
			IDENTIFIER ':' statement 	
			{$$ = new statement();}
			|CASE constant_expression ':' statement 
			{$$ = new statement();}	
			|DEFAULT ':' statement 		
			{$$ = new statement();}
;

compound_statement:
			'{' block_item_list '}'	
			{
				$$=$2;
			}		 
			|'{' '}'
			{
				$$=new statement();
			}						 
;


block_item_list:
			block_item 
			{
				$$=$1;
			}
			|block_item_list M block_item 
			{
				$$=$3;
				backpatch($1->nextlist,$2);
			}
;

block_item:
			declaration
			{
				$$=new statement();
			} 	
			|statement 
			{
				$$=$1;
			}		
;

expression_statement: 					
			expression ';'
			{
				$$=$1;
			} 
			|';'	
			{
				$$=new expr();
			}		
;


selection_statement:
			IF '(' expression N ')' M statement N %prec THEN 	
			{
				backpatch($4->nextlist,nextinstr());
				convertInt2Bool($3);
				$$=new statement();
				backpatch($3->truelist,$6);
				list<int> temp = merge($3->falselist,$7->nextlist);
				$$->nextlist= merge($8->nextlist, temp);

			}	
			|IF '(' expression N ')' M statement N ELSE M statement {
				backpatch($4->nextlist,nextinstr());
				convertInt2Bool($3);
				$$=new statement();
				backpatch($3->truelist,$6);
				backpatch($3->falselist,$10);
				list<int> temp = merge($8->nextlist,$7->nextlist);
				$$->nextlist= merge($11->nextlist, temp);
			}
			|SWITCH '(' expression ')' statement 
			{

			}		
;

iteration_statement:
			WHILE M '(' expression ')' M statement 
			{
				$$=new statement();
				convertInt2Bool($4);
				backpatch($7->nextlist,$2);
				backpatch($4->truelist,$6);
				$$->nextlist = $4->falselist;
				stringstream strs;
	    		strs << $2;
	    		string temp_str = strs.str();
	    		char* intStr = (char*) temp_str.c_str();
				string str = string(intStr);
				emit ("GOTO", str);

			} 		 	
			|DO M statement M WHILE '(' expression ')' ';' 
			{
				$$=new statement();
				convertInt2Bool($7);
				backpatch($7->truelist,$2);
				backpatch($3->nextlist,$4);
				$$->nextlist = $7->falselist;
			}		
			|FOR '(' expression_statement M  expression_statement   ')' M statement	
			{
				$$ = new statement();
				convertInt2Bool($5);
				backpatch($5->truelist, $7);
				backpatch($8->nextlist, $4);
				stringstream strs;
	    		strs << $4;
	    		string temp_str = strs.str();
	    		char* intStr = (char*) temp_str.c_str();
				string str = string(intStr);

				emit ("GOTO", str);
				$$->nextlist = $5->falselist;
			}
			|FOR '(' expression_statement M  expression_statement M expression N   ')' M statement	
			{
				$$ = new statement();
				convertInt2Bool($5);
				backpatch($5->truelist,$10);
				backpatch($8->nextlist, $4);
				backpatch($11->nextlist, $6);
				stringstream strs;
	    		strs << $6;
	    		string temp_str = strs.str();
	    		char* intStr = (char*) temp_str.c_str();
				string str = string(intStr);
				emit ("GOTO", str);
				$$->nextlist = $5->falselist;
			}
			|FOR '(' declaration  expression_opt ';'  expression_opt ')' statement 
			{

			}			
;

jump_statement:
			GOTO IDENTIFIER ';' 
			{
				$$=new statement();
			}			
			|CONTINUE ';'
			{
				$$=new statement();
			}				
			|BREAK ';'
			{
				$$=new statement();
			} 					
			|RETURN expression ';' 
			{
				$$=new statement();
				emit("RETURN",$2->loc->name);
			}
			|RETURN ';' 
			{
				$$=new statement();
				emit("RETURN","");
			}	
;

expression_opt:
			expression
			{
				$$=$1;
			}
			|/*epsilon*/
			{

			}
;

translation_unit:
			external_declaration 		{}
			|translation_unit external_declaration {}
;

external_declaration:
			function_definition 	{}		
			|declaration 		{}		
;

function_definition:
			declaration_specifiers declarator declaration_list CT compound_statement 	
			{

			}
			|declaration_specifiers declarator CT compound_statement
			{
				table->parent=glbl_table;
				changeTable(glbl_table);
			} 		
;


declaration_list:
			declaration 	{}	
			|declaration_list declaration 	{}
;

%%

void yyerror (string s)  /* Called by yyparse on error */
{
  cout<<s<<endl;
}
