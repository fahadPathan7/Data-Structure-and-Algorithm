/*
Question:
How many numbers have digit sum equal to x in the range a to b?
*/

#include <bits/stdc++.h>
using namespace std;
//
#define ll long long
#define ull unsigned long long
#define mx 100010
#define mod 1000000007
#define inf INT_MAX
#define pi acos(-1)
#define endl '\n'
#define pb push_back
#define pll pair<ll, ll>
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//
ll n, x;
ll dp[11][99][2];
vector<ll> vec(15);

ll calculate(ll pos, ll digitSum, ll isSmall) {
    if (pos == n + 1) return digitSum == x;
    if (dp[pos][digitSum][isSmall] != -1) return dp[pos][digitSum][isSmall];

    ll hi = isSmall ? 9 : vec[pos - 1];
    ll res = 0;

    for (ll i = 0; i <= hi; i++) {
        res += calculate(pos + 1, digitSum + i, isSmall | (i < hi));
    }

    return dp[pos][digitSum][isSmall] = res;
}
void fillVec(ll a) {
    vec.clear();
    n = 0;

    while (a) {
        vec.pb(a % 10);
        a /= 10;
        n++;
    }

    reverse(vec.begin(), vec.end());
}

int main() {
    ll a, b;
    cin >> a >> b;
    cin >> x;

    fillVec(b);
    memset(dp, -1, sizeof(dp));
    ll bSum = calculate(1, 0, 0);

    fillVec(a - 1);
    memset(dp, -1, sizeof(dp));
    ll aSum = calculate(1, 0, 0);

    cout << bSum - aSum << endl;
}