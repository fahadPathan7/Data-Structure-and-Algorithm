// Sparse table is a data structure that allows 
// answering queries of finding minimum or maximum 
// in a range in an array in O(1) time after O(nlogn) preprocessing. 
// tutorial : http://adilet.org/blog/sparse-table/

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
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//
const int MAXN = 105000;
const int MAXLOG = 20;
int n;
int logs[MAXN];
int a[MAXN];
int table[MAXLOG][MAXN];
//table[i][j] means the minimum in the subrange of length 2^i starting from the position j. Here are some values of table[i][j] in our example array a: 

void computeLogs() // find the maximum power of 2 for which 2^logs[i] <= i.
{
    logs[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        logs[i] = logs[i / 2] + 1;
    }
}
void buildSparseTable()
{
    for (ll i = 0; i <= logs[n]; i++)
    {
        ll len = 1 << i; // 2^i (left shift)
        for (ll j = 0; j + len <= n; j++)
        {
            if (len == 1)
            {
                table[i][j] = a[j];
            }
            else
            {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + len / 2]);
            }
        }
    }
}
ll getMin(ll begin, ll end)
{
    ll p = logs[end - begin + 1];
    ll len = 1 << p;

    return min(table[p][begin], table[p][end - len + 1]);
}

int main()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    computeLogs();
    buildSparseTable();

    ll query;
    cin >> query;
    for (ll i = 0; i < query; i++)
    {
        ll begin, end;
        cin >> begin >> end;

        cout << getMin(begin, end); // Indexing from 0;
    }
}
