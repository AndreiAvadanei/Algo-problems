#include<cstdio>
#include<algorithm>
#define lld long long int
#define MAXN 2011
using namespace std;
lld V[MAXN],a[MAXN],a1[MAXN],a2[MAXN],*p,*p1,*p2,*tmp;
void read(),solve();
int n,i,j,Ln;
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("joculet.in","r",stdin);
	freopen("joculet.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld", &V[i]);
}
void solve()
{

	p=a;p1=a1;p2=a2;
	for(i=1; i<=n; i++) p2[i]=V[i];
	if(n==1){
	    printf("%lld",p2[1]);
	    return;
    }

	for(i=1;i<n;i++)
        p1[i]=max(max(V[i]-V[i+1],V[i+1]-V[i]),V[i]+V[i+1]);

	if(n==2){
	    printf("%lld",p1[1]);
        return;
    }

	for(Ln=3;Ln<=n;Ln++)
	{
		for(i=1,j=Ln;j<=n;i++,j++)
			p[i]=max(max(V[i]-p1[i+1],V[j]-p1[i]),V[i]+V[j]-p2[i+1]);
		tmp=p2;p2=p1;p1=p;p=tmp;
	}
	printf("%lld",p1[1]);
}
