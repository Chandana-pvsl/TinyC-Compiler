int prints(char *c);
int printi(int i);
int readi(int *eP);

void div(int a,int b){
  prints("\n\nEntered the function \n");
  int l;
  l=a%b;
  if(l==0)
  {
    prints("number is divisible by the other ");
  }
  else
  {
    prints("number is not divisible by the other");
  }
  prints("\n");
}

int main() {
  int i,j=1,k;

  prints("enter i: ");
  readi(&i);
  prints("You Entered ");
  printi(i);
  prints("enter j: ");
  readi(&j);
  prints("You Entered ");
  printi(j);

  prints("Entering the function divisible... \n");
  div(i,j);
  prints("succesfully returned from function \n"); 
  return 0;
}