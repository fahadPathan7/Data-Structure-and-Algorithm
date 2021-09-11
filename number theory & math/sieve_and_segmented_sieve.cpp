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
vector<ll> primes;

void sieve(ll n) {
    vector<bool> isPrime(n + 5, true);

    for (ll i = 3; i * i <= n; i += 2) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= n; j += i + i) {
                isPrime[j] = false;
            }
        }
    }

    primes.pb(2);
    for (ll i = 3; i <= n; i += 2) {
        if (isPrime[i]) primes.pb(i);
    }
}
void segSieve(ll l, ll r) {
    vector<bool> isPrime(r - l + 1, true);
    if (l == 1) isPrime[0] = false;

    for (ll i = 0; primes[i] * primes[i] <= r; i++) {
        ll curPrime = primes[i];
        ll base = l / curPrime * curPrime;
        if (l % curPrime != 0) base += curPrime;

        for (ll j = base; j <= r; j += curPrime) isPrime[j - l] = false;
        if (curPrime == base) isPrime[base - l] = true;
    }

    for (ll i = 0; i < r - l + 1; i++) {
        if (isPrime[i]) cout << l + i << " ";
    }
    cout << endl;
}

int main() {
    sieve(10000000);
    segSieve(1, 100);
}