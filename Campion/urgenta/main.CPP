#include<cstdio>
#include<algorithm>
#include<vector>
#define MAXM 33000+10
using namespace std;
int n,m,k,mm,nn,ans,X[MAXM],Y[MAXM],C[MAXM],GR[MAXM],ind[MAXM],group(int);
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
    freopen("urgenta.in","r",stdin);
    freopen("urgenta.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&X[i],&Y[i],&C[i]);
        ind[i]=i;
        ans+=C[i];
    }
    mm=m; nn=n;
}
void solve()
{
    if(n==k)
    {
        printf("%d\n%d\n",ans,mm);
        for(int i=1;i<=m;i++)printf("%d %d",X[i],Y[i]);
        return;
    }
    for(int i=1;i<=n;i++)GR[i]=i;
    sort(ind+1,ind+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(group(X[ind[i]])!=group(Y[ind[i]]))
        {
            ans-=C[ind[i]];
            C[ind[i]]=0;
            merge(X[ind[i]],Y[ind[i]]);
            mm--;nn--;
        }
        if(nn==k) break;
    }

    printf("%d\n%d\n",ans,mm);
    for(int i=1;i<=m;i++) if(C[ind[i]]) printf("%d %d\n",X[ind[i]],Y[ind[i]]);
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
