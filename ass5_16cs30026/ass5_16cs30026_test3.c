// test for functions
char ch;
int main()
{
	int b,c;
	int a[10];
	a[b] = c;
	float *p;
	*p = 12.5;
	p = &b;
	while(i>0)
	{
		for(j=0;j<10;j++)
		{
			i++;
			j++;
		}
	}
	fun(15);
	k = fib(10);
	return 0;
}
void fun(int a) 
{ 
    printf("Value of a is %d", a); 
    char *f ;
} 
  
int m() 
{ 
    void (*fun_ptr)(int a) = &fun;   
    return 0; 
}

int fib(int n)
{
	if(n==1)
	{
		return 1;
	}
	else if(n==0) return 0;
	else return fib(n-2)*fib(n-1);
}
