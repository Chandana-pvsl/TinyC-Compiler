#include "ass5_16cs30026_translator.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

sym_table *glbl_table;
quad_array q;
string curr_type;
sym_table *table;
sym_det *currentsymbol;

map<string,int> sym_types;

//function to map data types to integers
void intialize()
{
	sym_types["VOID"] = 0;
	sym_types["INTEGER"] = 1;
	sym_types["FLOAT"] = 2;
	sym_types["CHAR"] = 3;
	sym_types["FUNC"] = 4;
	sym_types["PTR"] = 5;
	sym_types["ARR"] = 6;
}

type::type(string t , type *ptr , int w )  
{
	this->sym_type=t;
	this->p=ptr;
	this->width=w;
}

//overloading the quad constructor for different types of tac

quad::quad(string result, string arg1, string op, string arg2):
	op(op),result(result),arg1(arg1),arg2(arg2){};

quad::quad(string result, int arg1, string op, string arg2): 
op(op),result(result),arg2(arg2)
{
	this->arg1 = to_string(arg1);
}

quad::quad(string result, float arg1, string op, string arg2):
op(op),result(result),arg2(arg2){
	this->arg1 = to_string(arg1);
}

void quad::print () { //printing quads based on operator
	// Binary Operations
		map<string,int> value;
		value["ADD"] = 0;
		value["SUB"] = 1;
		value["MULT"] = 2;
		value["DIV"] = 3;
		value["MOD"] = 4;
		value["XOR"] = 5;
		value["BIT_OR"] = 6;
		value["BIT_AND"] = 7;
		value["AND"] = 8;
		value["OR"] = 9;
		value["LEFT_SHIFT"] = 10;
		value["RIGHT_SHIFT"] = 11;
		value["ASSIGN"] = 12;
		value["EQ"] = 13;
		value["NEQ"] = 14;
		value["LT"] = 15;
		value["GT"] = 16;
		value["GTE"] = 17;
		value["LTE"] = 18;
		value["GOTO"] = 19;
		value["ADDRESS"] = 20;
		value["ASSIGN_PTR"] = 21;
		value["PTR_ASSIGN"] = 22;
		value["U_MINUS"] = 23;
		value["BIT_NOT"] = 24;
		value["NOT"] = 25;
		value["ARR_RT"]= 26;
		value["ARR_LT"] = 27;
		value["RETURN"] = 28;
		value["PARAM"] = 29;
		value["CALL"] = 30;
		value["LABEL"] = 31;
		switch(value[op])
		{
			case 0:
		 		cout << result << " = " << arg1 << " + " << arg2;
				break;
			case 1:				
            	cout << result << " = " << arg1 << " - " << arg2;
				break;					
			case 2:				
            	cout << result << " = " << arg1 << " * " << arg2;
				break;					
			case 3:					
            	cout << result << " = " << arg1 << " / " << arg2;
				break;					
			case 4:					
            	cout << result << " = " << arg1 << " %" << arg2;
				break;					
			case 5:				
            	cout << result << " = " << arg1 << " ^ " << arg2;
				break;					
			case 6:				
            	cout << result << " = " << arg1 << " | " << arg2;
				break;					
			case 7:				
            	cout << result << " = " << arg1 << " & " << arg2;
				break;					
			case 8:				
            	cout << result << " = " << arg1 << " && " << arg2;
				break;				
			case 9:					
            	cout << result << " = " << arg1 << " || " << arg2;
				break;					
		// Shift Operations
            	
			case 10:				
            	cout << result << " = " << arg1 << " << " << arg2;
				break;					
			case 11:				
            	cout << result << " = " << arg1 << " >> " << arg2;
				break;					
			case 12:			
            	cout << result << " = " << arg1 ;				
				break;					
		// Relational Operations

			case 13:					
            	cout << "if " << arg1 <<  " == " << arg2 << " goto L" << result;
				break;		
			case 14:					
            	cout << "if " << arg1 <<  " != " << arg2 << " goto L" << result;
				break;		
			case 15:					
            	cout << "if " << arg1 <<  " < "  << arg2 << " goto L" << result;
				break;			
			case 16:					
            	cout << "if " << arg1 <<  " > "  << arg2 << " goto L" << result;
				break;

			case 17:					
            	cout << "if " << arg1 <<  " >= " << arg2 << " goto L" << result;
				break;			
			case 18:					
            	cout << "if " << arg1 <<  " <= " << arg2 << " goto L" << result;
				break;

			case 19:				
            	cout << "goto L" << result;		
				break;

		//Unary Operators

			case 20:		
            	cout << result << " = &" << arg1;
				break;

			case 21:				
            	cout << result	<< " = *" << arg1 ;
				break;

			case 22:			
            	cout << "*" << result	<< " = " << arg1 ;
				break;

			case 23:			
            	cout << result 	<< " = -" << arg1;
				break;

			case 24:			
            	cout << result 	<< " = ~" << arg1;
				break;

			case 25:		
            	cout << result 	<< " = !" << arg1;
				break;

			case 26:		
            	cout << result << " = " << arg1 << "[" << arg2 << "]";
				break;

			case 27:			
            	cout << result << "[" << arg1 << "]" <<" = " <<  arg2;
				break;

			case 28:			
            	cout << "retVal " << result;
				break;

			case 29:				
            	cout << "param " << result;
				break;

			case 30:				
            	cout << result << " = " << "call " << arg1<< ", " << arg2;
				break;
			case 31:				
            	cout <<  result << ": ";	
            	break;
			default:
				cout << "op";
				break;	
		}	
		cout << endl;	
}

