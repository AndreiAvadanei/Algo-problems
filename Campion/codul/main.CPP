#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n1,n2,i,j,C[300][300],k,*x,*y,*X,*Y,*aux,L,LT,LN,sx[300],sy[300],SX[300],SY[300];
char s1[300],s2[300],sol[300];
vector<pair<int,pair<int,int> > > LL[300];
vector<pair<int,pair<int,int> > >::iterator it;
void read(),solve();
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("codul.in","r",stdin);
    freopen("codul.out","w",stdout);

    scanf("%s%s",s1,s2);
}
void solve()
{
    n1=strlen(s1); n2=strlen(s2);
    for(i=n1-1;i>=0;i--)
        for(j=n2-1;j>=0;j--)
            if(s1[i]==s2[j])
                C[i][j]=1+C[i+1][j+1],LL[C[i][j]].push_back(make_pair(s1[i]-'0',make_pair(i,j)));
            else
                C[i][j]=max(C[i+1][j],C[i][j+1]);

    k = C[0][0]; LT = 1;
    x=sx;y=sy;X=SX;Y=SY;
    x[1]=y[1]=-1;
    for(L=k;L;L--)
    {
        sol[L]=-1;
        for(it=LL[L].begin();it!=LL[L].end();it++)
        {
            if(sol[L]>it->first)continue;
            for(i=1;i<=LT;i++)
            {
                if(it->second.first<=x[i])continue;
				if(it->second.second<=y[i])continue;
                if(sol[L]==it->first)
				{
					X[++LN] = it->second.first;
					Y[LN]   = it->second.second;
					break;
				}
                sol[L]=it->first;
                LN = 1;
                X[LN]=it->second.first;
				Y[LN]=it->second.second;
				break;
            }
        }
        aux=x;x=X;X=aux;
        aux=y;y=Y;Y=aux;
        LT = LN; LN = 0;
    }

   for(i=k;i>=1;i--)printf("%d",sol[i]); printf("\n");
}
