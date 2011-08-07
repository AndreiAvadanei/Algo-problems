#include<cstdio>

int a[100],b[100],v[100];

void back(int k,int len,int max)
{
     if(k-1 == max)
     {
         for(int i = 1; i <= max;i++)
           if(!v[a[i]]) printf("00 ");
           else if(v[a[i]]<10) printf("0%d ",v[a[i]]);
           else printf("%d ",v[a[i]]);
         printf("\n");
     }
     else
     {
         for(int  i = 1; i <= len; i++)
         {  if(!b[i] && a[k-1] < i)
           {
                 a[k] = i;
                 b[i] = 1;
                 back(k+1,len,max);
                 b[i] = 0;
           }
         }
     }
}

int main()
{
    freopen("combinari.in","r",stdin);
    freopen("combinari.out","w",stdout);
    int n,p;
    scanf("%d %d",&n,&p);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    back(1,n,p);
    fclose(stdin); fclose(stdout);
    return 0;
}
