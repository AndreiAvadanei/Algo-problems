#include<cstdio>
#define maxn 2000
using namespace std;
int x,y,z,t,ti,tf,ntA,op,ntB,t1,t2,nS,TA[maxn],TB[maxn],tsA[maxn],tsB[maxn],csA[maxn],csB[maxn],solA[maxn],solB[maxn];
void init(),solve();
int main()
{
    init();
    solve();
    return 0;
}
void init()
{
    freopen("litoral.in","r",stdin);
    freopen("litoral.out","w",stdout);
    scanf("%d%d",&x,&y); ti=x*60+y;
    scanf("%d%d",&x,&y); tf=x*60+y;
    scanf("%d%d",&ntA,&ntB);
    //TA = taxele lui A
    //TB = taxele lui B
    while(ntA--)scanf("%d%d%d",&x,&y,&z),TA[60*x+y]=z;
    while(ntB--)scanf("%d%d%d",&x,&y,&z),TB[60*x+y]=z;
    scanf("%d",&nS);
    //tsA, tsB = orarul salupelor
    //csA, csB = costurile salupelor
    while(nS--)
    {
        scanf("%d",&op);
        if(!op)
        {
            scanf("%d%d",&x,&y);t1=x*60+y;
            scanf("%d%d",&x,&y);t2=x*60+y;
            scanf("%d",&z);
            tsA[t1]=t2;csA[t1]=z;
            continue;
        }
        scanf("%d%d",&x,&y);t1=x*60+y;
        scanf("%d%d",&x,&y);t2=x*60+y;
        scanf("%d",&z);
        tsB[t2]=t1;csB[t2]=z;
    }
}
void solve()
{
    for(t=ti;t<=tf;t++)solA[t]=solB[t]=1<<25;
    solA[ti]=0;
    //don't ask :|
    for(t=ti;t<tf;t++)
    {
        solA[t]+=TA[t],solB[t]+=TB[t];
		solA[t+1]=solA[t+1]<solA[t]?solA[t+1]:solA[t];
		solB[t+1]=solB[t+1]<solB[t]?solB[t+1]:solB[t];

        if(tsA[t] && solB[tsA[t]]>solA[t]+csA[t])
				solB[tsA[t]]=solA[t]+csA[t];
		if(tsB[t] && solA[tsB[t]]>solB[t]+csB[t])
				solA[tsB[t]]=solB[t]+csB[t];
    }

    printf("%d\n",(solB[tf]+TB[tf]));
}

