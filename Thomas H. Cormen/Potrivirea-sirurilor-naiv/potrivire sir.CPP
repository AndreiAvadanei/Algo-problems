#include<stdio.h>
#include<string>
#define MAX_N 2000000
char A[MAX_N],B[MAX_N];
int sol[1001];
int n,m,k;

int len(char *p) { return (*p ? len(++p)+1 : 0); }
void read(),solve(),show();
int main()
{
	freopen("strmatch.in","r",stdin);
	freopen("strmatch.out","w",stdout);
	
	read();
   	solve();
	show();
	
	fclose(stdin); fclose(stdout);
	return 0;
}



void read()
{
	scanf("%s",&A);
	scanf("%s",&B);
	 
	n = strlen(A);
	m = strlen(B);
}

void solve()
{
	int i,j;
	for(i = 0; i <= m-n; i++)
	{
		j = 0;
		while(A[j] == B[i+j] && j < n) j++; 
		if(j == n) 
		{
			if(k < 1000) sol[k++] = i;	
			else k++;
		}
	}
}

void show()
{
	printf("%d\n",k);
	for(int i = 0; i < (k > 1000 ? 1000 : k); i++)
		printf("%d ",sol[i]);
}
