#ifndef TRANSLATE
#define TRANSLATE
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

// standard sizes of data types as in c
#define char_size			1
#define int_size 		    4
#define float_size		    8
#define pointer_size		4

extern  char* yytext;
extern int yyparse();

using namespace std;

class type;						// normal and derived datatypes of symbol
class quad;						// each entry produced during TAC
class quad_array;				// array of quads
class sym_det;					//symbol and its details
class sym_table; 				//table storing values of symbols in the given scope

extern sym_table* table;					// current symbol table where the flow is present
extern sym_table* glbl_table;				// symbol table used to store global variables
extern quad_array q;						// Array of Quads
extern sym_det* currentsymbol; 				//



class type
{ 
public:
	type(string t , type *p = NULL, int width = 1); //constructor
	string sym_type;							    //name of the type
	int width; 										//size of the symbol
	type *p; 										//nested types in case of arrays and pointers
};

class quad { 										//array for storing expressions
public:
	string op; 									    //operator
	string result; 								    
	string arg1;
	string arg2;

	quad(string result,string arg1,string op = "ASSIGN",string arg2 ="");
	quad(string result,int arg1,string op = "ASSIGN",string arg2 ="");
	quad(string result,float arg1,string op = "ASSIGN",string arg2 ="");
	void print();
};

class quad_array{
public:
	vector<quad> array; //list of quads
	void print(); 		//printing all the quads in the given array

};

class sym_det{
public:
	string name; 		//name of the symbol
	type *tp; 			//pointer to the details of the type of symbol
	string init_value;  //initial value of the symbol
	int size; 			//size of the symbol
	int offset; 		//offset of the symbol from the base pointer of scope
	sym_table* nest_table; //nested table if any in case of arrays
    
    //constructor of class
	sym_det(string name, string t = "INTEGER", type *p = NULL, int width = 0);
	//updates the types of symbols
	sym_det* update(type *t);
	//pointer to symbol table
	sym_det* ptr_sym_tab(sym_table *t);
};


class sym_table{
public:
	string name; 
	int count;
	list<sym_det> table; //list of symbols in the table
	sym_table *parent;   //pointer to parent of symbol table

	sym_table(string name="NULL"); //constructor
	sym_det* lookup(string name);  //looks into the symbol table if symbol found
	//else inserts it into the table
			
	void print(); //prints the symbol table
	void update();
};

struct statement{
	list<int> nextlist;//makes the list 
};

struct array{
	string cat; //
	sym_det* loc;// pointer to the location of base
	sym_det* array;// for multidimensional arrays
	type *tp; //type of array
};

struct expr{
	string tp; //type of expression
	sym_det* loc; //location of expression
	list<int> truelist; //stores the values of addresses to go when the expression is true
	list<int> falselist;//stores the values of addresses to go when the expression is false
	list<int> nextlist;//stores the values of addresses to go next
};

sym_det* conv(sym_det* , string); 							//converts a symbol to the type mentioned in the string
bool typecheck(sym_det* &s1, sym_det* &s2);                 //checks the type of the symbols
bool typecheck(type* t1, type* t2); 					    //compares the 2 types given

void backpatch (list<int> lst, int i);                      //inserts i as the target label for each of the statements on the list pointed to by lst.
list<int> makelist (int i);							        // creates a new list containing only i, an index into the array of quadruples and returns a pointer to the list it has made.
list<int> merge (list<int> &l1, list<int> &l2);             // concatenates the lists pointed to by l1 and l2, and returns a pointer to the concatenated list.

void emit(string op, string result, string arg1="", string arg2 = "");    //emits for adding quads to quadArray
void emit(string op, string result, int arg1, string arg2 = "");		  //emits for adding quads to quadArray (arg1 is int)
void emit(string op, string result, float arg1, string arg2 = "");

expr* convertInt2Bool (expr*);				// convert any expression (int) to bool
expr* convertBool2Int (expr*);              //converts boolean expression to integer

void changeTable (sym_table* newtable);           //for changing the current sybol table
int nextinstr();
sym_det* gentemp (type* t, string init = "");	// Generate a temporary variable and insert it in current symbol table
int size_type (type*);							// Calculate size of any symbol type 
string print_type(type*); 

#endif