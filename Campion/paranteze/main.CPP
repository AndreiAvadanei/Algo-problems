#include<cstdio>
#include<deque>
using namespace std;
int n,l,i,v;
deque<int> V;
void read();
int solve();
int main()
{
    read();
    return 0;
}
void read()
{
    freopen("paranteze.in","r",stdin);
    freopen("paranteze.out","w",stdout);
    for(scanf("%d",&n);n;n--)
    {
        scanf("%d",&l);
        printf("%d\n",solve());
    }
}
int solve()
{
    int state = 1;
    V.resize(0);
    for(i=1;i<=l;i++)
    {
        scanf("%d",&v);
        if(!state)continue;

        switch(v)
        {
            case 0:
                V.push_back(1);
                break;
            case 2:
                V.push_back(3);
                break;
            case 1:
            case 3:
                 if(!V.empty() && V.back()==v)
                    V.pop_back();
                else
                    state=0;
            break;
        }
    }
    if(!V.empty()) state=0;
    return state;
}
