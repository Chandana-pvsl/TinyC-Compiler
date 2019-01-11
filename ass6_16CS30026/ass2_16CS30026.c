#define MAX_SIZE 100
#define ERR 1
#define OK 0
#define FLOAT_SIZE 12
#define INT_SIZE 9
#include <stdio.h>

int prints(char *s)
{
	char print_str[MAX_SIZE];
	int i=0,len=0;

	while(s[i]!='\0')
	{
		print_str[i]=s[i];
		i++;
	}
	print_str[i++]='\n';
	len = i;

	__asm__ __volatile__(
	"movl $1, %%eax \n\t"
	"movq $1, %%rdi \n\t"
	"syscall \n\t"
	:
	:"S"(print_str), "d"(len)
	) ;
	return len;
}

int printi(int n)
{
	char print_int[MAX_SIZE];
	int i=0, j, k, size;
	int n0;
	if(n == 0) print_int[i++]='0';
	else
	{
		if(n < 0)
		{
			print_int[i++]='-';
			n = -1*n;
		}
		while(n)	
		{
			n0 = n%10;
			print_int[i++] = (char)(n0+'0');
			n /= 10;
		}
		if(print_int[0] == '-') j = 1;
		else j = 0;
		k=i-1;
		while(j<k)
		{
			char temp=print_int[j];
			print_int[j++] = print_int[k];	
			print_int[k--] = temp;
		}
	}
	print_int[i]='\n';
	size = i+1;
	if((((int)print_int[0]-'0')<0 || ((int)print_int[0]-'0')>9) && print_int[0]!='-')
	{
		return ERR;
	}
	for(i=1;i<size-1;i++)
	{
		if (((int)print_int[i]-'0')<0 || ((int)print_int[i]-'0')>9)
		{
			return ERR;
		}
	}
	__asm__ __volatile__ (
	"movl $1, %%eax \n\t"
	"movq $1, %%rdi \n\t"
	"syscall \n\t"
	:
	:"S"(print_int), "d"(size)
	) ; 
	return size;
}



int printd(float m)
{
	char print_float[MAX_SIZE];
	int i= 0, j, k, size;
	float dec;
	int n0,n1,p=0;
	if(m == 0) print_float[i++]='0';

	else
	{
		if(m < 0)
		{
			print_float[i++]='-';
			m = (-1)*m;
		}

		n1 = (int)m;

		dec = (m-n1)*10;
		if(dec==0)
		{
			while(p<6)
			{
				print_float[i++]='0';
				p++;
			}
		}
		else{
		while(dec && p<6)	
		{
			n0 = (int)dec;
			print_float[i++] = (char)(n0+'0');
			if (((int)print_float[i-1]-'0')<0 || ((int)print_float[i-1]-'0')>9)
			{
				return ERR;
			}
			dec = dec-n0;
			dec *= 10;
			p++;
		}
		}
		if(print_float[0] == '-') j = 1;
		else j = 0;
		k=i-1;
		while(j<k)
		{
			char temp=print_float[j];
			print_float[j++] = print_float[k];	
			print_float[k--] = temp;
		}
		print_float[i++]='.';
		if (print_float[i-1]!='.')
		{
			return ERR;
		}

		while(n1)	
		{
			n0 = n1%10;
			print_float[i++] = (char)(n0+'0');
			if (((int)print_float[i-1]-'0')<0 || ((int)print_float[i-1]-'0')>9)
			{
				return ERR;
			}
			n1 /= 10;

		}
		
		if(print_float[0] == '-') j = 1;
		else j = 0;
		k=i-1;
		while(j<k)
		{
			char temp=print_float[j];
			print_float[j++] = print_float[k];	
			print_float[k--] = temp;
		}
	}

	print_float[i]='\n';
	size = i+1;

	if((((int)print_float[0]-'0')<0 || ((int)print_float[0]-'0')>9) && print_float[0]!='-')
	{
		return ERR;
	}

	__asm__ __volatile__ (
	"movq $1, %%rax \n\t"
	"movq $1, %%rdi \n\t"
	"syscall \n\t"
	:
	:"S"(print_float), "d"(size)
	) ; 
	return OK;
}

