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
	int i,ok = 1;
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if(n != m) printf("Nu sunt egale"); 
	else
	{
		i = 0;
		cap1 = new nod; cap2 = new nod;
		scanf("%d%d",&cap1->v,&cap2->v);
		cap1->urmat = cap2->urmat = NULL;
		coada1 = cap1; coada2 = cap2;
		i++;
		for(; i < n; i++)
		{
		    coada1->urmat = new nod;
			coada2->urmat = new nod;
			coada1->urmat->urmat = NULL;
			coada2->urmat->urmat = NULL;
			scanf("%d%d",&coada1->urmat->v,&coada2->urmat->v);
			coada1 = coada1->urmat;
			coada2 = coada2->urmat;
		}
		while(cap1 != NULL)
		{
			if(cap1->v != cap2->v)
			{	
				ok = 0; 
				break; 
			}
			cap1 = cap1->urmat;
			cap2 = cap2->urmat;
		}
		printf("%s",(ok ? "Sunt egale" : "Nu sunt egale"));
	}
	
		
	fclose(stdin); fclose(stdout);
	return 0;
}
