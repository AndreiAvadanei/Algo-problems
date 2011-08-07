#include<stdio.h>

#define MAX_N 101

int S[MAX_N];
int varf;

int vid()
{
	return !varf; 
}

int full()
{
    return (MAX_N < varf);	
}

void push(int val)
{
	if(!full())
	{
		S[++varf] = val;
	}
}

int pop()
{
   if(!vid())
   {
	   return S[varf--];
   }	
   return -1;   
}

int main()
{
	push(10);
	printf("%d",pop());
	return 0;
}
