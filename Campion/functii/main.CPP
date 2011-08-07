//C(n,k)%p = n! * k!(n-k)! = n! * k!^ * (n-k)!^, unde x^ = invers modular
//C(n,k)= n!/k!*(n-k)! = n!/( (k-1)!*(n-k+1)! )   * (n-k+1)/k = C(n,k-1) * (n-k+1)/k
#include<cstdio>
using namespace std;
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("functii.in","r",stdin);
    freopen("functii.out","w",stdout);
    scanf("%d%d",n,s);

}
