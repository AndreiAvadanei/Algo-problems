#include<cstdio>
using namespace std;
int n,n2,k,i,A[1048576],sol[50];
void read(),solve(),up(int);
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("arbgraf.in","r",stdin);
    freopen("arbgraf.out","w",stdout);

    scanf("%d%d",&n,&k);
    n2 = (1<<n)-1;
    for(i=1;i<(1<<n);i++)
        scanf("%d",&A[i]),n2-=!A[i];
}
void solve()
{
    int stk = (1<<(n-1)),lvl=n,lung,sc,sn=0,d=1;

    while(k||!A[stk])
    {
        if(A[stk])A[stk]=0,up(stk),k--,n2--;
        stk++;
    }

    while(lvl)
    {
        if(d>0)
        {
            for(i=(1<<(lvl-1));i<(1<<lvl);i+=d)
                if(A[i])sol[++sn]=A[i];
        }
        else
        {

            for(i=(1<<lvl)-1;i>=(1<<(lvl-1));i+=d)
                if(A[i])sol[++sn]=A[i];
        }
        d*=-1;lvl--;
    }
    for(i=1,sc=1,d=0,lung=1;i<=sn;i++,sc++)
    {
      A[i]=sc;d+=lung;
      if(!((sc+1)%10))sc*=10,lung++;
    }
    printf("%d %d %d\n",n2,sn-1,d);
    for(i=1;i<=sn;i++)
      printf("%d %d\n",sol[i],A[i]);
}
void up(int nod)
{
    int dad = nod / 2;
    if(!dad)return;
    if(A[dad] && !A[dad*2] && !A[dad*2+1])
        A[dad]=0,n2--,up(dad);
}
