#include<cstdio>
#include<cstring>
using namespace std;
unsigned newnr;
char nr[40];
int T,i;
void read(),convert();
int main()
{
    read();
    return 0;
}
void read()
{
    freopen("kbiti.in","r",stdin);
    freopen("kbiti.out","w",stdout);
    scanf("%d", &T);
    for(;T;T--)
    {
        scanf("%s",nr);
        convert();
    }
}
void convert()
{
    int bit,exp=0;
    newnr = 0;
    for(i=strlen(nr)-1;i>=0;i--)
    {
        bit = nr[i]-'0';
        newnr = newnr + bit * (1<<exp);
        exp++;
    }
    newnr++;
    if(newnr)printf("%u\n",newnr);
    else printf("4294967296\n");
}
