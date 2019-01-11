#include <stdio.h>
#include "assgn4.tab.h"

extern int yyparse();

int main() {
	yydebug = 1;
  int i=yyparse();
  printf("Parser results\n\n");
  if(i) 
  	{
  		printf("Failure!\n");
  	}
  else 
  	{
  		printf("Success!\n");
  	}
	return 0;
}
