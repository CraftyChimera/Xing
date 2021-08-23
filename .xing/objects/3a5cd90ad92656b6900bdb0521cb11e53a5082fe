#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll choose(ll x,ll y)
{ll x1=1,y1=1;
for(ll i=1;i<=y;i++)
{y1*=i;y1%=1000000007;
x1*=(x+1-i);x1%=1000000007;}
return x1/y1;

}
int main()
{ll x,y;
cin>>x>>y;
if((x+y)%3!=0) {cout<<0; return 0;}
cout<<choose((x+y)/3,(2*x-y)/3);
return 0;
}
