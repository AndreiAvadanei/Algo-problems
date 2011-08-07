#include<cstdio>
#include<algorithm>
#define maxn 1<<17
using namespace std;
int n,v[maxn],poz[maxn],best[maxn],search(int),maxx;
void init(),solve(),show(int);
int main()
{
    init();
    solve();
    show(best[maxx]);
}
void init()
{
    freopen("scmax.in","r",stdin);
    freopen("scmax.out","w",stdout);

    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
}
void solve()
{
    int q;
    for(int i=1;i<=n;i++)
    {
        q=search(i);
        best[q+1]=i;
        maxx = max(maxx, q+1);
        poz[i]=best[q];
    }
    printf("%d\n",maxx);
}
int search(int pos)
{
    int l=0;
    for(int i=1<<17;i>0;i/=2)
        if(i+l <= maxx && v[best[i+l]]<v[pos])
            l+=i;
    return l;
}
void show(int p)
{
    if(p>0)
    {
        show(poz[p]);
        printf("%d ",v[p]);
    }
}
