#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 100000+5
using namespace std;
int n,m,i,a,b,u[MAXN],brk2;
vector<int> G[MAXN];
void read(),dfs(int);
int main()
{
    read();
    return 0;
}
void read()
{
    freopen("dfs.in","r",stdin);
    freopen("dfs.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        G[b].push_back(a);
        G[a].push_back(b);
    }
    for(i=1;i<=n;i++)
        if(!u[i])
        {
            dfs(i);
            brk2++;
        }
    printf("%d\n",brk2);
}
void dfs(int node)
{
    vector<int>::iterator it;

    u[node]=1;
    for(it=G[node].begin();it!=G[node].end();it++)
        if(!u[*it])
            dfs(*it);
}
