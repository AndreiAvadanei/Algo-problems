#include<cstdio>
#include<vector>
#define MAXN 50005
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;
int N,M,x,y,state[MAXN];
vector<int> V;
vector<int> G[MAXN];
void read(),sort_top(),DF(int),show();
int main()
{
    read();
    sort_top();
    show();
    return 0;
}

void read()
{
    freopen("sortaret.in","r",stdin);
    freopen("sortaret.out","w",stdout);
    scanf("%d%d", &N,&M);
    for(;M;M--)
        scanf("%d%d",&x,&y),G[x].push_back(y);
}
void sort_top()
{
    for(int i=1;i<=N;i++)
        if(state[i]==WHITE)
            DF(i);
}
void DF(int node)
{
    vector<int>::iterator it;
    state[node]=GREY;
    for(it=G[node].begin();it!=G[node].end();it++)
        if(state[*it]==WHITE)
            DF(*it);
    state[node]=BLACK;
    V.push_back(node);
}
void show()
{
    vector<int>::reverse_iterator it;
    for(it=V.rbegin();it!=V.rend();it++)
        printf("%d ",*it);
}
