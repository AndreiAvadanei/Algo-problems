#include<stdio.h>

struct nod {
	int v;
	nod* urmatorul;
};

nod *cap, *curent,*x;
int main()
{
	int i,n;
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		curent = new nod;
		scanf("%d",&curent->v);
		curent->urmatorul = cap;
		cap = curent;
	}
	while(cap != NULL)
	{
		printf("%d ",cap->v);
		cap = cap->urmatorul;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
