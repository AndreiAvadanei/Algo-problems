#include<stdio.h>

#define MAX_N 200005
int n,k,count,op,val;
struct hp { int val,id; };

hp A[MAX_N];
int pos[MAX_N];

void push(int);
void pop(int);

int main()
{
    freopen("heapuri.in","r",stdin);
    freopen("heapuri.out","w",stdout);
    
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
       scanf("%d",&op);
       if(op == 1)
       {
		  count++; 
          scanf("%d",&val);
          push(val);   
       }   
       else if(op == 2)
       {
          scanf("%d",&val);
          pop(pos[val]);
       }
       else
       {
           printf("%d\n",A[1].val);
       }
    }-

    fclose(stdin); fclose(stdout);
    return 0;
}

void heapUp(int v)
{
	hp key = A[v];
    while(v > 1 && key.val < A[v/2].val)
    {
		pos[A[v/2].id] = v;
        A[v] = A[v/2];        
		v/=2;
    } 
	A[v] = key;
	pos[A[v].id] = v;
}

void heapDown(int v)
{
    int w = 2*v;
	hp aux;
    while(w <= k)
    {
       if(w+1 <= k && A[w+1].val < A[w].val) w++;
       if(A[v].val <= A[w].val) return;
	   
	   pos[A[v].id] ^= pos[A[w].id] ^= pos[A[v].id] ^= pos[A[w].id];
	   aux = A[v],A[v] = A[w],A[w] = aux;
       v = w;
       w *= 2;      
    } 
}

void pop(int v)
{   
	A[v] = A[k--]; 
	pos[A[v].id] = v;
	if(v > 1 && A[v].val < A[v/2].val) heapUp(v); //percolate
	else heapDown(v); //sift
}

void push(int v)
{
    A[++k].val   = v;
	A[k].id    = count;
    pos[count] = k;	
    heapUp(k); //percolate
}

