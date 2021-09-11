// Time complexity: O(v + e)
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
#define white 1
#define black 2

ll node, edge, dis[mx], color[mx], parent[mx];
vector<vector<ll>> adj(mx);

void bfs(ll startingNode) {
    for (ll i = 0; i < node; i++) color[i] = white;

    parent[startingNode] = -1;
    dis[startingNode] = 0;
    queue <ll> q;
    q.push(startingNode);

    while (!q.empty()) {
        ll x = q.front();
        q.pop();

        for (ll i = 0; i < adj[x].size(); i++) {
            if (color[adj[x][i]] == white) {
                parent[adj[x][i]] = x;
                dis[adj[x][i]] = dis[x] + 1;
                q.push(adj[x][i]);
            }
        }
        color[x] = black;
    }
}
int main() {
    cin >> node >> edge;

    for (ll i = 0; i < edge; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a); // undirected edge
    }

    bfs(0); // single source.

    //Todo: can print traversal order, parent, label and many more...
}