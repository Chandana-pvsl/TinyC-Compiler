#include <stdio.h>
//assignment3
/*P.V.S.L. Hari Chandana
 16cs30026*/

typedef struct list{
	tree *next;
	int value;
}list;

void main(){
	// checking keywords
	auto
	enum
	restrict
	unsigned
	break
	extern
	return
	void
	case
	float
	short
	volatile
	char
	for
	signed
	while
	const
	goto
	sizeof
	_Bool
	continue
	if
	static
	_Complex
	default
	inline
	struct
	_Imaginary
	do
	int
	switch
	double
	long
	typedef
	else
	register  
	  union
	auto x = 40; 
	// checking constants,identifiers,string literals and keywords
	int i=5,_identify;
	char ch='Ican';
	char ch216_12;
	int *k = malloc(sizeof(int)*15);
	ch = 'c';
	char* str = "Assignment3 \"lexer assignment\"16CS30026\f";
	char d[262];
	tree *node = calloc(sizeof(tree),1);
	tree *node1 = calloc(sizeof(tree),1);
	node->next = node1;
	float _f = 1632.;
	_f = 16.235;
	_f = 16.32e+1235;
	_f = 0.23;
	i = 16E-156;
	i = 1;
	i = i<<2;
	f *= 12;
	enum Month {may};
	enum Day{ Monday =1, Tuesday, Wednesday, Thursday};
   printf("Thursday/Tuesday = %d\n", Thursday/Tuesday);
   i |=0;
   i +=12;
   i *=1;
   i >>= 2;
	if(i>(int)f)
	{
		printf("%d is greater than f",i);
	}
	else if(i%2==0)
	{
		printf("i is even");
	}
	switch(ch)
	{
		case 'a':
		{
			printf("it is a");
			break;
		}
		case 'b':
		{
			printf("it is b");
			break;
		}
		case 'c':
		{
			printf("it is c");
			break;
		}

	}

	int j=0.0;

	do{
		j++;
	}while(j<10);


	return 0;
}
