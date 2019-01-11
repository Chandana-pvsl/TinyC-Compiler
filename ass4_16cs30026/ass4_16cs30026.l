%{
	#include "assgn4.tab.h"
	
%}




Multi-line-Comment	[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]
Single-line-Comment	[/][/][^\n]*[\n]
comment 			{Multi-line-Comment}|{Single-line-Comment}
punctuator			"["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|"#"|","
keyword 			"auto"|"enum"|"restrict"|"unsigned"|"break"|"extern"|"return"|"void"|"case"|"float"|"short"|"volatile"|"char"|"for"|"signed"|"while"|"const"|"goto"|"sizeof"|"_Bool"|"continue"|"if"|"static"|"_Complex"|"default"|"inline"|"struct"|"_Imaginary"|"do"|"int"|"switch"|"double"|"long"|"typedef"|"else"|"register"|"union"

digit 				[0-9]
identifier-nondigit [A-Za-z]|"_"
identifier   		{identifier-nondigit}({identifier-nondigit}|{digit})*

escape-sequence         "\'"|"\""|"\?"|"\\"|"\a"|"\b"|"\f"|"\n"|"\r"|"\t"|"\v"
c-char                  [^("\'"|"\\"|"\n")]|{escape-sequence}
c-char-sequence         {c-char}+
character-constant	 "\'"{c-char-sequence}"\'"


nonzero-digit 		[1-9]
sign 				[+-]
digit-sequence		{digit}+
enumeration-constant {identifier}
fractional-constant	({digit-sequence}?"."{digit-sequence})|({digit-sequence}".")|[0]*"."[0]+
exponent-part 		([eE]{sign}?{digit-sequence})
integer-constant 	{nonzero-digit}({digit})*|[0]+
floating-constant 	({fractional-constant}{exponent-part}?)|({integer-constant}{exponent-part})
constant 			{integer-constant}|{floating-constant}|{enumeration-constant}|{character-constant}


s-char 				[^("\"""\\""\n")]|{escape-sequence}
s-char-sequence		{s-char}+
string-literal		("\""{s-char-sequence}?"\"")
whitespace		[\t\n]




%%





{keyword}		{
	if(strcmp(yytext,"auto") == 0) 		return AUTO;
	if(strcmp(yytext,"break") == 0) 	return BREAK;
	if(strcmp(yytext,"case") == 0) 		return CASE;
	if(strcmp(yytext,"char") == 0) 		return CHAR;
	if(strcmp(yytext,"const") == 0) 	return CONST;
	if(strcmp(yytext,"continue") == 0) 	return CONTINUE;
	if(strcmp(yytext,"default") == 0) 	return DEFAULT;
	if(strcmp(yytext,"do") == 0) 		return DO;
	if(strcmp(yytext,"double") == 0) 	return DOUBLE;
	if(strcmp(yytext,"else") == 0) 		return ELSE;
	if(strcmp(yytext,"enum") == 0) 		return ENUM;
	if(strcmp(yytext,"extern") == 0) 	return EXTERN;
	if(strcmp(yytext,"float") == 0) 	return FLOAT;
	if(strcmp(yytext,"for") == 0) 		return FOR;
	if(strcmp(yytext,"goto") == 0) 		return GOTO;
	if(strcmp(yytext,"if") == 0) 		return IF;
	if(strcmp(yytext,"inline") == 0) 	return INLINE;
	if(strcmp(yytext,"int") == 0) 		return INT;
	if(strcmp(yytext,"long") == 0) 		return LONG;
	if(strcmp(yytext,"register") == 0) 	return REGISTER;
	if(strcmp(yytext,"restrict") == 0) 	return RESTRICT;
	if(strcmp(yytext,"return") == 0) 	return RETURN;
	if(strcmp(yytext,"short") == 0) 	return SHORT;
	if(strcmp(yytext,"signed") == 0) 	return SIGNED;
	if(strcmp(yytext,"sizeof") == 0) 	return SIZEOF;
	if(strcmp(yytext,"static") == 0) 	return STATIC;
	if(strcmp(yytext,"struct") == 0) 	return STRUCT;
	if(strcmp(yytext,"switch") == 0) 	return SWITCH;
	if(strcmp(yytext,"typedef") == 0) 	return TYPEDEF;
	if(strcmp(yytext,"union") == 0) 	return UNION;
	if(strcmp(yytext,"unsigned") == 0) 	return UNSIGNED;
	if(strcmp(yytext,"void") == 0) 		return VOID;
	if(strcmp(yytext,"volatile") == 0) 	return VOLATILE;
	if(strcmp(yytext,"while") == 0) 	return WHILE;
	if(strcmp(yytext,"_Bool") == 0) 	return BOOL;
	if(strcmp(yytext,"_Complex") == 0) 	return COMPLEX;
	if(strcmp(yytext,"_Imaginary") == 0)return IMAGINARY;
}

{identifier}			{return IDENTIFIER;}

{integer-constant}			{return INTEGER_CONSTANT;}
{floating-constant}			{return FLOATING_CONSTANT;}
{enumeration-constant}		{return ENUM_CONSTANT;}
{character-constant}		{return CHAR_CONSTANT;}


{string-literal}		{return STRING_LITERAL;}

{punctuator}	{
	

	if(strcmp(yytext,"->") == 0) return ARROW;
	if(strcmp(yytext,"++") == 0) return INCREMENT;
	if(strcmp(yytext,"--") == 0) return DECREMENT;
	if(strcmp(yytext,"&") == 0) return BIT_AND;

	

	if(strcmp(yytext,"<<") == 0) return LS;
	if(strcmp(yytext,">>") == 0) return RS;
	if(strcmp(yytext,"<") == 0) return LT;
	if(strcmp(yytext,">") == 0) return GT;
	if(strcmp(yytext,"<=") == 0) return LTE;
	if(strcmp(yytext,">=") == 0) return GTE;
	if(strcmp(yytext,"==") == 0) return EQ;
	if(strcmp(yytext,"!=") == 0) return NEQ;
	if(strcmp(yytext,"^") == 0) return BIT_XOR;
	if(strcmp(yytext,"|") == 0) return BIT_OR;
	if(strcmp(yytext,"&&") == 0) return AND;
	if(strcmp(yytext,"||") == 0) return OR;

	
	if(strcmp(yytext,"...") == 0) return ELLIPSE;
	if(strcmp(yytext,"=") == 0) return ASSIGN;
	if(strcmp(yytext,"*=") == 0) return ASSIGN_MUL;
	if(strcmp(yytext,"/=") == 0) return ASSIGN_DIV;
	if(strcmp(yytext,"%=") == 0) return ASSIGN_MODULO;
	if(strcmp(yytext,"+=") == 0) return ASSIGN_ADD;
	if(strcmp(yytext,"-=") == 0) return ASSIGN_SUB;
	if(strcmp(yytext,"<<=") == 0) return ASSIGN_LS;
	if(strcmp(yytext,">>=") == 0) return ASSIGN_RS;
	if(strcmp(yytext,"&=") == 0) return ASSIGN_BIT_AND;
	if(strcmp(yytext,"^=") == 0) return ASSIGN_BIT_XOR;
	if(strcmp(yytext,"|=") == 0) return ASSIGN_BIT_OR;

	return yytext[0];
}

{whitespace}|{Multi-line-Comment}|{Single-line-Comment}  {}	
	
%%