void quad_array::print()
{
    cout << setw(30) << setfill ('*') << "*"<< endl;
    cout << "Quad Translation" << endl;
    cout << setw(30) << setfill ('-') << "-"<< setfill (' ') << endl;
	vector<quad>::iterator it; //iterates over array of quads
	for(it = array.begin();it!=array.end();it++)
	{
		if(it->op!="LABEL") //if operator in quad is not label then print address and then tac
		{
			cout<<"\tL"<<setw(4)<<it-array.begin()<<":\t";
			it->print();
			cout<<"\n";
		}	
		else 			//else just print the quad
		{
			it->print();
			cout<<"\n";
		}
	}
    cout << setw(30) << setfill ('-') << "-"<< endl;
}


//emitting instructions to the program being built
//a new quad is created everytime and is pushed into the current quad_array the control is at
void emit(string op, string result, string arg1, string arg2) 
{
	q.array.push_back(*(new quad(result,arg1,op,arg2)));
}
void emit(string op, string result, int arg1, string arg2) 
{
	q.array.push_back(*(new quad(result,arg1,op,arg2)));
}
void emit(string op, string result, float arg1, string arg2) 
{
	q.array.push_back(*(new quad(result,arg1,op,arg2)));
}


//constructor for sym_det
sym_det::sym_det(string name, string t , type *p , int width )
:name(name){
	tp = new type(t,p,width);   //stores the details of the type of symbol

	//values are updated later
	nest_table=NULL;
	init_value = "null";
	offset = 0;
	
	size = size_type(tp);
}

sym_det* sym_det::update(type* t)//updates the size of type in case of double pointers or multi dimensional arrays
{
	tp = t;
	this->size = size_type(t);
	return this;
}


sym_table::sym_table(string name):
name(name),count(0){};

//looks for the symbol in the given symbol table and if found return it else creates a new entry in the table
sym_det* sym_table::lookup(string name)
{
	sym_det* s;
	list<sym_det>::iterator it;
	for(it=table.begin();it!=table.end();it++)
	{
		if(it->name==name)
		{
			break;
		}
	}
	if(it!=table.end())
	{
		return &*it;
	}
	else
	{
		s = new sym_det(name);
		table.push_back(*s);
		return &table.back();
	}
}

//update different fields of an existing entry 
void sym_table::update()
{
	list<sym_table*> tbl_lst;
	int ofst;
	list<sym_det>::iterator it;
	for(it = table.begin();it!=table.end();it++)
	{
		//if beginning sets offset to 0
		if(it==table.begin())
		{
			it->offset = 0;
			ofst = it->size;
		}
		//updates the offset to cummulative offset
		else
		{
			it->offset = ofst;
			ofst = it->offset + it->size;
		}
		if(it->nest_table!=NULL)
		{
			tbl_lst.push_back(it->nest_table);
		}
	}
	list<sym_table*>::iterator it1;
	for(it1 = tbl_lst.begin();it1!=tbl_lst.end();it1++)
	{
		(*it1)->update();
	}
}

