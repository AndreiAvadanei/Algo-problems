#include<cstdio>
#define MAXP 100100
using namespace std;
long long p,q,i,j,c,n,I[MAXP],F[MAXP],inv[MAXP],A,B,C,sol,a[500],b[500],x[500],y[500];
void read(),solve(),i_modular();
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("jap2.in","r",stdin);
    freopen("jap2.out","w",stdout);
    scanf("%lld%lld",&p,&q);
}
void solve()
{
    i_modular();
    I[0]=F[0]=1;for(i=1;i<=p;i++)F[i]=(F[i-1]*i)%p,I[i]=inv[F[i]];//calculam factorial && inversul modular
    for(;q;q--)
    {
        scanf("%lld%lld",&A,&B);C=A-B;//citim
        a[0]=0;i=0;for(;A;A/=p)a[0]+=A/p,a[++i]=F[A%p];//factorii lui a
        b[0]=0;j=0;for(;B;B/=p)b[0]+=B/p,b[++j]=I[B%p];//factorii lui b
                   for(;C;C/=p)b[0]+=C/p,b[++j]=I[C%p];//factorii lui a-b
        if(a[0]>b[0]){printf("0\n");continue; }//N%p=0
        sol=1;
        for(;i;i--)sol=(sol*a[i])%p;//calculam solutia
        for(;j;j--)sol=(sol*b[j])%p;
        printf("%lld\n",sol);
    }
}
void i_modular()
{
    for(i=1;i<=p;i++)//pentru fiecare i<=p
    {
        if(inv[i])continue;
        a[1]=i; b[1]=p;//calculam inversul modular al lui i
        c=1,j=1;
        for(;b[j];j++)
        {
            a[j+1]=b[j];
            b[j+1]=a[j]%b[j];
        }
        n=j;
        x[n]=c/a[n];y[n]=0;
        for(j=n-1;j>=1;j--)
		{
			x[j]=y[j+1];y[j]=x[j+1]-(a[j]/b[j])*y[j+1];
		}
        //normalizam
        while(x[1]>=p)x[1]-=p;
        while(x[1]<0)x[1]+=p;
        inv[i]=x[1];inv[inv[i]]=i;//adaugam i, inv[i],p-i,inv[p-i]
        inv[p-i]=p-inv[i];inv[inv[p-i]]=p-i;
    }
}
