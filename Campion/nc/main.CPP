#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define isl(a) (((a)>='a'&&(a)<='z')||((a)>='A'&&(a)<='Z'))
using namespace std;
int fraze,cuv;
vector<int> sol;
vector<int>::iterator i;
char s[5000],*p;
void init();
int main()
{
     init();
     return 0;
}
void init()
{
    freopen("nc.in","r",stdin);
    freopen("nc.out","w",stdout);

    for(p=fgets(s,4000,stdin);;)
    {
        if(!*p)
        {
            p=fgets(s,4000,stdin);
            if(!p)break;
        }
        if(*p=='!'||*p=='?')++p,fraze++,sol.push_back(cuv),cuv=0;
        else if(*p=='.'){
            while(*p=='.')++p;
            fraze++;
            sol.push_back(cuv);
            cuv=0;
            }
        else if(isl(*p)) {cuv++; while(isl(*p))++p;}
        else ++p;
    }
    printf("%d\n",fraze);
    for(i=sol.begin();i!=sol.end();i++)
        printf("%d\n",*i);
}

