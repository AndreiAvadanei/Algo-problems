//la problema asta nu am inteles foarte bine cerinta

#include<stdio.h>

struct nod 
{
	int v;
	nod *urmat;
};

int n,m;
nod *cap1,*coada1;


int main()
{
	int i,n,ok = 0;
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	
	int i;
	scanf("%d%d",&n;
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
    
	while(cap1 != NULL)
	{
		if(cap1->urmat != NULL)
			ok =1;
		cap1 = cap1->urmat;
	}		
	
	printf("%s",ok ? "Are cicluri": "Nu are cicluri");
	fclose(stdin); fclose(stdout);
	return 0;
}