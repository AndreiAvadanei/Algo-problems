#include<stdio.h>
#include<string>

#define base 73
#define M1 100007
#define M2 100021

#define MAX_N 2000010

char A[MAX_N],B[MAX_N];
int n,m,sol[1001],total;

int i;
unsigned int hashA1,hashA2;
unsigned int H1,H2;
unsigned int hashB1,hashB2;

int main()
{
	freopen("strmatch.in","r",stdin);
	freopen("strmatch.out","w",stdout);
	
	scanf("%s %s",A,B);
    m = strlen(A);
    n = strlen(B);
    
	H1 = H2 = 1;
	for(i = 0; i < m; i++)
	{
		hashA1 = (hashA1 * base + A[i]) % M1;
		hashA2 = (hashA2 * base + A[i]) % M2;
		
		hashB1 = (hashB1 * base + B[i]) % M1;
		hashB2 = (hashB2 * base + B[i]) % M2;
		
		if(!i) continue;
		H1 = (H1 * base) % M1;
		H2 = (H2 * base) % M2;
	}
	
	for(i = 0; i <= n-m; i++)
	{
		if(hashA1 == hashB1 && hashA2 == hashB2)
		{
			if(total < 1000) sol[total++] = i; else total++;
		}
		hashB1 = ((hashB1 - (B[i] * H1) % M1 + M1) * base + B[i+m]) % M1;
		hashB2 = ((hashB2 - (B[i] * H2) % M2 + M2) * base + B[i+m]) % M2;
	}
	
	printf("%d\n",total);
	for(i = 0; i < (total < 1000 ? total : 1000); i++)
		printf("%d ",sol[i]);
	
	fclose(stdin); fclose(stdout);
}
