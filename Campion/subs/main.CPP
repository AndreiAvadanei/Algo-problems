//nu stiu d'astea.

#include<cstdio>
using namespace std;
int main()
{
    init();
    solve();
    return 0;
}
void init()
{
    freopen("subs.in","r",stdin);
    freopen("subs.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&v[i]),norm=min(v[i],norm); norm--;
    for(i=1;i<=n;i++)lst[i]=v[i]-norm;
    so
    for(i=2;i<=n;i++)update(1,1,n,i,v[i]-v[i-1]);
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        q=search(i);
        best[q+1]=i;
        if(maxx < q+1)
            maxx = q+1,minn=
    }
    printf("%d %d\n",maxx,minn);
}
