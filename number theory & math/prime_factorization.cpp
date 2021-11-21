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
int List[300];
int Listsize = 0;

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
void primefactorization(ll n)
{
    for (int i = 0; primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                List[Listsize++] = primes[i];
            }
        }
    }
}
int main()
{
    sieve(10000000);

    ll n;
    cin >> n;
    
    primefactorization(n);

    for (int i = 0; i < Listsize; i++)
    {
        cout << List[i] << " ";
    }
}
