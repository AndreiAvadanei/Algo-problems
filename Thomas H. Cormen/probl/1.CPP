//nu-i optim, se poate face prin inmultirea matricilor insa nu stiu
//netestat
#include<iostream>

using namespace std;
int main()
{
 int n;
cin>>n;
int x1=1,x2=1,xn;
if(n==0) cout<<0;
else if(n<2) cout<<1;
else
{
for(int i = 2; i <=n;i++)
{
  xn = x1+x2;
  x2 = x1;
  x1 = xn;
}
cout<<xn;
}
return 0;
}