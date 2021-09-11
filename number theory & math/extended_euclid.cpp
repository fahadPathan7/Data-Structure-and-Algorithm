// Tutorial : https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
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
int gcd(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main()
{
    int a = 35, b = 15, x, y;
    int g = gcd(a, b, x, y);

    cout << g << endl;
}