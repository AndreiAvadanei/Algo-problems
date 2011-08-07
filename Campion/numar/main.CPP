#include<cstdio>
#include<algorithm>
using namespace std;
void init(),solve();
unsigned long long int n,nn,m,i,t,average,s,cnt,cntt,lim;
unsigned long long int A[100000];
int ccnt[15000+1];
int main()
{
    init();
    solve();
    return 0;
}
void init()
{
    freopen("numar.in","r",stdin);
    freopen("numar.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++) scanf("%lld",&A[i]),s+=A[i];
    //aflam o valoare medie pentru care toti multipli ar putea da in medie m valori unice
    //improbabil, dar fie :D

    average = (((s/n)+1)*m)/n;
    //printf("%lld %lld\n",average,s/n);
}
void solve()
{
    //pentru fiecare adaugam noduri
    nn=n;

    for(i=1;i<=n;i++)
    {
        t=A[i]; cnt=0;
        //trebuie imbunatatita probabilitatea fiindca average pe numere mici mananca o gramada de valori
        //m < 1000
        //m/(n/2.8) in caz contrar. :)

        do {
           t+=A[i];
           if(nn==100000-1)break;
           A[++nn]=t;
           cnt++;
         //  ccnt[A[i]]++;

        } while(t<=average && cnt <= (m<=1000?m:m/(n/2.8)));
    }


    sort(A+1,A+nn+1);//sortam
    int cnt=0;
   // for(i=1;i<1000000;i++)
        //if(ccnt[i]>0) printf("%lld %d\n",i,ccnt[i]);

    //cautam al m-lea numar unic si il afisam
    for(i=1;i<=nn;i++)
    {
        cnt++; t=A[i];
        if(m == cnt) {printf("%lld",t); break; }
        while(t==A[i+1] && i+1<=nn)i++;
    }
}
