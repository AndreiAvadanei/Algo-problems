#include<cstdio>
#define llong long long
using namespace std;

llong inv, t;
int a,b;
void gcd(llong&, llong&, int,int,int);
int main()
{
    freopen("inversmodular.in","r",stdin);
    freopen("inversmodular.out","w",stdout);
    scanf("%d%d",&a,&b);

    gcd(inv,t,a,b,1);
    if(inv<=0)
        inv = b + inv % b;
    printf("%lld\n", inv);
    return 0;
}

void gcd(llong &a, llong &b, int x, int y,int step)
{

    if(!y)
        a=1,b=0;
    else
    {
        gcd(a, b, y, x%y,step+1);
        llong t = a;
        a = b;
        b = t-b*(x/y);
        //sprintf("!(%d)%lld %lld - %d %d\n",step,a,b,x,y);
    }
}
