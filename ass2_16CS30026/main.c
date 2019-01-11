#include "myl.h"

int main(){
  char *c = "give an integer to print";
  int n;
  float n0;
  int a = printStr(c);
  if(a==1)
  {
    printStr("Error");
  }
  a = readInt(&n);
  if(a==1)
  {
    printStr("Error");
  }
  a = printInt(n);
  if(a==1)
  {
  	printStr("Error");
  }
  c = "give a float to print";
  a = printStr(c);
  if(a==1)
  {
    printStr("Error");
  }
  a = readFlt(&n0);
  if(a==1)
  {
    printStr("Error");
  }

  a = printFlt(n0);
  if(a==1)
  {
  	printStr("Error");
  }
  return 0;

}