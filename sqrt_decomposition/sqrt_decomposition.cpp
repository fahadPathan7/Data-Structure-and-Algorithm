// Time complexity O(sqrt(n))
// Tutorial : http://www.shafaetsplanet.com/?p=3416

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
ll segmentSize, segment[mx];
ll n, input[mx];

void process() {
    segmentSize = ceil(sqrt(n)); // taking ceiling is my opinion
    ll curSegment = -1;

    for (ll i = 0; i < n; i++) {
        if (i % segmentSize == 0) curSegment++;
        segment[curSegment] += input[i];
    }
}
ll query(ll begin, ll end) {
    ll sum = 0, i = begin;
    while(i <= end) {
        if (i % segmentSize == 0) break;
        sum += input[i++];
    }
    while(i + segmentSize <= end) {
        sum += segment[i / segmentSize];
        i += segmentSize;
    }
    while(i <= end) sum += input[i++];

    return sum;
}
void update(ll idx, ll val) {
    segment[idx / segmentSize] -= input[idx];
    segment[idx / segmentSize] += val;
    input[idx] = val;
}
int main() {
    // taking values of input array
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> input[i];

    // doing query and update
    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++) {
        ll choice;
        cin >> choice; // 1 to query, 2 to update

        if (choice == 1) {
            ll begin, end;
            cin >> begin >> end;
            cout << query(begin, end);
        }
        else if (choice == 2) {
            ll idx, val;
            cin >> idx, val;
            update(idx, val);
        }
    }
}