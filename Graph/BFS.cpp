// time complexity: O(v + e)

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
ll node, edge;
vector<ll> dis(mx), parent(mx);
vector<bool> visited(mx, 0);
vector<vector<ll>> adj(mx);

void bfs(ll sNode) {
    parent[sNode] = -1;
    dis[sNode] = 0;

    queue<ll> q;
    q.push(sNode);

    while(!q.empty()) {
        ll cNode = q.front();
        q.pop();

        for (ll i = 0; i < adj[cNode].size(); i++) {
            if (!visited[adj[cNode][i]]) {
                parent[adj[cNode][i]] = cNode;
                dis[adj[cNode][i]] = dis[cNode] + 1;

                q.push(adj[cNode][i]);
            }
        }

        visited[cNode] = 1;
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

    bfs(0); // single source

    //Todo: can print traversal order, parent, label and many more...
}