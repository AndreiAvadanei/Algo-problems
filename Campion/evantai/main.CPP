#include<cstdio>
using namespace std;
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&v[i]);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
             if(i==j)continue;
             update(i,j,v[i]+v[j]);
        }
}
void solve()
{
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(i==j)continue;

        }
}
