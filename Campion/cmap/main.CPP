/*#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#define oo 4e18;
using namespace std;
vector<pair<long long, long long> > V,X,Y;
void read(),solve();
long long cb(int,int),dist(pair<long long, long long>, pair<long long, long long>);
int n,x,y;
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("cmap.in","r",stdin);
    freopen("cmap.out","w",stdout);
    scanf("%d", &n);
    for(int i=1;i<=n;i++)scanf("%d%d",&x,&y),X.push_back(make_pair(x,y));
}
void solve()
{
    sort(X.begin(),X.end());
    for(int i=1;i<=n;i++)Y.push_back(make_pair(X[i].first, X[i].second));
    printf("%lf",sqrt(cb(0,n)));
}

long long cb(int st,int dr)
{
    if (st >= dr - 1)
    {
        return oo;
    }
    else if(dr-st==2)
    {
        if(Y[st] > Y[st+1])
            swap(Y[st],Y[st+1]);
        return dist(X[st],X[st+1]);
    }
    int mid = (st+dr)/2;
    long long  best = min(cb(st,mid),cb(mid,dr));
    merge(Y.begin()+st, Y.begin()+mid, Y.begin() + mid, Y.begin() + dr,V.begin());
    copy(V.begin(), V.begin()+(dr-st), Y.begin() + st);
    int vsize = 0;
    for(int i = st; i<dr;i++)
        if(abs(Y[i].second - X[mid].first) <= best)
            V[vsize++]=Y[i];
    for(int i=0;i<vsize-1;i++)
        for(int j=i+1;j<vsize && j-i < 8; j++)
            best = min(best, dist(V[i],V[j]));
    return best;
}
long long dist(pair<long long, long long> a, pair<long long, long long> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
using namespace std;

const char iname[] = "cmap.in";
const char oname[] = "cmap.out";

typedef long long i64;

const int MAX_N = 100005;
const i64 INF = 4e18;

vector < pair <i64, i64> > V(MAX_N), X, Y;

i64 dist(const pair <i64, i64>& a, const pair <i64, i64>& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

i64 go(int st, int dr, vector < pair <i64, i64> >& X, vector < pair <i64, i64> >& Y) {
    if (st >= dr - 1)
        return INF;
    else if (dr - st == 2) {
        if (Y[st] > Y[st + 1])
            swap(Y[st], Y[st + 1]);
        return dist(X[st], X[st + 1]);
    }
    int mid = (st + dr) / 2;
    i64 best = min(go(st, mid, X, Y), go(mid, dr, X, Y));

    merge(Y.begin() + st, Y.begin() + mid, Y.begin() + mid, Y.begin() + dr, V.begin());
    copy(V.begin(), V.begin() + (dr - st), Y.begin() + st);

    int v_size = 0;
    for (int i = st; i < dr; ++ i) if (abs(Y[i].second - X[mid].first) <= best)
        V[v_size ++] = Y[i];
    for (int i = 0; i < v_size - 1; ++ i) {
        for (int j = i + 1; j < v_size && j - i < 8; ++ j)
            best = min(best, dist(V[i], V[j]));
    }
    return best;
}

int main(void) {
    int n;
    ifstream in(iname);
    assert(in >> n);
    assert(1 <= n && n <= 100000);

    X.resize(n), Y.resize(n);
    for (int i = 0; i < (int) X.size(); ++ i) {
        assert(in >> X[i].first >> X[i].second);
        assert(-1000000000 <= X[i].first && X[i].first <= +1000000000);
        assert(-1000000000 <= X[i].second && X[i].second <= +1000000000);
    }
    in.close();

    sort(X.begin(), X.end());
    for (int i = 0; i < (int) X.size(); ++ i)
        Y[i] = make_pair(X[i].second, X[i].first);

    ofstream out(oname);
    out << fixed << setprecision(6) << sqrt(go(0, (int) X.size(), X, Y)) << "\n";
    out.close();
    return 0;
}
