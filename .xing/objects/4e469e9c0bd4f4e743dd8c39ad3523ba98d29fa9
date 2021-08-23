#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{ll n,b=0,m,ssum=0;vector<ll> a;
cin>>n;
a.resize(n);
for(ll i=0;i<n;i++)
cin>>a[i];
sort(a.begin(),a.end());
m=a[0];
for(ll i=0;i<n;i++)
{if(a[i]!=m)
{m=a[i];ssum+=(i-b)*(i-b);b=i;}
}
ssum+=(n-b)*(n-b);
cout<<(n*n-ssum)/2;

return 0;}