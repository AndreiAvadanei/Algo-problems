#include<iostream>

using namespace std;
int n;

void buildHeap(int[]),heapDown(int[],int),heapUp(int[],int),addHeap(int[],int);
int cutHeap(int[],int);
int search(int[],int,int);

int main()
{
	int a[] = { 20,10,19,9,8,18,17,7,6,5,4,16 };
	n = 12;
    buildHeap(a);	

	cout<<"\n"<<search(a,100,0);
	system("pause");
	
	return 0;
}

void buildHeap(int a[])
{
	for(int i = n/2; i>=0; i--)
	{
		heapDown(a,i);
	}
}

void heapDown(int a[],int v)
{
	int w = v*2;
	while(w < n)
	{
		if(w+1 < n && a[w+1] > a[w]) w++;
		if(a[v] >= a[w]) return;
		a[v] ^= a[w] ^= a[v] ^= a[w];
		v = w;
		w *= 2;
	}
}

void heapUp(int a[],int v)
{
	int k = a[v];
	while(v && k > a[v/2])
	{
		a[v] = a[v/2];
		v/=2;
	}
	a[v] = k;
}

int cutHeap(int a[],int v)
{
	int k = a[v];
	a[v] = a[--n];
	if(v && a[v] > a[v/2])
		heapDown(a,v);
	else
		heapUp(a,v);
	
	return k;
}

void addHeap(int a[],int k)
{
	a[++n] = k;
	heapUp(a,n-1);
}


int search(int a[],int k,int v)
{
	int ans = -1,r;
	if(a[v] == k) ans = v;
    else
    {
	    if(v*2+1 < n)
        {					
			r = search(a,k,v*2+1);
		    ans = ans == -1 ? r : ans;
		}
		
		if(v*2+2 < n && ans == -1) 
		{			
			r = search(a,k,v*2+2);
		    ans = ans == -1 ? r : ans;
		}		 
	}
	return ans;
}
