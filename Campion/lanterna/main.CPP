#include<cstdio>
#include<queue>
#include<vector>
#define MAXN 51
#define MAXK 1100+1
#define oo 30000+1
#define mp make_pair
using namespace std;
int n,k,i,m,a,b,T,W,st,dr,mijl,tok,tmin,node,charge,tN,p,j,s[MAXN],u[MAXN],D[MAXN][MAXK],v[MAXN][MAXK];
vector<pair<int, pair<int,int> > > G[MAXN];
vector<pair<int, pair<int,int> > >::iterator it;
queue<pair<int, int> > Q;
pair<int,int> c;
void init(),solve();
int bford(int);
int main()
{
    init();
    solve();
    return 0;
}
void init() //citeste & initializeaza lista, graf neorientat
{
    freopen("lanterna.in","r",stdin);
    freopen("lanterna.out","w",stdout);

    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&s[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&a,&b,&T,&W);
        G[a].push_back(mp(b,mp(T,W)));
        G[b].push_back(mp(a,mp(T,W)));
    }
}
void solve()
{
    //cautare binara * bellman ford
    st=1;dr=k-1;
    tok  = k;
    tmin = bford(k);//init

    while(st<=dr)
    {
        mijl = (st+dr)/2;
        if(bford(mijl)==tmin)
            tok=mijl,dr=mijl-1;
        else
            st=mijl+1;
    }
    printf("%d %d\n",tmin,tok);
}
int bford(int kmax)
{
    //init
    for(i=1;i<=n;i++)
        for(j=0;j<=kmax;j++)
            D[i][j]=oo,v[i][j]=0;

    Q.push(mp(1,0));D[1][0]=0;v[1][0]=1;
    tN = oo;
    while(!Q.empty())
    {
        //extragem root-ul
        c = Q.front();
        i = c.first;
        k = c.second;
        v[i][k]=0;
        if(D[i][k] < tN)//merita?
        {
            for(it=G[i].begin();it!=G[i].end();it++)//parcurgem vecinii
            {
                //info noul nod
                j    = it->first;
                T    = it->second.first;
                W    = it->second.second;
                if(k+W <= kmax)//are suficienti wati pentru a parcurge
                {
                    p = D[i][k]+T; //timpul
                    charge = k+W;
                    if(s[j])charge = 0; //putem sa ne reincarcam? De ce nu.

                    if(p<D[j][charge]) //avem un consum mai bun intre nodul i si j?
                    {
                        D[j][charge]=p;
                        //actualizam solutia?
                        if(j==n && D[j][charge] < tN)
                            tN = D[j][charge];
                        //ciclu si se merita?
                        if(!v[j][charge] && D[j][charge] < tN)
                        {
                            v[j][charge]=1;
                            Q.push(mp(j,charge));
                        }
                    }
                }
            }
        }
        Q.pop();
    }
    return tN;
}
