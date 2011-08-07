#include<cstdio>
#include<cstring>
#define LMAX 510
typedef int BIG[LMAX];
using namespace std;
void dif(BIG),div(BIG,BIG,BIG,BIG),readd(BIG),dif2(BIG,BIG,BIG),read(),solve(),pp(BIG,int);
int cmp(BIG,BIG),t,cnt;
int main()
{
    read();
    return 0;
}
void read()
{
    freopen("doi.in","r",stdin);
    freopen("doi.out","w",stdout);

    scanf("%d",&t);
    for(;t;t--)
        solve();
}
void solve()
{
    BIG nr,nrdiv,nrr,nrrr;
    nrdiv[0]=1;nrdiv[1]=2;

    readd(nr);
    cnt = 0;
    while(nr[nr[0]]!=0)
    {
        if(nr[1]%2)
            dif(nr);
        else
        {
            div(nr,nrdiv,nrrr,nrr);
            for(int i=0;i<=nrrr[0]+10;i++)
                nr[i]=nrrr[i];
        }
        cnt++;
    }
    printf("%d\n",cnt);
}
void readd(BIG x)
{
     int i;
     char s[LMAX];
     scanf("%s",s);
     x[0] = strlen(s);
     for(i = x[0]-1; i >= 0; i--) x[x[0]-i] = s[i]-'0';
     for(i = x[0]+1; i < LMAX; i++) x[i] = 0;
}
void dif(BIG nr)
{
    int t = -1;
    for(int i=1;i<=nr[0];i++)
    {
        nr[i]+=t;
        if(nr[i]<0)nr[i]+=10,t=-1;
        else { t=0; break; }
        i--;
        while(i >= 1 && !nr[i]) i--;
        nr[0] = i;
    }
}
void div(BIG a,BIG b,BIG c,BIG r)
{
     int i;
     r[0] = 0; c[0] = a[0];
     for(i = a[0]; i >= 1; i--)
     {
        pp(r,1); r[1] = a[i];
        c[i] = 0;

        while(cmp(b,r) != 1)
        {
           c[i]++;
           dif2(r,b,r);
        }
     }
     while(!c[c[0]] && c[0] > 1) c[0]--;
     while(!r[r[0]] && r[0] > 1) r[0]--;
}
void pp(BIG x,int nr)
{
     int i;
     for(i = x[0]; i >= 1; i--) x[i+nr] = x[i];
     for(i = 1; i <= nr; i++) x[i] = 0;
     x[0] += nr;
}
void dif2(BIG a,BIG b,BIG d)
{
     int i,t = 0;
     if(a[0] < b[0]) dif2(b,a,d);
     else { for(i = 1; i <= a[0]; i++)
       {
           d[i] = a[i]-b[i]+t;
           if(d[i] < 0) d[i]+= 10,t = -1;
           else t = 0;
        }
        i--; while(i >= 1 && !d[i]) i--; d[0] = i;
     }
}
int cmp(BIG a,BIG b)
{
   int i;

   if(a[0] < b[0]) return -1;
   if(a[0] > b[0]) return  1;
   for(i = a[0]; i >= 1 && a[i] == b[i]; i--) ;
   if(i < 1) return 0; if(a[i] < b[i]) return -1; return 1;
}
