#include<cstdio>
#define MAXN 10000000/2+1
using namespace std;
int dif,a,b,i,j,first=-1,second=-1,solfirst=-1,solsecond=-1,dift;
char ciur[MAXN];
void init();
int main()
{
    init();
    return 0;
}
void init()
{
    freopen("difprim.in","r",stdin);
    freopen("difprim.out","w",stdout);
    scanf("%d%d", &a,&b);
    if(a<=2)first=2;
    for(i=1;(i<<1)+1<=b;i++)
        if(!ciur[i])
        {
            ciur[i]=1;
            if(i*2+1>=a)
            {
                if(first==-1)first=i;
                else if(second==-1)second=i;
                if(first!=-1&&second!=-1)
                {
                    //printf("%d %d\n",first*2+1,second*2+1);
                    dift=(second*2+1)-(first*2+1);

                    if(dift>dif)dif=dift,solfirst=first,solsecond=second;
                    first=second;second=-1;
                }
            }
            for(j=3*i+1;(j<<1)+1<=b;j+=(i<<1)+1)
                ciur[j]=1;
        }
    if(solfirst!=-1 && solsecond !=-1)
        printf("%d %d\n",solfirst*2+1,solsecond*2+1);
    else
        printf("-1\n");
}
