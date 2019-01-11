
#include "ass6_16CS30026_translator.h"
#include <iostream>
#include <cstring>
#include <string>

extern FILE *yyin;
extern vector<string> allstrings;

using namespace std;

int labelCount=0;							// Label count in asm file
std::map<int, int> labelMap;				// map from quad number to label number
ofstream out;								// asm file stream
vector <quad> arr1;						// quad array
string asmfilename="ass6_16CS30026_";		// asm file name
string inputfile="ass6_16CS30026_test";	

void computeActivationRecord(sym_table *st)
{
	int param = -20;
	int local = -24;
	for (list <sym_det>::iterator it = st->table.begin(); it!=st->table.end(); it++) {
		if (it->ctg =="param") {
			st->AR[it->name] = param;
			param +=it->size;	
					
		}
		else if (it->name=="return") continue;
		else {
			st->AR[it->name] = local;
			local -=it->size;
			
		}
	}
}

void genasm() {
	arr1 = q.array;

	//To update the goto labels
	for (vector<quad>::iterator it = arr1.begin(); it!=arr1.end(); it++)
	{
		int i;
		if (it->op=="GOTO" || it->op=="LT" || it->op=="GT" || it->op=="LTE" || it->op=="GTE" || it->op=="EQ" || it->op=="NEQ") 
		{
			i = atoi(it->result.c_str());
			labelMap[i] = 1;
		}
	}
	// storing the labels of all quads 
	int count = 0;
	std::map<int,int>::iterator it;
	for (it=labelMap.begin(); it!=labelMap.end(); ++it)
	{
		it->second = count++;
	}

	// creating a list of all tables in tablelist
	list<sym_table*> tablelist;
	list <sym_det>::iterator it2;
	for (it2  = glbl_table->table.begin(); it2!=glbl_table->table.end(); it2++)
	{
		if (it2->nest_table!=NULL) 
		{
			tablelist.push_back (it2->nest_table);
		}
	}

	// computing activation record of all tables
	list<sym_table*>::iterator it1;
	for (it1 = tablelist.begin();it1 != tablelist.end(); ++it1)
	{
		computeActivationRecord(*it1);
	}

	//asmfile
	ofstream asmfile;
	asmfile.open(asmfilename.c_str());

	asmfile << "\t.file	\"test.c\"\n";
	for (list <sym_det>::iterator it = table->table.begin(); it!=table->table.end(); it++)
	{
		if (it->ctg!="function")
		{
			if (it->tp->sym_type=="CHAR")
			{ // Global char
				if (it->init_value!="")
			    {
					asmfile << "\t.globl\t" << it->name << "\n";
					asmfile << "\t.type\t" << it->name << ", @object\n";
					asmfile << "\t.size\t" << it->name << ", 1\n";
					asmfile << it->name <<":\n";
					asmfile << "\t.byte\t" << atoi( it->init_value.c_str()) << "\n";
				}
				else
				{
					asmfile << "\t.comm\t" << it->name << ",1,1\n";
				}
			}
			if (it->tp->sym_type=="INTEGER") 
			{ // Global int
				if (it->init_value!="") 
				{
					asmfile << "\t.globl\t" << it->name << "\n";
					asmfile << "\t.data\n";
					asmfile << "\t.align 4\n";
					asmfile << "\t.type\t" << it->name << ", @object\n";
					asmfile << "\t.size\t" << it->name << ", 4\n";
					asmfile << it->name <<":\n";
					asmfile << "\t.long\t" << it->init_value << "\n";
				}
				else 
				{
					asmfile << "\t.comm\t" << it->name << ",4,4\n";
				}
			}
		}
	}
	if (allstrings.size()) {
		asmfile << "\t.section\t.rodata\n";
		for (vector<string>::iterator it = allstrings.begin(); it!=allstrings.end(); it++)
		{
			asmfile << ".LC" << it - allstrings.begin() << ":\n";
			asmfile << "\t.string\t" << *it << "\n";	
		}	
	}
	asmfile << "\t.text	\n";

	vector<string> params;
	std::map<string, int> theMap;
	for (vector<quad>::iterator it = arr1.begin(); it!=arr1.end(); it++) {
		if (labelMap.count(it - arr1.begin())) {
			asmfile << ".L" << (2*labelCount+labelMap.at(it - arr1.begin()) + 2 )<< ": " << endl;
		}

		string op = it->op;
		string result = it->result;
		string arg1 = it->arg1;
		string arg2 = it->arg2;
		string s=arg2;

		if(op=="PARAM"){
			params.push_back(result);
		}
		else {
			asmfile << "\t";
			// Binary Operations
			if (op=="ADD") {
				bool flag=true;
				if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) flag=false ;
				else{
					char * p ;
					strtol(s.c_str(), &p, 10) ;
					if(*p == 0) flag=true ;
					else flag=false;
				}
				if (flag) {
					asmfile << "addl \t$" << atoi(arg2.c_str()) << ", " << table->AR[arg1] << "(%rbp)";
				}
				else {
					asmfile << "movl \t" << table->AR[arg1] << "(%rbp), " << "%eax" << endl;
					asmfile << "\tmovl \t" << table->AR[arg2] << "(%rbp), " << "%edx" << endl;
					asmfile << "\taddl \t%edx, %eax\n";
					asmfile << "\tmovl \t%eax, " << table->AR[result] << "(%rbp)";
				}
			}
			else if (op=="SUB") {
				asmfile << "movl \t" << table->AR[arg1] << "(%rbp), " << "%eax" << endl;
				asmfile << "\tmovl \t" << table->AR[arg2] << "(%rbp), " << "%edx" << endl;
				asmfile << "\tsubl \t%edx, %eax\n";
				asmfile << "\tmovl \t%eax, " << table->AR[result] << "(%rbp)";
			}
			else if (op=="MULT") {
				asmfile << "movl \t" << table->AR[arg1] << "(%rbp), " << "%eax" << endl;
				bool flag=true;
				if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) flag=false ;
				else{
					char * p ;
					strtol(s.c_str(), &p, 10) ;
					if(*p == 0) flag=true ;
					else flag=false;
				}
				if (flag) {
					asmfile << "\timull \t$" << atoi(arg2.c_str()) << ", " << "%eax" << endl;
					sym_table* t = table;
					string val;
					for (list <sym_det>::iterator it = t->table.begin(); it!=t->table.end(); it++) {
						if(it->name==arg1) val=it->init_value; 
					}
					theMap[result]=atoi(arg2.c_str())*atoi(val.c_str());
				}
				else asmfile << "\timull \t" << table->AR[arg2] << "(%rbp), " << "%eax" << endl;
				asmfile << "\tmovl \t%eax, " << table->AR[result] << "(%rbp)";			
			}
			else if(op=="DIV") {
				asmfile << "movl \t" << table->AR[arg1] << "(%rbp), " << "%eax" << endl;
				asmfile << "\tcltd" << endl;
				asmfile << "\tidivl \t" << table->AR[arg2] << "(%rbp)" << endl;
				asmfile << "\tmovl \t%eax, " << table->AR[result] << "(%rbp)";		
			}

			// Bit Operators /* Ignored */
			else if (op=="MOD")	{
				asmfile << "movl \t" << table->AR[arg1] << "(%rbp), " << "%eax" << endl;
				asmfile << "\tcltd" << endl;
				asmfile << "\tidivl \t" << table->AR[arg2] << "(%rbp)" << endl;
				asmfile << "\tmovl \t%edx, " << table->AR[result] << "(%rbp)";	

				 }
				 // asmfile << result << " = " << arg1 << " % " << arg2;
			else if (op=="XOR")			asmfile << result << " = " << arg1 << " ^ " << arg2;
			else if (op=="BIT_OR")		asmfile << result << " = " << arg1 << " | " << arg2;
			else if (op=="BIT_AND")		asmfile << result << " = " << arg1 << " & " << arg2;
			// Shift Operations /* Ignored */
			else if (op=="LEFT_SHIFT")		asmfile << result << " = " << arg1 << " << " << arg2;
			else if (op=="RIGHT_SHIFT")		asmfile << result << " = " << arg1 << " >> " << arg2;

			else if (op=="ASSIGN")	{
				s=arg1;
				bool flag=true;
				if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) flag=false ;
				else{
					char * p ;
					strtol(s.c_str(), &p, 10) ;
					if(*p == 0) flag=true ;
					else flag=false;
				}
				if (flag) 
					asmfile << "movl\t$" << atoi(arg1.c_str()) << ", " << "%eax" << endl;
				else
					asmfile << "movl\t" << table->AR[arg1] << "(%rbp), " << "%eax" << endl;
				asmfile << "\tmovl \t%eax, " << table->AR[result] << "(%rbp)";
			}			
