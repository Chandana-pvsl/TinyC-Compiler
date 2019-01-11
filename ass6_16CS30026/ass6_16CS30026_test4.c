// //test file to check basic statements, expression, readi and printi library 
// //functions created in assignment 2
// //also checks the recursive fibonacci function to check the function call and return methodology


// int prints(char *c);
// int printi(int i);
// int readi(int *eP);


// int f(int a){
//   prints("\nEntered the function for i : ");
//   printi(a);
//   int b,ck,d;
//   int p;
//   if(a <=1) 
//     {
//       return a;
//     }
//   else {
//     b = a-1;
//     b = b+f(b);
//     return b;
//   }
//   return 0;
// }

// int main () {
//   int a = 5, b = 2, c;
//   char ch = 'x';
//   char* str;
//   str = "Hello World\n";
//   char* str1;
//   str1 = "abcd";
//   if (a<b) {
//     a++;
//   }
//   else {
//     c = a+b;
//   }
//   int read;
//   int e;
  
//   prints("eneter i: ");
//   readi(&e);
//   prints("You Entered ");
//   printi(e);
//   prints("\n");

//   prints("recursive funtion\n");
//   int out=0;
//   out=f(e);
//   prints("\n\nReturned from recursive function  outptut:");
//   printi(out);

// }


//test file to check basic statements, expression, readi and printi library 
//functions created in assignment 2
//also checks the recursive fibonacci function to check the function call and return methodology


int prints(char *c);
int printi(int i);
int readi(int *eP);


int fib(int a){
  int b=a-1,c,d;
  int p;
  if(b<=0) 
  {
    p=b+1;
  }
  else {
    c=fib(b);
    b=b-1;
    d=fib(b);
    c=c+d;
    p = c;
  }
  return p;
}

int fun(int i) 
{ 
  int p;
  if ( i%2==1 )
  { 
    p = i++; 
  }
  else 
  {
    p= fun(fun( i - 1 ));
  }
  return p; 
} 

int main () {
  int a = 5, b = 2, c;
  char ch = 'x';
  char* str;
  str = "Hello World\n";
  char* str1;
  str1 = "abcd";
  int read;
  int e;
  if (a<b) {
    a++;
  }
  else {
    c = a+b;
  }
  prints("Please enter a number for recursive fibonacci: ");
  read = readi(&e);
  prints("You Entered ");
  c = printi(e);
  prints("\n");

  prints("Now testing for recursive fibonacci number ....Entering the function\n");
  int out=0;
  out=fib(e);
  prints("\n\nReturned from recursive fibonacci function output is");
  printi(out);
  prints("\n");
  prints("Please enter a number for recursive fun function: ");
  read = readi(&e);
  prints("You Entered ");
  c = printi(e);
  prints("\n");
  prints("recursive fun function....Entering the function\n");
  int out1=0;
  out1=fun(e);
  prints("\n\nReturned from recursive fun function output is");
  printi(out1);

  return 0;

}