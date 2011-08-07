#include<cstdio>
#include<list>
using namespace std;
list<int> v[10002];
struct nod{long int info;nod *next;};
long int n,k,i,j,m,a,b,gr[10002],cost[10002],h[10002],s,L;
void read(),solve(),hd(int R),hu(int S),sh(int I,int J);
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("cezar1.in","r",stdin);
	freopen("cezar1.out","w",stdout);
	scanf("%ld%ld",&n,&k);
	//gradul & lista de adiacenta
	for(i=1;i<n;i++){scanf("%ld%ld",&a,&b);gr[a]++;gr[b]++;v[a].push_back(b);v[b].push_back(a);}
}
void solve()
{
    //costurile 1, contorizam toate frunzele si le adaugam intr-un min heap
	for(i=1;i<=n;i++){cost[i]=1;if(gr[i]==1){L++;h[L]=i;}}
	for(i=1;i<=n-k-1;i++) //ne intereseaza n-k din toate nodurile
	{
	    //extragem varful heap-ului, adaugam la costul total minim si eliminam din heap valoarea avand grija sa scadem si gradul
		j=h[1];s+=cost[j];gr[j]--;h[1]=h[L--];hd(1);

		//cat timp nodul j are muchii cu grad > 0, le sterge
	    while(!gr[v[j].front()])v[j].pop_front();
        //???
	    m=v[j].front();gr[m]--;cost[m]+=cost[j];
	    if(gr[m]==1){h[++L]=m;hu(L);}
	}
	printf("%ld\n",s);
}
//heap up
void hd(int R)
{
	int S,D;
	S=R<<1;D=S+1;
	if(S>L)return;
	if(S<L)if(cost[h[D]]<cost[h[S]]) S=D;
	if(cost[h[S]]<cost[h[R]]){sh(S,R);hd(S);}
}
//heap down
void hu(int S)
{
	int R=S>>1;
	if(R)
		if(cost[h[S]]<cost[h[R]])
		{
			sh(S,R);
			hu(R);
		}
}
//swap
void sh(int I,int J)
{
    int A=h[I];h[I]=h[J];h[J]=A;
}
