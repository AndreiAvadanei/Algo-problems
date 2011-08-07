#include<cstdio>
using namespace std;
int main()
{
    init();
    solve();
    return 0;
}
void init()
{
    freopen("bile.in","r",stdin);
    freopen("bile.out","w",stdout);
    scanf("%d",&n);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            RN[i][j]=4;
            V[i][j]=15;//1111
        }
    for(i=1;i<=n;i++)RN[1][i]=3,V[1][i]=7; //setam ca avand doar N,V,E - 1101
    for(i=1;i<=n;i++)RN[n][i]=3,V[n][i]=13;//setam ca avand doar S,V,E - 0111
    for(i=1;i<=n;i++)RN[i][1]=3,V[i][1]=14;//setam ca avand doar S,N,E - 1110
    for(i=1;i<=n;i++)RN[i][n]=3,V[i][n]=11;//setam ca avand doar N,S,V - 1011
    //setam cazurile particulare

    RN[0][0]=RN[n][n]=RN[0][n]=RN[n][0]=2;
}
void solve()
{

}
