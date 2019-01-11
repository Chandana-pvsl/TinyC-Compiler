//test file to check functions and iterations and also some of the
//functions created in assignment 2

int prints(char *c);
int printi(int i);
int readi(int *eP);


int fib(int a){
  prints("Entering the fib function\n");
  int f=1,f_1=0;
  int i=1,temp;
  while(i<a) {
    temp=f;
    f=f+2*f_1;
    f_1=temp;
    i=i+1;
  }
  return f;
}

int main () {
  prints("enter i: ");
  int i=0,ep;
  i=readi(&ep);
  prints("\n\nnumber entered:");
  printi(ep);

  prints("\ncalculating modified fibonocci numbers\n");
  int j;
  j=fib(ep);
  prints("\n\nSuccesfully!! Returned from the fib function output is:");
  printi(j);
  return;
}