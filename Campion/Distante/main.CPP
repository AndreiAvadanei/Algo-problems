#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define oo 1<<20
#define mp make_pair
#define MAXN 50005
using namespace std;
int T,n,m,s,i,a,b,c,D[MAXN],Dmi[MAXN],v[MAXN],u[MAXN];
vector<pair<int, int> > C[MAXN];
queue<int> Q;
void read(),bford();
int main()
{
    freopen("distante.in","r",stdin);
    freopen("distante.out","w",stdout);
    scanf("%d",&T);
    for(;T;T--)
        read(),bford();
    return 0;
}
void read()
{
    scanf("%d%d%d",&n,&m,&s);
    for(i=1;i<=n;i++)scanf("%d",&Dmi[i]);
    for(i=1;i<=m;i++)scanf("%d%d%d",&a,&b,&c),C[a].push_back(mp(b,c)),C[b].push_back(mp(a,c));
}
void bford()
{
    int node, nnode;
    vector<pair<int,int> >::iterator it;
    for(i=1;i<=n;i++)D[i]=oo,v[i]=0,u[i]=0;
    Q.push(s);
    v[s]=u[s]=1;D[s]=0;

    while(!Q.empty())
    {
        node = Q.front();Q.pop();
        v[node]=0;
        for(it=C[node].begin();it!=C[node].end();it++)
        {
            nnode = it->first;
            if(D[nnode]>D[node]+it->second)
            {
                D[nnode]=D[node]+it->second;
                if(!v[nnode])
                {
                    v[nnode]=1;
                    if(u[nnode]>n)return;
                    u[nnode]++;
                    Q.push(nnode);
                }
            }
        }
    }
    for(i=1;i<=n;i++)C[i].resize(0);
    for(i=1;i<=n;i++)
        if(D[i]!=Dmi[i])
            {printf("NU\n");return;}
    printf("DA\n");
}
