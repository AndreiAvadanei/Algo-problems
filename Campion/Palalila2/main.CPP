#include<cstdio>
using namespace std;
int i,n,ln,j,k;
char s[500000+2010];
int sm[500000+2010];
void solve();
int main()
{
    solve();
    return 0;
}
void solve()
{
    freopen("palalila2.in","r",stdin);
    freopen("palalila2.out","w",stdout);

    scanf("%s",s);
    for(k=0,i=1;s[i]>0;i++)
    {
        if(s[i]==s[k])continue;
        if(s[i]>s[k]){s[++k]=s[i];sm[k]=1;}
		else{s[++k]=s[i];sm[k]=-1;}
    }
    for(i=1;i<=k;i++)if(sm[i]==-1)break;
    if(i==k+1){printf("1\n");return;}
	sm[1]=sm[i];ln=1;
	for(j=i+1;j<=k;j++)
        if(sm[j]-sm[ln])
            sm[++ln]=sm[j];

	printf("%d\n",ln+2);
}

