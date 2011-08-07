#include<stdio.h>


struct nod 
{
	int v;
	nod* urmat;
};

nod *cap,*coada;


nod *oglinda(nod *cap)
{
	nod *oglinda = new nod;
	nod *aux;
	oglinda->urmat = NULL;
	oglinda->v = cap->v;
	cap = cap->urmat;
	while(cap != NULL)
	{
		aux = new nod;
		aux->urmat = oglinda;
		aux->v = cap->v;
	
		oglinda = aux;
		
		cap = cap->urmat;
	}
	
	return oglinda;
}

int uoglinda(nod *w,nod *cap)
{
	int ok = 1;
	nod *ogl = oglinda(cap);
	while(w != NULL)
	{
		if(cap == NULL)
		{
			ok = 0;
			break;
		}
		if(cap->v != w->v)
		{
			ok =0;
			break;
		}
		cap = cap->urmat;
		w = w->urmat;
	}
	if(!ok || cap != NULL) return 0;
	while(w!= NULL)
	{
		if(ogl == NULL)
		{
			ok = 0;
			break;
		}
		if(ogl->v != w->v)
		{
			ok = 0;
			break;
		}
		w = w->urmat;
		ogl = ogl->urmat;
	}
	return (ok && w == NULL && v == NULL);
}

//listele pot fi de diferite lungimi
nod* sirw1w2(nod* cap1,nod* cap2)
{
	nod *w1w2 = new nod;
	w1w2->v = cap1->v;
	w1w2->urmat = NULL;
	cap1 = cap1->urmat;
	while(cap1 != NULL && cap2 != NULL)
	{
		w1w2->urmat = new nod;
		w1w2->urmat->v = cap2->v;
		w1w2 = w1w2->urmat;
		w1w2->urmat = new nod;
		w1w2->urmat->v = cap1->v;
		w1w2->urmat->urmat = NULL;
		w1w2 = w1w2->urmat;
		
		cap1 = cap1->urmat;
		cap2 = cap2->urmat;
	}
	cap1 = cap1 != NULL ? cap1 : cap2;
	while(cap1 != NULL)
	{
		w1w2->urmat-> = new nod;
		w1w2->urmat->v = cap1->v;
		w1w2->urmat->urmat = NULL;
		cap1 = cap->urmat;
		w1w2 = w1w2->urmat;
	}
}

int main()
{
	int i,n;
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	
	scanf("%d",&n);
	//citeste lista
	i = 0; cap = new nod;
	scanf("%d",&cap->v);
	cap->urmat = NULL; 
	coada = cap;
	for(++i; i < n; i++)
	{
		coada->urmat = new nod;
		coada->urmat->urmat = NULL;
		scanf("%d",&coada->urmat->v);
		coada = coada->urmat;
	}
    
	/*nod *ogl = oglinda(cap);
	
	while(ogl != NULL)
	{
		printf("%d ",ogl->v);
		ogl = ogl->urmat;
	}*/
	fclose(stdin); fclose(stdout);
	return 0;
}


