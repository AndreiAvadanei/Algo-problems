#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 8000
using namespace std;
int n,m,x,y,i,a,b,nr,dx[MAXN],dy[MAXN],cnt[MAXN],sol[MAXN],vv[MAXN];
vector<int> G[MAXN];
queue<int> Q;
void init(),solve(),bfs(int,int[]);
int main()
{
    init();
    solve();
    return 0;
}
void init()
{
    freopen("graf.in","r",stdin);
    freopen("graf.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&x,&y);
    //construim graf neorientat
    for(i=1;i<=m;i++)
        scanf("%d%d",&a,&b),G[a].push_back(b),G[b].push_back(a);
}
void solve()
{
    bfs(x, dx);//bfs pornind din x pentru toate nodurile
    bfs(y, dy);//bfs pornind din y pentru toate nodurile

    /*ne bazam pe observatia :
        Dacă definim distanţa între două vârfuri ale unui graf neorientat ca fiind lungimea celui mai scurt lanţ dintre care are drept capete vârfurile,
        atunci putem să observăm că un vârf oarecare Z se află pe un lanţ de lungime minima dintre X şi Y dacă şi numai dacă d(X,Z)+d(Z,Y)=d(X,Y) ,
         pentru cazul în care considerăm lungimea lanţului ca fiind numărul muchiilor şi d(X,Z)+d(Z,Y)=d(X,Y)+1,
         pentru cazul în care considerăm lungimea ca fiind numărul vârfurilor.

    */

    for(i=1;i<=n;i++)
        if(dx[i]+dy[i]==dx[y]+1)
            cnt[dx[i]]++,vv[dx[i]]=i;
    //cautam nodurile care sunt singurele aflate la o distanta de X (si mai sus)
    for(i=1;i<=n;i++)
        if(cnt[i]==1)
            nr++,sol[vv[i]]=1;
    //sol
    printf("%d\n",nr);
    for(i=1;i<=n;i++)
        if(sol[i]) printf("%d ",i);
}
void bfs(int v, int d[])
{
    int len,c;
    vector<int>::iterator it;
    d[v]=1;
    Q.push(v);
    while(Q.size())
    {
        len = Q.size();
        for(i=1;i<=len;i++)
        {
            c = Q.front(); Q.pop();
            for(it=G[c].begin();it!=G[c].end();it++)
            {
                if(!d[*it])
                    Q.push(*it),d[*it]=d[c]+1;
            }
        }
    }
}
