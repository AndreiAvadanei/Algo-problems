#include<cstdio>
#include<queue>
#include<vector>
#define INF 2<<15
#define MAXN 400000+10
using namespace std;
vector<int> G[MAXN];
queue<int> Q;
int i,n,x,y,d[MAXN],u[MAXN],dt[MAXN],s,m,st;
void read(),solve(),bfs(),act(int);
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("tractomarm.in","r",stdin);
    freopen("tractomarm.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<n;i++)
        scanf("%d%d",&x,&y),G[x].push_back(y),G[y].push_back(x);
}
void solve()
{
    bfs();
    for(i=2;i<=n;i++)s+=d[i];
    scanf("%d",&m);
    for(;m;m--)
    {
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        st=s;
        for(int j=1;j<=n;j++) dt[j]=d[j];
        act(x);
        act(y);
        printf("%d\n",st);
        G[x].pop_back();
        G[y].pop_back();
    }
}

void bfs()
{
    vector<int>::iterator it;
    Q.push(1);u[1]=1;
    while(Q.size())
    {
        int c=Q.front();
        for(it=G[c].begin();it!=G[c].end();it++)
        {
            if(u[*it]) continue;
            u[*it]=1;Q.push(*it);
            if(!d[*it]||d[*it]>d[c]+1)
              d[*it]=d[c]+1;
        }
        Q.pop();
    }
}
void act(int se)
{
    vector<int>::iterator it;
    for(i=1;i<=n;i++)u[i]=0;
    Q.push(1);u[0]=u[1]=1;
    while(Q.size())
    {
        int c=Q.front();
        for(it=G[c].begin();it!=G[c].end();it++)
        {
            if(u[*it])continue;
            u[*it]=1;
                Q.push(*it);
            if(dt[*it]>dt[c]+1)
            {
                dt[*it]=dt[c]+1;
                st-=(d[*it]-dt[*it]);
            }
            if(*it==se){while(Q.size())Q.pop(); return;}
        }
        Q.pop();
    }
}
