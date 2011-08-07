#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int> >V,U;
int B,F,K,i,j,n,b,f,M[1005][1005];
void show(),solve();
int use(int,int);
int main()
{
    solve();
    show();
    return 0;
}
void solve()
{
    freopen("cazare.in","r",stdin);
    freopen("cazare.out","w",stdout);
    scanf("%d%d%d",&B,&F,&n);
    int len,bb,ff;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&b,&f);
        V.push_back(make_pair(b,f));
        len = U.size();
        for(j=0;j<len;j++)
        {
            bb=U[j].first+b;
            ff=U[j].second+f;
            if(bb > B || ff > F)continue;
            if(!M[bb][ff])
            {
                U.push_back(make_pair(bb,ff));
                M[bb][ff]=i;
            }
            if(bb==B && ff==F)return;
        }

        if(use(b,f)) return;
    }
}
void show()
{
    int c=0,ind; short sol[1005];

    while(B||F)
    {
        ind = M[B][F];
        sol[c++]=ind;
        B-=V[ind-1].first;
        F-=V[ind-1].second;
    }

    printf("%d\n",c);
    for(i=c-1;i>=0;i--) printf("%d\n",sol[i]);
}
inline int use(int bb,int ff)
{
    if(bb > B || ff > F)return 0;
    if(!M[bb][ff])
    {
        U.push_back(make_pair(bb,ff));
        M[bb][ff]=i;
    }
    if(bb==B && ff==F)
        return 1;
    return 0;
}