int readi(int *n) {
	char read_int[1];
	char n_str[INT_SIZE];
	int k=0,i;
	*n = 0;
	for(;;)
	{
		__asm__ __volatile__ ("syscall"::"a"(0), "D"(0), "S"(read_int), "d"(1));
		if(read_int[0]=='\n'|| read_int[0]==' '||read_int[0]=='\t')
		{
			break;
		}
		else if (((int)read_int[0]-'0'<0||(int)read_int[0]-'0'>9) && read_int[0]!='-') 
		{
			return ERR;
		}
		else
		{
			n_str[k]=read_int[0]; 
			k++;
		}
	}
	if(k == 0 || k > INT_SIZE)
	{
		return ERR;
	}
	if(n_str[0]=='-')
	{
		if(k==1)
		{
			return ERR;
		}
		i=1;
		while(i<k)
		{
			if(n_str[i]=='-')
			{
				return ERR;
			}
			else
			{
				(*n) *= 10;
				(*n) += (int)n_str[i]-'0'; 
			}
			i++;
		}
		*n = (-1)*(*n);

	}
	else
	{
		i=0;
		while(i<k)
		{
			if(n_str[i]=='-')
			{
				return ERR;
			}
			else
			{
				(*n) *= 10;
				(*n) += (int)n_str[i]-'0';
			} 
			
			i++;
		}
	}
	return OK;
}

int readf(float *n)
{
	char read_flt[1];
	char n_str[FLOAT_SIZE];
	int k=0,i=0,flag =1;
	float t;
	int s,z,o=1;
	*n = 0.0;
	for(;;)
	{
		__asm__ __volatile__ ("syscall"::"a"(0), "D"(0), "S"(read_flt), "d"(1));
		if(read_flt[0]=='\n'|| read_flt[0]==' '||read_flt[0]=='\t')
		{
			break;
		}
		if (((int)read_flt[0]-'0'<0||(int)read_flt[0]-'0'>9) && read_flt[0]!='-' && read_flt[0]!='.')
		{
			return ERR;
		}
		n_str[k]=read_flt[0]; 
		k++;
	}
	if(k==0||k>FLOAT_SIZE)
	{
		return ERR;
	}
	if(n_str[0]=='.' )
	{
		return ERR;
	}
	if(n_str[0]=='-')
	{
		if(k==1)
		{
			return ERR;
		}
		if(n_str[1]=='.')
		{
			return ERR;
		}
		i=1;
		while(i<k)
		{
			if(n_str[i]=='-' )
			{
				return ERR;
			}
			else if((n_str[i]=='.' && flag == 0))
			{
				return ERR;
			}
			else
			{
				if(n_str[i]=='.')
				{
					flag =0;
					s = i;
					i++;
					continue;
				}
				if(flag==1)
				{
					(*n) *= 10;
					(*n) += (int)n_str[i]-'0';
				} 
				else
				{
					t = (int)n_str[i]-'0';
					o = 1;
					for(z=0;z<(i-s);z++)
					{
						o *= 10;
					}
					t /= o;
					*n += t;
				}
			}
			i++;
		}
		*n = (-1)*(*n);
	}
	else
	{
		while(i<k)
		{
			if(n_str[i]=='-')
			{
				return ERR;
			}
			else if((n_str[i]=='.' && flag == 0))
			{
				return ERR;
			}
			else
			{
				if(n_str[i]=='.')
				{
					flag =0;
					s = i;
					i++;
					continue;
				}
				if(flag==1)
				{
					(*n) *= 10;
					(*n) += (int)n_str[i]-'0';
				} 
				else
				{
					t = (int)n_str[i]-'0';
					o = 1;
					for(z=0;z<(i-s);z++)
					{
						o *= 10;
					}
					t /= o;
					*n += t;
				}
			}
			i++;
		}
	}
	return 0;

}
