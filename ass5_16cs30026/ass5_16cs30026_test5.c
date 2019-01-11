// test fro boolean logic and assignment expressions
int foo(int a)
{
	int b,c;
	b = 10;
	c = b++;
	c = b-a;
	return b;
}

int logical()
{
	int a=5,b=-6;
	int log;
	// log = a||b;
	log = a&b;
	log = a^b;
	log = a|b;
	log = a||b;
	log = a&&b;
	if(log!=0)
	{
		printf("%d",log);
		if(a<10 && b>20)
		{
			log = log%10;
		}
	}
	else 
		log = 1;
	return log;
}
int main()
{
	int g;
	g = foo(10);
	g = logical();
	return 0;
}