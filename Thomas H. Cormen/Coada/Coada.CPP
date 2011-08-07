//Coada circulara - reia procesul cand capul a ajuns la maxim dar totusi coada este vida :)
#include<stdio.h>

#define MAX_N 2

int Q[MAX_N];
int coada = -1,cap = -1;

int full()
{
	return (cap == MAX_N-1);
}

int vid()
{
   return (coada == cap);
}

void push(int val)
{
    if(full())
    {
		if(vid())
		{
			coada = cap = -1;
		}
		else
		{
			return; //eroare
		}
    }	    
	Q[++cap] = val;	 
}

int pop()
{
	if(vid()) return -1; //eroare
	int val = Q[++coada];	 
	
	return val;
}

int main()
{
	push(10);
	push(15);
	printf("%d",pop());
	pop();
 
	push(20);
	printf("%d",pop());
	return 0;
}
