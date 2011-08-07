#include <cstdio>
#define det1 (Xa * Yb + Xb * Yp + Xp * Ya - Xp * Yb - Xa * Yp - Xb * Ya)
#define det2 (Xb * Yc + Xc * Yp + Xp * Yb - Xp * Yc - Xb * Yp - Xc * Yb)
#define det3 (Xc * Ya + Xa * Yp + Xp * Yc - Xp * Ya - Xc * Yp - Xa * Yc)
int Q,Xa,Xb,Xc,Xp,Ya,Yb,Yc,Yp;
void _read(),_solve();
int main()
{
    _read();
    _solve();
    return 0;
}
void _read()
{
    freopen("qtri.in","r",stdin);
    freopen("qtri.out","w",stdout);
    scanf("%d",&Q);
}
void _solve()
{
    for(int i = 0;i < Q;i++)
    {
        scanf("%d%d%d%d%d%d%d%d",&Xa,&Ya,&Xb,&Yb,&Xc,&Yc,&Xp,&Yp);
        if(det1 < 0 && det2 < 0 && det3 < 0 || det1 >= 0 && det2 >= 0 && det3 >= 0)
            printf("DA\n");
        else
            printf("NU\n");
    }
}
