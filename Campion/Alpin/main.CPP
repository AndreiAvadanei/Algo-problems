#include<cstdio>
#define MAXN 1030
using namespace std;
void read(),solve(),DF(int,int);
int sx,sy,n,i,j,dmax,state[MAXN][MAXN],a[MAXN][MAXN],d[MAXN][MAXN],dx[]={-1,1,0,0},dy[]={0,0,-1,1};

int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("alpin.in","r",stdin);
    freopen("alpin.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
}
void solve()
{
    dmax = -1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(!d[i][j])
                DF(i,j);

    printf("%d\n%d %d\n",dmax,sx,sy);
    for(--dmax;dmax;dmax--)
        for(i=0;i<4;i++)
            if(d[sx+dx[i]][sy+dy[i]]==dmax)
                printf("%d %d\n",sx+dx[i],sy+dy[i]),sx+=dx[i],sy+=dy[i];
}
void DF(int x,int y)
{
    if(state[x][y])return;
    d[x][y]=1;
    for(int k=0;k<4;k++)
    {
        if(a[x][y]<a[x+dx[k]][y+dy[k]])
        {
            if(!state[x+dx[k]][y+dy[k]])
                DF(x+dx[k],y+dy[k]);
            if(d[x+dx[k]][y+dy[k]]+1>d[x][y])
                d[x][y]=d[x+dx[k]][y+dy[k]]+1;
        }
    }
    state[x][y]=1;
    if(d[x][y]>dmax) dmax=d[x][y],sx=x,sy=y;
}
