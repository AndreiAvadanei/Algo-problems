#include<cstdio>
#define MAXN 100000+10
using namespace std;
int n,m,i,act,x,y,A[MAXN],R[MAXN],search(int);
void read(),unite(int,int),search();
int main()
{
    read();
    return 0;
}
void read()
{
    freopen("disjoint.in","r",stdin);
    freopen("disjoint.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)A[i]=i,R[i]=1;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&act,&x,&y);
        if(act==1)unite(x,y);
        if(act==2)printf("%s\n",search(x)==search(y)?"DA":"NU");
    }
}
void unite(int a,int b)
{
    a=search(a);
    b=search(b);
    //reuniune dupa rang
    if(R[a]>R[b]) A[b]=a,R[a]+=R[b];
    else A[a]=b,R[b]+=R[a];
}
int search(int v)
{
    int tmp,R;
    for(R=v;R!=A[R];R=A[R]);
    while(v!=A[v])//compresia drumurilor
        tmp=A[v],A[v]=R,v=tmp;
    return R;
}
