#include<cstdio>
#include<algorithm>
#include<vector>
#define MAXM 400000+10
using namespace std;
int n,m,ans,X[MAXM],Y[MAXM],C[MAXM],GR[MAXM],ind[MAXM],group(int);
vector<int> Vsol;
void read(),solve(),merge(int,int);
bool cmp(int,int);
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("apm.in","r",stdin);
    freopen("apm.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&X[i],&Y[i],&C[i]);
        ind[i]=i;
    }
}
void solve()
{
    for(int i=1;i<=n;i++)GR[i]=i;
    sort(ind+1,ind+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(group(X[ind[i]])!=group(Y[ind[i]]))
        {
            ans+=C[ind[i]];
            merge(X[ind[i]],Y[ind[i]]);
            Vsol.push_back(ind[i]);
        }
    }

    printf("%d\n%d\n",ans,n-1);
    for(int i=0;i<n-1;i++) printf("%d %d\n",X[Vsol[i]],Y[Vsol[i]]);
}
bool cmp(int i1,int i2)
{
    return (C[i1]<C[i2]);
}
int group(int i)
{
    if(GR[i]==i)return i;
    GR[i]=group(GR[i]);
    return GR[i];
}
void merge(int i,int j)
{
    GR[group(i)]=group(j);
}
