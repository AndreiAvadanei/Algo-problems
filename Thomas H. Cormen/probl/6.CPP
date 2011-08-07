//nu-i optim
//netestat
#include<stdio.h>
#include<string.h>

char cuv[100][1000];
int n,m,k;

char cuv2[100][1000];

char sol[100][1000];
char used[100];

void check(int);
void showSol();
int sols();

int main()
{
	int i;
	scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < n; i++)
		scanf("%s", cuv[i]);
	for(i=0;i<m;i++)
		scanf("%s",cuv2[i]);
	for(i=0;i<m;i++)
	{
		//mda trebuie backtracking
		check(0);
	}
	return 0;
}

void check(int sl)
{
	int i;
	if(sl == k) { if(sols()) showSol(); return; }
	
	for(i = 0; i < n; i++)
	{
		if(!used[i])
		{
			strcpy(sol[sl],cuv[i]);
			used[i]=1;
			check(sl+1);
			used[i]=0;
			strcpy(sol[sl],NULL);
		}
	}
}

int sols()
{
	char c1[1000],c2[1000];
	int j1,j2,lng=strlen(sol[0]);
	for(j1=0;j1<k;j1++)
	{
		c1[j1]=sol[j1][0];
		c2[j1]=sol[j1][lng-1];
	}
	for(j1=0;j1<k;j1++)
		for(j2=0;j2<k;j2++)
		{
			if(strcmp(c1,cuv2[j1])==0 && strcmp(c2,cuv2[j2])==0)
				return 1;
		}
	return 0;
}

void showSol()
{
	printf("\n");
	for(int p = 0; p < k;p++)
		printf("%s\n",sol[p]);
	
}
