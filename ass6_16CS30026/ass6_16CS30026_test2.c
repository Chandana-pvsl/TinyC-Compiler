//This test file extensively checks the expressions both boolean and algebraic
//and also the funciton calling and returning process in detail

int prints(char *c);
int printi(int i);
int readi(int *eP);
int a;
int b = 1;
char c;
char d = 'a';

int pro(int a, int b) {
  int ans;
  int c = 2, d, arr[10];
  int *p;
  prints("function starts here");
  ans = a*b;
  ans =ans +1;
  d = 2;
  //redundant code for computation
  if (a>=d) {
    a++;
  }
  else {
    c = a+b;
  }
  prints("function ends here");
  return ans;
}
int main () {
  int c = 2, d, arr[10];
  int*p;
  int x, y, z;
  int eP;
  prints("Enter two numbers :");
  ep = readi(&x);
  ep = readi(&y);
  z = pro(x,y);
  prints("product of numbers +1 is equal to ");
  printi(z);
  prints("\n");
  return c;
}