#include<iostream>

using namespace std;

void sort(int v[],int n)
{
    int i,j,x;
    for(i = 1; i < n; i++)
	{
		x = v[i];
		j = i-1;
		while(j >= 0 && v[j] > x)
		{
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = x;
	}		
}

int main()
{
	int a[] = { 5,2,4,6,1,3 };
	
	sort(a,6);
	for(int i = 0; i < 6;i++)
	{
		cout<<a[i]<<" ";
	}
    
    return 0;
}