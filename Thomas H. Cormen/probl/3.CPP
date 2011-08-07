//nu e clar enuntul, starea celulelor se ia de la pasul anterior strict?Asa am considerat eu
//netestat , nu stiu daca e cea mai buna solutie

#include<stdio.h>


int n,m,p;
short mat[1000][1000];
short mat2[1000][1000];

void read();
void show(int);
void make(int);

int dx[] = {0,0,1,-1,-1,1,-1,1};
int dy[] = {-1,1,0,0,-1,1,1,-1};

int main()
{
	int i;
	scanf("%d%d%d",&n,&m,&p);
	read();
	
	if(p==0) show(1);
	else
	{		
		for(i=0;i<p;i++)
		{
			make(i);
			show(i);
			printf("\n");
		}
	}
	return 0;
}

void show(int p)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(p%2==0)
			{
				printf("%d ",mat2[i][j]);	
			}
			else
			{
				printf("%d ",mat[i][j]);
			}
		}
		printf("\n");
	}

}

void make(int wh)
{
	int i,j,desc,inc,r;
	
	wh = (wh%2==0);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			inc=desc=0;
			for(r=0;r<8;r++)
			{
				if(wh) 
				{
					if(mat[i+dx[r]][j+dy[r]])
						desc++;
					else
						inc++;
				}
				else
				{
					if(mat2[i+dx[r]][j+dy[r]])
						desc++;
					else
						inc++;
				}
			}
			if(wh)
			{
				if(mat[i][j]==0 && desc==3)
				{
					mat2[i][j]=1;
				}
				else if(mat[i][j]==1 && (desc==3 || desc==2))
				{
					mat2[i][j]=1;
				}
				else
				{
					mat2[i][j]=0;
				}
				
			}
			else
			{
				if(mat2[i][j]==0 && desc==3)
				{
					mat[i][j]=1;
				}
				else if(mat2[i][j]==1 && (desc==3 || desc==2))
				{
					mat[i][j]=1;
				}
				else
				{
					mat[i][j]=0;
				}
			}
		}
}

void read()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&mat[i][j]);
}
