#include<iostream>

using namespace std;

int n;
void downHeap(int[],int),makeHeap(int[]),insert(int[],int);
int maxHeap(int[]);

int main()
{
	int a[] = { 16,4,10,14,7,9,3,2,8,1 };
	n = 10;
	makeHeap(a);
	cout<<maxHeap(a);
	return 0;
}

void downHeap(int a[],int v)
{
   int w = v*2;
   while(w < n)
   {
	   if(w+1 < n)
		if(a[w+1] > a[w]) w++;
	   if(a[v] >= a[w]) return;
	   a[v] ^= a[w] ^= a[v] ^= a[w];
       w *= 2;	
   }	   
}

void makeHeap(int a[])
{
   for(int i = n/2-1; i >= 0;i--)
	   downHeap(a,i);
}


int maxHeap(int a[])
{
   int max = a[0];
   a[0] = a[n-1];
   n--;
   downHeap(a,0);
   return max;
}

void insert(int a[],int v)
{
	int i = ++n;
	while(i > 0 && a[i/2] < v)
	{
		a[i] = a[i/2];
		i = i/2;
	}
	a[i] = v;
}