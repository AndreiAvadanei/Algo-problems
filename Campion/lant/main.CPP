#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
char word[35],s[160][35],*p;
int k, sc, i,j,ii,jj,d[35][35],nr[160];
vector<int> G[160];
void init(),solve(),get(int);
int levenstein(int,int);
int main()
{
    init();
    solve();
    return 0;
}
void init()
{
    freopen("lant.in","r",stdin);
    freopen("lant.out","w",stdout);

    scanf("%d", &k);
    int ok;
    //read && init s, vector de cuvinte unice, cuvinte ce vor deveni noduri ale unui graf orientat
    while(scanf("%s",word) != -1)
    {
        p = strtok(word, " ,:;.!?-");
        while(p!=NULL)
        {
            if(strlen(p))
            {
                for(ok=i=1;i<=sc && ok;i++)
                    if(strcmp(s[i],p)==0)
                        ok=0;
                if(ok) strcpy(s[++sc],p);

            }
            p = strtok(NULL, " ,:;.!?-");
        }
    }
}
void solve()
{
    //muchie de la ii la jj doar daca levenstein e mai mic decat k
    for(ii=1;ii<=sc;ii++)
        for(jj=ii+1;jj<=sc;jj++)
        {
            if(levenstein(ii,jj)<=k)
                G[ii].push_back(jj);
        }
    //nr[i]=numarul de drumuri care incep din nodul i si se termina intr-un nod terminal
    get(1);

    printf("%d\n",nr[1]);
}
int levenstein(int a, int b)
{
    int n,m;
    //init levenstein
    n = strlen(s[a]);
    m = strlen(s[b]);
    //reset
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            d[i][j]=0;
    //init
   /* for(i=0;i<=n;i++) d[i][0]=i;
    for(j=0;j<=m;j++) d[0][j]=j;
    //levenstein
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(s[a][i]==s[b][j])
                d[i][j]=d[i-1][j-1];
            else
                d[i][j]=min(1+d[i-1][j],      //delete
                            min(1+d[i][j-1],  //insert
                                d[i-1][j-1]   //substitutie fara sa fie contorizata
                                )
                            );
    return d[n][m];*/
    for (i=0; i<=n; i++) d[i][m]=n-i;
    for (j=0; j<=m; j++) d[n][j]=m-j;
    for (i=n-1; i>=0; i--)
        for (j=m-1; j>=0; j--)
            {d[i][j]=1+d[i][j+1];
             if (d[i][j]>1+d[i+1][j])
                d[i][j]=1+d[i+1][j];
             if (s[a][i]==s[b][j] && d[i][j]>d[i+1][j+1])
                d[i][j]=d[i+1][j+1];}
    return d[0][0];
}
void get(int a)
{
    vector<int>::iterator it;
    if(G[a].empty()) { nr[a]=1; return; }
    int sum=0;
    for(it=G[a].begin();it!=G[a].end();it++)
    {
        if(!nr[*it]) get(*it);
        sum+=nr[*it];
    }
    nr[a]=sum;
}
