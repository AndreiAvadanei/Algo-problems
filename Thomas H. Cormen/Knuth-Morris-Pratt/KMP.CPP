#include<stdio.h>
#include<string>

#define MAX_N 2000010
char A[MAX_N],B[MAX_N];
int pi[MAX_N],sol[1005],n,m,total;

void buildPrefix()
{ 
	int i, q = 0;

	for (i = 2, pi[1] = 0; i <= m; ++i)
	{
		while (q && A[q+1] != A[i])
			q = pi[q];
		if (A[q+1] == A[i])
			++q;
		pi[i] = q;
	} 
}

void solve()
{
	int q = 0;
	for (int i = 1; i <= n; ++i)
	{		
		while (q && A[q+1] != B[i])
			q = pi[q];
		if (A[q+1] == B[i])
			++q;
		if (q == m)
		{
			q = pi[m];
			if(total < 1000)
				sol[total] = i-m;
			total++;
		}	
	}		   
}

void show()
{
	printf("%d\n",total);
	for(int i = 0; i < (total < 1000 ? total : 1000); i++)
		printf("%d ",sol[i]);
}

int main()
{
	freopen("strmatch.in","r",stdin);
	freopen("strmatch.out","w",stdout);
	
	scanf("%s %s",A+1,B+1); 
	m = strlen(A+1);
    n = strlen(B+1);	
	
	if(m > n) 
		{ printf("0\n"); return 0; }
	buildPrefix();
	solve();
	show();
	
	fclose(stdin); fclose(stdout);
	return 0;
}
