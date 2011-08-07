//arbore binar 1D
#include<cstdio>
#define MAXN 100000+10
using namespace std;
int n,m,i,v,act,a,b,A[MAXN],pp,search(int),query(int);
void solve(),update(int,int);
int main()
{
    solve();
    return 0;
}
void solve()
{
    freopen("aib.in","r",stdin);
    freopen("aib.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&v),update(i,v);
    for(pp=1;pp<n;pp<<=1);
    for(;m;m--)
    {
        scanf("%d",&act);
        if(act==0)scanf("%d%d",&a,&b),update(a,b);
        if(act==1)scanf("%d%d",&a,&b),printf("%d\n",query(b)-query(a-1));
        if(act==2)scanf("%d",&a),printf("%d\n",search(a));
    }
}
void update(int p,int val)
{
    for(;p<=n;p+= (p&-p))
        A[p]+=val;
}
int query(int p)
{
    int s=0;
    for(;p>0;p-=(p&-p))
        s+=A[p];

    return s;
}
int search(int v)
{
    int pt,i;
    for(pt=pp,i=0;pt>0;pt>>=1)
    {
        if(pt+i<=n && v>=A[pt+i])
        {
            v-=A[pt+i];i+=pt;
            if(!v)return i;
        }
    }
    return -1;
}