//prints the symbol table and its corresponding nested tables 
void sym_table::print()
{
	list<sym_table*> tbl_lst;
	cout << setw(115) << setfill ('*') << "*"<< endl;
	cout << "Symbol Table: " << setfill (' ') << left << setw(50)  << this->name ;

	cout << right << setw(25) << "Parent: ";
	if (this->parent!=NULL)
		cout << this->parent->name;
	else cout << "NULL" ;

	cout << endl;
	cout << setw(115) << setfill ('-') << "-"<< endl;
	cout << setfill (' ') << left << setw(20) << "Name";
	cout << left << setw(25) << "Type of symbol";
	cout << left << setw(30) << "Initial Value";
	cout << left << setw(12) << "Size";
	cout << left << setw(12) << "Offset";
	cout << left << "Nested table" << endl;
	cout << setw(115) << setfill ('-') << "-"<< setfill (' ') << endl;

	list <sym_det>::iterator it;
	for ( it = table.begin(); it!=table.end(); it++) 
	{
		cout << left << setw(20) << it->name;
		string stype = print_type(it->tp);
		cout << left << setw(25) << stype;
		cout << left << setw(30) << it->init_value;
		cout << left << setw(12) << it->size;
		cout << left << setw(11) << it->offset;
		cout << left;
		if (it->nest_table == NULL) 
		{
			cout << "null" <<  endl;	
		}
		else
		{
			cout << it->nest_table->name <<  endl;
			tbl_lst.push_back (it->nest_table);
		}
	}
	cout << setw(115) << setfill ('-') << "-"<< setfill (' ') << endl;
	cout << endl;
	for (list<sym_table*>::iterator it1 = tbl_lst.begin();it1 != tbl_lst.end();++it1) 
	{
	    	(*it1)->print();
	} 

}

//inputs: are type pointer and the initial value of symbol in string format
//algorithm: generate a new temporary, insert
// it to the Symbol Table
//output: return a pointer to the entry
sym_det* gentemp (type* t, string init)
{
	char n[10];
	sprintf(n,"t%02d",table->count++);
	sym_det* s = new sym_det(n);
	s->tp = t;
	s->size = size_type(t);
	s->init_value = init;
	table->table.push_back(*s);
	return &table->table.back();
}

// input pointer to a symbol and type to which it is being converted into
//algorithm: convert an expression E from its current
// type type1 to target type type2, to adjust the attributes of E
// accordingly.
// output: returns the pointer to symbol
sym_det* conv(sym_det *s , string t)
{
	intialize();
	sym_det* temp = gentemp(new type(t));
	switch(sym_types[s->tp->sym_type])
	{
		case 1: 
			switch(sym_types[t])
			{
				case 2:
					emit("ASSIGN",temp->name,"int2float("+s->name+")");
					return temp;
				case 3:
					emit("ASSIGN",temp->name,"int2char("+s->name+")");
					return temp;
				default:
					return s;
			}
			break;
		case 2:
			switch(sym_types[t])
			{
				case 1:
					emit("ASSIGN",temp->name,"float2int("+s->name+")");
					return temp;
				case 3:
					emit("ASSIGN",temp->name,"float2char("+s->name+")");
					return temp;
				default:
					return s;
			}
			break;	
		case 3:
			switch(sym_types[t])
			{
				case 1:
					emit("ASSIGN",temp->name,"char2int("+s->name+")");
					return temp;
				case 3:
					emit("ASSIGN",temp->name,"char2float("+s->name+")");
					return temp;
				default:
					return s;
			}
			break;
		default:
			return s;
	}
}


//two symbols are given as input whose type is checked and if the type is not same then
//a global function to check the types of symbols
//converted to respective type using conv function
// outputs true if t1 == t2 or one type can be converted to other
bool typecheck(sym_det* &s1, sym_det* &s2)
{
	type* t1 = s1->tp;
	type* t2 = s2->tp;
	if(typecheck(t1,t2))
	{
		return true;
	}
	else if(s1 = conv(s1, t2->sym_type))
	{
		return true;
	}
	else if(s2 = conv(s2, t1->sym_type))
	{
		return true;
	}
	else return false;
}


