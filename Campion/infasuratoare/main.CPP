//scanarea Graham
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#define mp make_pair
#define X first
#define Y second
#define oo 1000000000
#define MAXN 120000
using namespace std;
int n,init,i,IND[MAXN],ST[MAXN];
double a,b;
vector<pair<double,double> > V;
void solve();
int main()
{
    solve();
    return 0;
}

bool cmpf(int i,int j)
{
    return (double)(V[i].X - V[init].X) * (V[j].Y - V[init].Y) < (double)(V[j].X - V[init].X) * (V[i].Y - V[init].Y);
}
long double sign(int i1,int i2,int i3)
{
    return (long double)V[i1].X * V[i2].Y + V[i2].X * V[i3].Y + V[i3].X * V[i1].Y - V[i1].Y * V[i2].X - V[i2].Y * V[i3].X - V[i3].Y * V[i1].X;
}
void solve()
{
    freopen("infasuratoare.in","r",stdin);
    freopen("infasuratoare.out","w",stdout);
    scanf("%d",&n);
    V.push_back(mp(oo,oo)); init=0;
    //caut cel mai din stanga si mai de jos punct
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf",&a,&b);
        V.push_back(mp(a,b));
        if(a<V[init].X || (a==V[init].X && b<V[init].Y)) init = i;
    }
    for(i=1;i<=n;i++) if(i!=init) IND[++IND[0]]=i;

    sort(IND+1,IND+IND[0]+1,cmpf);//sortam punctele in ordine crescatoare dupa panta dreptei dintre init si restul punctelor
    ST[++ST[0]]=init;
    for(i=1;i<=IND[0];i++)
    {
        if(IND[i]==init)continue;
        //eliminam toate punctele din stiva care formeaza cu dreapta (ultimile doua puncte) unghi mai mare de 180grade
        while(ST[0]>=2 && sign(ST[ST[0]-1],ST[ST[0]],IND[i])>0) ST[0]--;
        ST[++ST[0]]=IND[i]; //adaugam punctul in stiva
    }
    ST[++ST[0]]=init;
    printf("%d\n",ST[0]-1); //numarul de puncte din infasuratoarea convexa
    //punctele ce apartin infasuratorii convexe
    reverse(ST + 1, ST + ST[0] + 1);
    for(i = 1;i < ST[0]; ++i)
        printf("%lf %lf\n",V[ST[i]].X,V[ST[i]].Y);
}
