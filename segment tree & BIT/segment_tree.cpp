// Time Complexity: O(nlog n)
// Tutorial: http://www.shafaetsplanet.com/?p=1557
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
ll ar[mx];
ll tree[mx * 4];

void init_tree(ll node, ll begin, ll end) {
	if (begin == end) {
		tree[node] = ar[begin];
		return;
	}

	ll left = node * 2;
	ll right = node * 2 + 1;
	ll mid = (begin + end) / 2;

	init_tree(left, begin, mid);
	init_tree(right, mid + 1, end);

	tree[node] = tree[left] + tree[right];
}
void update(ll node, ll begin, ll end, ll index, ll newVal) {
	if (index < begin || index > end) return;
	if (index == begin && index == end) {
		tree[node] = newVal;
		return;
	}

	ll left = node * 2;
	ll right = node * 2 + 1;
	ll mid = (begin + end) / 2;

	update(left, begin, mid, index, newVal);
	update(right, mid + 1, end, index, newVal);

	tree[node] = tree[left] + tree[right];
}
ll query(ll node, ll begin, ll end, ll i, ll j) {
	if (i > end || j < begin) return 0;
	if (i <= begin && j >= end) return tree[node];

	ll left = node * 2;
	ll right = node * 2 + 1;
	ll mid = (begin + end) / 2;

	ll a = query(left, begin, mid, i, j);
	ll b = query(right, mid + 1, end, i, j);

	return a + b;
}
int main() {
	ll n;

	cin >> n;
	for (ll i = 1; i <= n; i++) cin >> ar[i];

	init_tree(1, 1, n);
    update(1, 1, n, 2, 0);
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 8);
    cout << query(1, 1, n, 2, 2) << endl;
}