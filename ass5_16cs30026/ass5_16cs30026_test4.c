// test for global functions
int a;
void fun(int a, int *b, char c, float d);
char **c;
int f[10];
int main()
{
	float c[5][6];
	for(i=0;i<4;i++)
	{
		if(c[i]<c[i+1])
		{
			printf("f is great");
		}
	}
	c[0][1] = 45;
	while(i<5)
	{
		while(j<5)
		{
			c[i][j] = i+j;
		}
	}
	return 0;
}
