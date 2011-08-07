#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;
deque<int> D;
int n,k,i,a,b,m,v[1000000+5];
void init(),solve();
int main()
{
    init();
    solve();
    return 0;
}
void init()
{
    freopen("knumere.in","r",stdin);
    freopen("knumere.out","w",stdout);
    scanf("%d%d%d",&n,&k,&a);

    for(i=2;i<=n;i++)scanf("%d",&b),v[i-1]=b-a,a^=b^=a^=b;
}
void solve()
{
    b=n-k-1;m=1<<20;

    for(i=1;i<n;i++)
    {
        while(!D.empty() && v[D.back()]<=v[i])D.pop_back();
        D.push_back(i);

        if(D.front()==i-b)D.pop_front();
        if(i>=b)m=min(m,v[D.front()]);
    }
    printf("%d\n",m);
}
