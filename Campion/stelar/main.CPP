#include<cstdio>
#include<algorithm>
#include<vector>
#define X first
#define Y second.first
#define Z second.second
using namespace std;
int n,i,a,b,c,j,dmax,dt,bi,bj;
vector<pair<int,pair<int,int> > > V;
void read(),solve();
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("stelar.in","r",stdin);
    freopen("stelar.out","w",stdout);
    scanf("%d",&n);
    V.push_back(make_pair(0,make_pair(0,0)));
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        V.push_back(make_pair(a,make_pair(b,c)));
    }
}
void solve()
{
    dmax = abs(V[1].X-V[2].Y)+abs(V[1].Y-V[2].Z)+abs(V[1].Z-V[2].X);
    bi=1;bj=2;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j)
            {
                dt = abs(V[i].X-V[j].Y)+abs(V[i].Y-V[j].Z)+abs(V[i].Z-V[j].X);
               // printf("%d %d %d %d %d\n",i,j,V[i].X-V[j].Y,V[i].Y-V[j].Z,V[i].Z-V[j].X);
                if(dt>dmax) dmax=dt,bi=i,bj=j;
            }
    printf("%d %d\n",bi,bj);
}
