#include <stdio.h>
#include <math.h>
int cf[9];

void afisare(int[],int);

int main()
{
	int n,i,j,c,p;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p=pow((double)i,2);
		c=pow((double) i,3);
		
		while(p!=0)
		{
			j=0;			
			while(c!=0)
			{
				if(p%10==c%10)
				{
					cf[j++]=p%10;
					
				}
				c=c/10;
			}
			if(j>0)
			{
				afisare(cf,j);
				printf("\n %d \n",i);
			}
				
			p=p/10;
		}
		
	}
	
	return 0;
}

void afisare(int v[],int k)
{
	int i;
	for(i=0;i<k;i++)
	{
		printf("%d ",v[i]);
	}
}
