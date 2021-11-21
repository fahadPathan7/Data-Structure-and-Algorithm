#include <bits/stdc++.h>
using namespace std;
//
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mx 100010
#define pi acos(-1)
#define endl '\n'
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int a, b;
    cout << gcd(a, b) << endl;
}
