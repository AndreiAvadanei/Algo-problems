#include<iostream>

using namespace std;

int n;

void downHeap(int a[],int v)
{
	int w = 2 * v;    
    while (w<n)
    {
       if (w+1<n)    
          if (a[w+1]>a[w]) w++;
                     

        if (a[v]>=a[w]) return;   
        a[v] ^= a[w] ^= a[v] ^= a[w];
        v = w;        
        w = 2 * v;
    }
}

void heapSort(int a[])
{
	for(int i = n/2-1; i >= 0; i--)
		downHeap(a,i);
	while(n > 1)
	{
		n--;
		a[0] ^= a[n] ^= a[0] ^= a[n];
		downHeap(a,0);
	}
}

void heapDown2(int v,int a[])
{
    int w = 2 * v;    
    while (w<n)
    {
       if (w+1<n)    
          if (a[w+1]>a[w]) w++;
                     

        if (a[v]>=a[w]) return;   
		a[w] ^= a[v] ^= a[w] ^= a[v];
        v = w;        
        w = 2 * v;
    }
}

int main()
{
    int i;
	int a[] = { 0,16,4,10,14,7,9,3,2,8,1 };
	n = 11;
	
   	for(int i = n/2; i >= 1; i--)
		heapDown2(i,a);
	while(n > 2)
	{
		n--;
		a[1] ^= a[n] ^= a[1] ^= a[n];
		heapDown2(1,a);
        
	}
	
	for(i = 1; i <= 10;i++)
	{
		cout<<a[i]<<" ";
	}
	system("pause");
	return 0;
}
