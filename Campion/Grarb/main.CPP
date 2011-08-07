#include<cstdio>
#include<vector>
using namespace std;
vector<int> G[100010];
int n,m,i,a,b,viz[100010],cc;
void read(),solve(),dfs(int);
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("grarb.in","r",stdin);
	freopen("grarb.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);

		G[a].push_back(b);
		G[b].push_back(a);
	}
}
void solve()
{
	for(i=1;i<=n;i++)
		if(!viz[i])
		{
            cc++;
            dfs(i);
		}

	printf("%d\n",cc+m-n);
	printf("%d\n",cc-1);
}
void dfs(int p)
{
	vector<int>::iterator it;
    viz[p]=1;
    for(it=G[p].begin();it!=G[p].end();it++)
        if(!viz[*it])
            dfs(*it);
}
