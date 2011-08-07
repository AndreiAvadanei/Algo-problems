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
    freopen("fsb.in","r",stdin);
    freopen("fsb.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%c",&c),v[i]=c-'0';
}
