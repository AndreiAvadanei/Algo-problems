#include<cstdio>
struct nod {
    nod* c[2];
    int cnt;
} *root;
using namespace std;
void init(),solve(),update(int,nod*,int);
int n,i,q,j,r,k,nr,query(int, nod*, int,int);
int main()
{
    init();
    solve();
    return 0;
}
void init()
{
    freopen("rk.in","r",stdin);
    freopen("rk.out","w",stdout);
    scanf("%d",&n);
    root = new nod;root->cnt=0;root->c[0]=root->c[1]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&nr);
        update(nr,root,0);
    }
    scanf("%d",&q);
}
void solve()
{
    for(;q;q--)
    {
        scanf("%d%d",&r,&k);
        printf("%d\n",query(r,root,k,0));
    }
}
void update(int p, nod *Nr, int lvl)
{
    int child;nod *aux;
    Nr->cnt++;
    if(lvl==31)return;
    child = p&1;
    if(!Nr->c[child])
    {
        aux = new nod;
        aux->cnt=0;
        aux->c[0]=aux->c[1]=0;
        Nr->c[child]=aux;
    }
    update(p>>1,Nr->c[child],lvl+1);
}
int query(int p, nod *Nr, int l, int lvl)
{
    int child;
    if(lvl==l)return Nr->cnt;
    child=p&1;
    if(!Nr->c[child])return 0;
    return query(p>>1, Nr->c[child],l,lvl+1);
}
