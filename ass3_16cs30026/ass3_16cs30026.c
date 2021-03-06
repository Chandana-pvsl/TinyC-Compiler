#include <stdio.h>
#include "lex.yy.c"


int main(int argc,char *argv[]) 
{
	int token;
	while (token = yylex())
	 {
		switch (token) 
		{
			case COMMENT: 	printf("<COMMENT, %d, %s>\n", token,yytext); 
				break;
			case KEYWORD: 	printf("<KEYWORD, %d, %s>\n", token, yytext); 
				break;
			case IDENTIFIER: 	printf("<IDENTIFIER, %d, %s>\n", token, yytext); 
				break;
			case CONSTANT: 	printf("<CONSTANT, %d, %s>\n", token, yytext); 
				break;
			case PUNCTUATOR: 	printf("<PUNCTUATOR, %d, %s>\n", token, yytext); 
				break;
			case STRING_LITERAL: 	printf("<STRING-LITERAL, %d, %s>\n", token, yytext); 
				break;
		}
	}
	return 0;
}
