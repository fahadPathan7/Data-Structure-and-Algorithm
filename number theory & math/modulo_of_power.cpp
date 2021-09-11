// Tutorial: http://www.shafaetsplanet.com/?p=936
#include <bits/stdc++.h>
using namespace std;
//
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mx 100010
#define mod 1000000007
#define inf INT_MAX
#define pi acos(-1)
#define endl '\n'
#define fin freopen("input", "r", stdin)
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//
ll F(ll n, ll p)
{
    if (p==0) return 1;
    if (p%2==0)
    {
        ll ret = F(n, p/2);
        return ((ret%mod)*(ret%mod))%mod;
    }
    else return ((n%mod)*F(n,p-1)%mod)%mod;
}
int main()
{
    cout<<F(2,10);
}
