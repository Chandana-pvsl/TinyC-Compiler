// test for declarations and assignment statements
int a[10][20];
int main(int args, char* argv)
{
	float a;
	a = 10.45;
	int i,w[10];
	int a = 4,*p,b;
	float b = 2.6;
	void func(int i, float d);
	k=sorting_a(p,4);
	fun();
	char c;
	c = 'a';
	if(c != 'b')
	{
		c = (char)125; 
		b = a<<2;
	}
	do
	{
		b = b+1;
		b = b*7;
	}while(1);
	b = a<b?1:0;
	return 0;

}
void fun()
{
	printf("fun");
}
int sorting_a(int a[],int size)
{
    int i,j,temp;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(a[i]>=a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    return 0;
}