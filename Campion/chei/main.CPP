#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 100000+5
using namespace std;
int n,i,a,u[MAXN],brk;
vector<int> G[MAXN];
void read(),dfs(int);
int main()
{
    read();
    return 0;
}
void read()
{
    freopen("chei.in","r",stdin);
    freopen("chei.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        G[i].push_back(a);
        G[a].push_back(i);
    }
    for(i=1;i<=n;i++)
        if(!u[i])
        {
            dfs(i);
            brk++;
        }
    printf("%d\n",brk);
}
void dfs(int node)
{
    vector<int>::iterator it;

    u[node]=1;
    for(it=G[node].begin();it!=G[node].end();it++)
        if(!u[*it])
            dfs(*it);
}
