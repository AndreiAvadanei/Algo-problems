#include<stdio.h>
#include<string>

#define MAX_N 200010
char A[MAX_N],B[MAX_N];
int n,m,k;
int intr[MAX_N];
int sol[MAX_N];

void show(int v,int times)
{
	for(int i = 0; i < times; i++)
		printf("%d\n",v);
}

void read()
{
	scanf("%s",A); //citim primul sir
	n = strlen(A);
	do scanf("%c",&m); while(m=='\n' || m=='\n');
	B[0] = m; m = 0;
	//citim al doilea sir si salvam interogarile
	while(B[m]!='\n' && B[m]!='\r' && B[m] != '\0')
	{
		scanf("%c",&B[++m]);
		if(B[m]=='?') 
		{
			intr[m-1]++;
			B[m--] = '\0';
		}
	}
	B[m] = '\0';
}

void build(int prev,int len)
{
	int st,p;
	for(int i = 0; i < k; i++)
	{
		st = sol[i];
		p  = prev;
		while(A[st+p] == B[p] && p <= m && p <= len)
			p++;
		if(p != len+1)
			sol[i--] = sol[--k];
	}
}

void solve()
{
	int prev = 0;
	for(int q = 0; q < m;q++)
	{
		if(intr[q])
		{
			build(prev+1,q);
			prev = q;
			show(k,intr[q]);
		}
	}		
}

void begin()
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(A[i] == B[0]) sol[k++] = i;
	}
}

int main()
{
	freopen("seti.in","r",stdin);
	freopen("seti.out","w",stdout);
	
	read();
	begin();
	
	solve();
	
	fclose(stdin); fclose(stdout);
	return 0;
}
