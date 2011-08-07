//netestat optim
#include<stdio.h>

struct nod 
{
  int v;
  nod *next;
}

nod inc,sfarsit;

int main()
{
 freopen("date.in","r",stdin);
 freopen("date.out", "w",stdout);
 
 int n,i,t;
 scanf("%d",&n);
 inc = new nod;
 scanf("%d",inc->v);
 sfarsit = inc;

 for(i = 1; i < n;i++)
 {
    sfarsit->next = new nod;
    scanf("%d",&sfarsit->next->v);
    sfarsit = sfarsit->next;   
 }
 
 while(inc != NULL)
 { 
    sfarsit = inc;
    while(sfarsit->next != NULL)
      sfarsit = sfarsit->next;
    t=inc->v;
    inc->v = sfarsit->v;
    sfarsit->v = t;
    inc = inc->next; 
 }
 while(inc != NULL)
 {
   printf("%d ",inc->v);
   inc = inc->v;
 } 
 
 fclose(stdin); fclose(stdout);
 return 0;
}