// bool typecheck(sym_det* &s1, sym_det* &s2)
// {
// 	type* t1 = s1->tp;
// 	type* t2 = s2->tp;
// 	if(typecheck(t1,t2))
// 	{
// 		return true;
// 	}
// 	else if(size_type(t1)>size_type(t2))
// 	{
// 		s2 = conv(s2,t1->sym_type);
// 		return true;
// 	}
// 	else if(size_type(t1)<size_type(t2))
// 	{
// 		s1 = conv(s1, t2->sym_type);
// 		return true;
// 	}
// 	else return false;
// }

//A global function to insert i as the target label for each of the
// quad’s on the list pointed to by lst.
void backpatch (list<int> lst, int i)
{
	string s = to_string(i);
	for(list<int>::iterator it = lst.begin();it!=lst.end();it++)
	{
		q.array[*it].result = s;
	}
}


//overloaded function to compare two types returns false if either of them 
//do not have any type 
bool typecheck(type* t1, type* t2)
{
	if(t1!=NULL || t2!=NULL)
	{
		if(t1==NULL)
			return false;
		if(t2==NULL)
			return false;
		if(t1->sym_type==t2->sym_type) //if the types are same checks if the concatenated types have same type
			return typecheck(t1->p,t2->p);
		else return false;
	}
	return true;
}

// input index of the instruction
//creates a new list containing only i, an index into the array of quad’s,
// output: return a pointer to the newly created list.
list<int> makelist (int i)
{
	list<int> l(1,i);
	return l;
}					        

// algorithm: concatenate two lists pointed to by l1 and l2
//output: return a pointer to the concatenated list
list<int> merge (list<int> &l1, list<int> &l2)
{
	l1.merge(l2);
	return l1;
}

// input: pointer to the expression to be converted to bool
// algorithm:  converts an integer expression to boolean based on values
expr* convertInt2Bool (expr* e)
{
	if( e->tp!= "BOOL")
	{
		// e->tp = new type("BOOL");
		e->falselist=makelist(nextinstr());
		emit("EQ","",e->loc->name, "0");
		e->truelist = makelist(nextinstr());
		emit("GOTO","");
	}
}	

//converting boolean expression to integer expression
//assigns variable names true and false based on their boolean values 
expr* convertBool2Int (expr* e)
{
	int t;
	if (e->tp=="BOOL")
	 {

		e->loc = gentemp(new type("INTEGER"),"null");
		backpatch (e->truelist, nextinstr());
		emit ("ASSIGN", e->loc->name, "1");
		t = nextinstr()+2;
		string str = to_string(t);
		emit ("GOTO", str);
		backpatch (e->falselist, nextinstr());
		emit ("ASSIGN", e->loc->name, "0");
	}
} 

// change table from current table to new table
void changeTable (sym_table* newtable)
{
	table = newtable;
}  

//returns the index of next instruction from the scope of control 
int nextinstr()
{
	return q.array.size();
}

// input pointer to type t
// output: returns the size of type given as input
// algorithm: for arrays  and pointers it recursively calculates their sizes
int size_type (type* t)
{
	intialize();
	switch(sym_types[t->sym_type])
	{
		case 0:
			return 0;
		case 1:
			return int_size;
		case 2:
			return float_size;
		case 3:
			return char_size;
		case 4:
			return 0;
		case 5:
			return pointer_size;
		case 6:
			return t->width*size_type(t->p);
		default:
			return 0;
	}
}	

string type_name(int a)
{
	if(a==0)
	{
		return "void";
	}
	else if(a==1)
	{
		return "integer";
	}
	else if(a==2)
	{
		return "float";
	}
	else if(a==3)
	{
		return "character";
	}
	else if(a==4)
	{
		return "function";
	}
	return "_";
}						

//input pointer to type t
//ouput and algorithm: prints the type of symbols
string print_type(type* t)
{
	intialize();
	if(t==NULL)
	{
		return "NULL";
	}
	else
	{
		switch(sym_types[t->sym_type])
		{
			case 0:
				return type_name(0);
			case 1:
				return type_name(1);
			case 2:
				return type_name(2);
			case 3:
				return type_name(3);
			case 4:
				return type_name(4);
			case 5:
				return "pointer("+print_type(t->p)+")" ;
			case 6:
				return "arr("+to_string(t->width)+","+print_type(t->p)+")" ;
			default:
				return type_name(5);
		}
	}
}

int  main (int argc, char* argv[]){
    glbl_table = new sym_table("Global");
    table = glbl_table;
    yyparse();
    glbl_table->update();
    glbl_table->print();
    q.print();
    cout.flush();
};
