
int findOdd(int arr[], int n) {
   int res = 0, i;
   for (i = 0; i < n; i++)
     res ^= arr[i];
   return res;
}
inline int fib(int n)
{
   if (lookup[n] == NIL)
   {
      if (n <= 1)
         lookup[n] = n;
      else
         lookup[n] = fib(n-1) + fib(n-2);
   }
 
   return lookup[n];
}
int main(int argc, char* argv)
{
	// declarations
	int b,k=50;
	b = 0;

	// type qualifier and pointer specifier
	const short c[] = {0,-1,2,5};
	volatile int *e = 89;

	char ch[] = {'a','j','9','2','5'};
    float n = sizeof(float)/2.0;
    printf("TinyC parser testing...");

    // storage-class specifier
    auto float d = -45.56 ;
    extern short int a=(5^7)|9;
    static int a = 10.2;

    // type-specifier
    _Bool   x;
    _Complex  y;
    _Imaginary z;
    signed int b = -k;
    unsigned long c;

    //enum specifier
    enum {q,w};
    int **f;

    for( int i = 0 ; i< 50 ;i++)
    	// compound statement
    {
    	switch(i) {
    		// labeled statement an jump statements
            case(1) : continue;
            case(2) : break;
            default : return 1;
        }
    }
 	// expression statement
    int j = 1;
    j++;
    --j;
    j *= j;
    j =j-5;
    j |= 21;
    // selection-statement
    if (j||0 && !j) j=j^5;

    if(j==0)
    {
    	j &= j;
    }
    if(i > 10)
    {i%=20;}
    else if(i < 10) 
    i += 5;
    else i -= 7;

    // expressions
    j=j%2;
    j = 2||(3^4); 
    j= (((j>>5)<<8)+9)-100;
    j *= 8;
    j = j%5;
    a_node->val = 50;

    i<<=5;
    i>>=2;
    // iterator statement
    do
    {
    	auto int j=0,k=0;
    	j|=i;
    	i--;
    	if(j>i) break;
    }
    while(i||i+10);

    return 0;
}
