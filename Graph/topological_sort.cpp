/* Topological order may not exist at all if the graph contains cycles. 
And may have multiple solutions of topological sort in one graph */
// Time Complexity: O (V + E) 
// Tutorial: https://cp-algorithms.com/graph/topological-sort.html
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
ll node, edge;
vector<ll> vec;
vector<ll> visited(mx, 0);
vector<vector<ll>> adj(mx);

void dfs(ll node) {
    visited[node] = 1;
    for (ll i : adj[node]) {
        if (!visited[i]) dfs(i);
    }

    vec.pb(node);
}
void dfsVisit() {
    for (ll i = 0; i < node; i++) {
        // should start dfs from every node which is not visited yet.
        if (!visited[i]) dfs(i);
    }
}
int main() {
    cin >> node >> edge;
    for (ll i = 0; i < edge; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b); // directed edge
    }

    dfsVisit();

    // to have the answer, the vec should be reversed. because the result is
    // according to the decreasing order of finishing time of dfs. and the vec
    // is built according to the increasing order. (can use stack.)
    reverse(vec.begin(), vec.end());
    for (ll i : vec) cout << i << " ";
}
