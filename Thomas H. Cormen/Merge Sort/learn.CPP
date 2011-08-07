#include<iostream>

using namespace std;

void merge(int v[],int,int,int);
void sort(int v[],int st,int dr)
{
   if(st < dr) 
   {
	   int mijl = (st+dr)/2;
	   sort(v,st,mijl);
	   sort(v,mijl+1,dr);
	   merge(v,st,mijl,dr);
   }
}

void merge(int v[],int st,int mijl,int dr)
{
    int i,j,k,b[100];
	
    i = 0; j = st;
	while(j <= mijl)
	   b[i++] = v[j++];
    
	i = 0; k = st;
	while(k < j && j <= dr)
	   if(b[i] <= v[j])
		   v[k++] = b[i++];
	   else
		   v[k++] = v[j++];
	
	while(k < j)
        v[k++] = b[i++];		
}

int main()
{
    int a[] = { 5,2,4,6,1,3 };
	
	sort(a,0,6);
	for(int i = 0; i < 6;i++)
	{
		cout<<a[i]<<" ";
	}
    
    return 0;
}
