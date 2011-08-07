#include<cstdio>
#include<vector>
#include<algorithm>
#define X first
#define Y second
#define mp make_pair
using namespace std;
int n,c,i,x,y,cc,k,j,ii,jj,nt,nr,sol;
vector<pair<int,int> > V[1100];
void read(),solve();
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("dreptc.in","r",stdin);
    freopen("dreptc.out","w",stdout);

    scanf("%d%d",&n,&c);

    //adaugam punctele pe culori
    for(i=1;i<=n;i++)scanf("%d%d%d",&x,&y,&cc),V[cc].push_back(mp(x+1000,y+1000));
}
void solve()
{
    //sortam dupa x apoi dupa y
    for(i=1;i<=5;i++) sort(V[i].begin(),V[i].end());

    //pentru fiecare culoare
    for(k=1;k<=5;k++)
    {
        //numarul elementelor
        nt = V[k].size();
        for(i=0;i<nt;i++)
          // printf("%d %d\n",V[k][i].X,V[k][i].Y );printf("---------------\n");
            for(j=i+1;j<nt-1;j++)
                if(V[k][i].X != V[k][j].X) //cautam doua elemente x1 != x2
                {
                    ii=i;jj=j;nr=0; //incercam sa vedem cate din ele au acelasi y
                   // printf("%d %d )",ii,jj);
                    //cautam doua elemente cu acelasi y
                    while(ii<j && jj<nt && V[k][i].X==V[k][ii].X && V[k][j].X == V[k][jj].X)
                    {
                        //incercam sa scapam de gunoi
                        while(ii<j && V[k][i].X==V[k][ii].X && V[k][ii].Y < V[k][jj].Y)ii++;
                        while(jj<nt && V[k][j].X == V[k][jj].X && V[k][jj].Y < V[k][ii].Y)jj++;
                        //avem doua la fel?
                        if(V[k][i].X==V[k][ii].X && V[k][j].X == V[k][jj].X && V[k][ii].Y==V[k][jj].Y) nr++,ii++,jj++;
                       // printf(" %d ",nr);
                    }
                    //actualizam solutia
                    sol += (nr*(nr-1))/2;
                   // printf(" (%d %d\n", ii, jj);
                    i=ii; j=jj-1;
                }
    }
    printf("%d\n",sol);
}

