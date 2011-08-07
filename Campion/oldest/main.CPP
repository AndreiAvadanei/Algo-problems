#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<functional>
#define mp make_pair
#define pb push_back
#define MAXN 100000+5
using namespace std;
int n,i,op,key,val,hash_id,ccnt;
vector<pair<int,int> > V;
vector<int> Kt,Ks;
deque<pair<int,int> > HP;
pair<int,int> pHP;
deque<int> Q[MAXN];
void init(),solve(),query(),insert(int,int);
class cmp
{
    public:

        bool operator()(const pair<int,int>& x, const pair<int,int>& y) const
        {
            return x.first < y.first;
        }
};
int main()
{
    init();
    solve();
    return 0;
}
void init()
{
    freopen("oldest.in","r",stdin);
    freopen("oldest.out","w",stdout);
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&op);
        if(op==1)scanf("%d%d",&key,&val),V.pb(mp(key,val)),Kt.pb(key);
        else if(op==2)V.pb(mp(-1,-1));
    }
}
void solve()
{
    vector<pair<int,int> >::iterator its;
    vector<int>::iterator it,it2;
    //sort keys & make uniques id's
    sort(Kt.begin(),Kt.end());
    for(it=Kt.begin();it!=Kt.end();it++)
    {
        Ks.pb(*it);
        for(it2=it;it2!=Kt.end();it2++)
            if(*it2!=*it)break;
        it=it2-1;
    }
    Kt.resize(0);
    //now the tricky part - we need queue for every key and a min-heap for insertion

    for(its=V.begin();its!=V.end();its++)
    {
        key = its->first;
        val = its->second;

        //we procedeed query
        if(key==-1) {query(); continue;}
        insert(key,val);
    }
}

/*search hash id
  add to queue
  we update the min-heap
*/

void insert(int k, int v)
{
    hash_id = lower_bound(Ks.begin(),Ks.end(),k)-Ks.begin();
    Q[hash_id].push_back(v);
    HP.push_back(mp(++ccnt, hash_id));
    push_heap(HP.begin(),HP.end());
    make_heap(HP.begin(),HP.end(), cmp());
}
void query()
{
    pHP = HP.front();
    hash_id = pHP.second;
    HP.pop_front();
    printf("%d\n", Q[hash_id].back());
    Q[hash_id].pop_front();
    make_heap(HP.begin(),HP.end(), cmp());
}

