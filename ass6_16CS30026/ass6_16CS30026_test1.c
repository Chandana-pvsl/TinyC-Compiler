int printi(int num);
int prints(char * c);
int readi(int *eP);

int f(int *a)
{
    int bi;
    bi = *a;
    bi = bi+2;
    return bi;
}
int main()
{
    int b;
    int e,*l,s;
    b = 3;
    
    prints("Passing pointers to function f!\n");
    prints("Value passed to function: ");
    printi(b);
    prints("\n");
    prints("value returned from function is: ");
    b=f(&e);
    printi(5);

    prints("give an integer as input");
    prints("\n");
    b = readi(&e);
    prints("The integer that was read is:");
    printi(e);
    prints("\n");

    int k[10],i;
    prints("printing array numbers+5");

    for(i=0;i<10;i++)
    {
        k[i] = i+5;
        printi(k[i]);
    }   
    return 0;
}

