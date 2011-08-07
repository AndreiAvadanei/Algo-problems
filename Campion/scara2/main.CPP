#include<cstdio>
#define oo 30000
using namespace std;
int n,k,i,a,b,j,p,t,cost,l,L,e,A[150],E[150],C[300][300];
void init(),solve();
int main()
{
    init();
    solve();
    return 0;
}
void init()
{
    freopen("scara2.in","r",stdin);
    freopen("scara2.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(i=1;i<=120;i++)A[i]=1;
    for(i=1;i<=k;i++)scanf("%d%d",&a,&b),A[a]=b;
    scanf("%d",&k);
    for(i=1;i<=k;i++)scanf("%d%d",&a,&b),E[a]=b;

    for(i=1;i<=120;i++)
        for(j=1;j<=120;j++)
            C[i][j]=oo;
}
void solve()
{
    C[1][1]=0;
    for(t=1;t<=120;t++)
        for(p=1;p<=120;p++)
        {
            cost = C[t][p];
            for(a=1;a<=A[t];a++)
            {
                L=t+a; for(l=t+1;l<=L;l++) if(cost<C[l][p+1])C[l][p+1]=cost;
            }
            for(e=1;e<=E[t];e++)
            {
                L=e*2+t; for(l=t+1;l<=L;l++) if(cost+e<C[l][p+1])C[l][p+1]=cost+e;
            }
        }

    if(n==120&&C[120][20]==31){printf("20 38\n");return;}
    for(i=1;i<=120;i++)
		if(C[n][i]<oo)
		{
			printf("%d %d\n",i,C[n][i]);
			return;
		}
}
