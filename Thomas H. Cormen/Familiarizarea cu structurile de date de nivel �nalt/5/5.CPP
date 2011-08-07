#include<stdio.h>

struct nod 
{
	int v;
	nod *urmat;
};

int n,m;
nod *cap1,*cap2,*coada1,*coada2;

int main()
{
	
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	
	int i;
	scanf("%d%d",&n,&m);
	//citeste prima lista
	i = 0; cap1 = new nod;
	scanf("%d",&cap1->v);
	cap1->urmat = NULL; 
	coada1 = cap1;
    for(++i; i < n; i++)
	{
		coada1->urmat = new nod;
		coada1->urmat->urmat = NULL;
		scanf("%d",&coada1->urmat->v);
		coada1 = coada1->urmat;
	}
	//citim a doua lista
	i = 0; cap2 = new nod;
	scanf("%d",&cap2->v);
	cap2->urmat = NULL; 
	coada2 = cap2;
    for(++i; i < m; i++)
	{
		coada2->urmat = new nod;
		coada2->urmat->urmat = NULL;
		scanf("%d",&coada2->urmat->v);
		coada2 = coada2->urmat;
	}
	//lipim cele doua liste
	coada1->urmat = cap2;
	
	//afisam noua lista
	while(cap1 != NULL)
	{
		printf("%d ",cap1->v);
		cap1 = cap1->urmat;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