/*what is this*/else if (op=="EQUALSTR")	{
				asmfile << "movq \t$.LC" << arg1 << ", " << table->AR[result] << "(%rbp)";
			}
/*what is this*/else if (op=="EQUALCHAR")	{
				asmfile << "movb\t$" << atoi(arg1.c_str()) << ", " << table->AR[result] << "(%rbp)";
			}					
			// Relational Operations
			else if (op=="EQ") {
				asmfile << "movl\t" << table->AR[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->AR[arg2] << "(%rbp), %eax\n";
				asmfile << "\tje .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="NEQ") {
				asmfile << "movl\t" << table->AR[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->AR[arg2] << "(%rbp), %eax\n";
				asmfile << "\tjne .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="LT") {
				asmfile << "movl\t" << table->AR[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->AR[arg2] << "(%rbp), %eax\n";
				asmfile << "\tjl .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="GT") {
				asmfile << "movl\t" << table->AR[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->AR[arg2] << "(%rbp), %eax\n";
				asmfile << "\tjg .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="GTE") {
				asmfile << "movl\t" << table->AR[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->AR[arg2] << "(%rbp), %eax\n";
				asmfile << "\tjge .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="LTE") {
				asmfile << "movl\t" << table->AR[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->AR[arg2] << "(%rbp), %eax\n";
				asmfile << "\tjle .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="GOTO") {
				asmfile << "jmp .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			// Unary Operators
			else if (op=="ADDRESS") {
				asmfile << "leaq\t" << table->AR[arg1] << "(%rbp), %rax\n";
				asmfile << "\tmovq \t%rax, " <<  table->AR[result] << "(%rbp)";
			}
			else if (op=="ASSIGN_PTR") {
				asmfile << "movq\t" << table->AR[arg1] << "(%rbp), %rax\n";
				asmfile << "\tmovl\t(%rax),%eax\n";
				asmfile << "\tmovl \t%eax, " <<  table->AR[result] << "(%rbp)";	
			}
			else if (op=="PTR_ASSIGN") {
				asmfile << "movq\t" << table->AR[result] << "(%rbp), %rax\n";
				asmfile << "\tmovl\t" << table->AR[arg1] << "(%rbp), %edx\n";
				asmfile << "\tmovl    %edx, (%rax)";
			} 			
			else if (op=="U_MINUS") {
				asmfile << "negl\t" << table->AR[arg1] << "(%rbp)";
			}
			else if (op=="BIT_NOT")		asmfile << result 	<< " = ~" << arg1;
			else if (op=="NOT")			asmfile << result 	<< " = !" << arg1;
			else if (op=="ARR_RT") {
				int off=0;
				off=theMap[arg2]*(-1)+table->AR[arg1];
//				asmfile << "movq\t" << table->AR[arg2] << "(%rbp), "<<"%rax" << endl;
				asmfile << "movq\t" << off << "(%rbp), "<<"%rax" << endl;
				asmfile << "\tmovq \t%rax, " <<  table->AR[result] << "(%rbp)";
			}	 			
			else if (op=="ARR_LT") {
				int off=0;
				off=theMap[arg1]*(-1)+table->AR[result];
//				asmfile << "movq\t" << table->AR[arg1] << "(%rbp), "<<"%rax" << endl;
				asmfile << "movq\t" << table->AR[arg2] << "(%rbp), "<<"%rdx" << endl;
				asmfile << "\tmovq\t" << "%rdx, " << off << "(%rbp)";
			}	 
			else if (op=="RETURN") {
				if(result!="") asmfile << "movl\t" << table->AR[result] << "(%rbp), "<<"%eax";
				else asmfile << "nop";
				// cout <<"\tleave\n\tret"<<endl;
			}
			else if (op=="PARAM") {
				params.push_back(result);
			}
			else if (op=="CALL") {
				// Function Table
				sym_table* t = glbl_table->lookup(arg1)->nest_table;
				int i,j=0;	// index
				for (list <sym_det>::iterator it = t->table.begin(); it!=t->table.end(); it++) {
					i = distance ( t->table.begin(), it);
					if (it->ctg== "param") {
						if(j==0) {
							asmfile << "movl \t" << table->AR[params[i]] << "(%rbp), " << "%eax" << endl;
							asmfile << "\tmovq \t" << table->AR[params[i]] << "(%rbp), " << "%rdi" << endl;
							//asmfile << "\tmovl \t%eax, " << (t->AR[it->name]-8 )<< "(%rsp)\n\t";
							j++;
						}
						else if(j==1) {
							asmfile << "movl \t" << table->AR[params[i]] << "(%rbp), " << "%eax" << endl;
							asmfile << "\tmovq \t" << table->AR[params[i]] << "(%rbp), " << "%rsi" << endl;
							//asmfile << "\tmovl \t%eax, " << (t->AR[it->name]-8 )<< "(%rsp)\n\t";
							j++;
						}
						else if(j==2) {
							asmfile << "movl \t" << table->AR[params[i]] << "(%rbp), " << "%eax" << endl;
							asmfile << "\tmovq \t" << table->AR[params[i]] << "(%rbp), " << "%rdx" << endl;
							//asmfile << "\tmovl \t%eax, " << (t->AR[it->name]-8 )<< "(%rsp)\n\t";
							j++;
						}
						else if(j==3) {
							asmfile << "movl \t" << table->AR[params[i]] << "(%rbp), " << "%eax" << endl;
							asmfile << "\tmovq \t" << table->AR[params[i]] << "(%rbp), " << "%rcx" << endl;
							//asmfile << "\tmovl \t%eax, " << (t->AR[it->name]-8 )<< "(%rsp)\n\t";
							j++;
						}
						else {
							asmfile << "\tmovq \t" << table->AR[params[i]] << "(%rbp), " << "%rdi" << endl;							
						}
					}
					else break;
				}
				params.clear();
				asmfile << "\tcall\t"<< arg1 << endl;
				asmfile << "\tmovl\t%eax, " << table->AR[result] << "(%rbp)";
			}
			else if (op=="FUNC") {
				asmfile <<".globl\t" << result << "\n";
				asmfile << "\t.type\t"	<< result << ", @function\n";
				asmfile << result << ": \n";
				asmfile << ".LFB" << labelCount <<":" << endl;
				asmfile << "\t.cfi_startproc" << endl;
				asmfile << "\tpushq \t%rbp" << endl;
				asmfile << "\t.cfi_def_cfa_offset 8" << endl;
				asmfile << "\t.cfi_offset 5, -8" << endl;
				asmfile << "\tmovq \t%rsp, %rbp" << endl;
				asmfile << "\t.cfi_def_cfa_register 5" << endl;
				table = glbl_table->lookup(result)->nest_table;
				asmfile << "\tsubq\t$" << table->table.back().offset+24 << ", %rsp"<<endl;
				
				// Function Table
				sym_table* t = table;
				int i=0;
				for (list <sym_det>::iterator it = t->table.begin(); it!=t->table.end(); it++) {
					if (it->ctg== "param") {
						if (i==0) {
							asmfile << "\tmovq\t%rdi, " << table->AR[it->name] << "(%rbp)";
							i++;
						}
						else if(i==1) {
							asmfile << "\n\tmovq\t%rsi, " << table->AR[it->name] << "(%rbp)";
							i++;
						}
						else if (i==2) {
							asmfile << "\n\tmovq\t%rdx, " << table->AR[it->name] << "(%rbp)";
							i++;
						}
						else if(i==3) {
							asmfile << "\n\tmovq\t%rcx, " << table->AR[it->name] << "(%rbp)";
							i++;
						}
					}
					else break;
				}
			}		
			else if (op=="FUNCEND") {
				asmfile << "leave\n";
				asmfile << "\t.cfi_restore 5\n";
				asmfile << "\t.cfi_def_cfa 4, 4\n";
				asmfile << "\tret\n";
				asmfile << "\t.cfi_endproc" << endl;
				asmfile << ".LFE" << labelCount++ <<":" << endl;
				asmfile << "\t.size\t"<< result << ", .-" << result;
			}
			else asmfile << "op";
			asmfile << endl;
		}
	}
	asmfile << 	"\t.ident\t	\"Compiled by 16CS30026\"\n";
	asmfile << 	"\t.section\t.note.GNU-stack,\"\",@progbits\n";
	asmfile.close();
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	copy(v.begin(), v.end(), ostream_iterator<T>(os, " ")); 
	return os;
}

int main(int ac, char* av[]) {
	inputfile=inputfile+string(av[ac-1])+string(".c");
	asmfilename=asmfilename+string(av[ac-1])+string(".s");
	 glbl_table = new sym_table("Global");
	table =  glbl_table;
	
yyin = fopen(inputfile.c_str(),"r"); 
	yyparse();
	 glbl_table->update();
	 glbl_table->print();
	q.print();
	genasm();
}