#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define mp make_pair
#define INF 1<<20
#define MAXN 36010
using namespace std;
int n,m,k,a,b,c,i,D[MAXN],v[MAXN],u[MAXN],unde[MAXN];
void read(),solve();
vector<pair<int,int> > G[MAXN];
vector<int> C;
queue<int> Q;
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("catun.in","r",stdin);
	freopen("catun.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i++)scanf("%d",&a),C.push_back(a);
	for(i=1;i<=m;i++)scanf("%d%d%d",&a,&b,&c),G[a].push_back(mp(b,c)),G[b].push_back(mp(a,c));
}
void solve()
{
	int node,nnode,tmp;
	vector<pair<int,int> >::iterator it;
	for(i=1;i<=n;i++)D[i]=INF;
	sort(C.begin(),C.end());
	for(i=0;i<k;i++)Q.push(C[i]),D[C[i]]=0,v[C[i]]=u[C[i]]=1,unde[C[i]]=C[i];


	while(!Q.empty())
	{
		node = Q.front(); Q.pop();
		v[node]=0;
		for(it=G[node].begin();it!=G[node].end();it++)
		{
			nnode = it->first;
			tmp = it->second;
			if(D[nnode] > D[node]+it->second||(D[nnode]==D[node]+it->second&&unde[nnode]>unde[node]))
			{
			    unde[nnode]=unde[node];
				D[nnode] = D[node]+it->second;
				if(!v[nnode])
				{
					v[nnode]=1;
					if(u[nnode]>n)return; //avem ciclu negativ(desi aici nu e cazul)
					u[nnode]++;
					Q.push(nnode);
				}
			}
		}
	}

	for(i=1;i<=n;i++)
		printf("%d ",(D[i]&&D[i]!=INF&&unde[i])?unde[i]:0);
}
