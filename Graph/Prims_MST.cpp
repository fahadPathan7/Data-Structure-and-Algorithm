/* A spanning tree of a graph G is a tree that includes every vertex of G and is a subgraph of G (every edge in the tree belongs to G)
(no cycle is allowed). The cost of the minimum spanning tree is the minimum sum of the weights of all the edges in the tree. */
// Time Complexity, for adjacency matrix : O (V ^ 2)
// for adjacency list : O (E log V) (this code)

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
vector<pll> adj[mx]; // {weight, node}
vector<ll> parent(mx), edge_weight(mx, inf);
vector<bool> visited(mx, 0);

void prims(ll sNode) {
    parent[sNode] = -1;

    multiset<pll> ms; // {weight, node}
    ms.insert({ 0, sNode });

    while (!ms.empty()) {
        pll p = *ms.begin();
        ms.erase(ms.begin());

        ll cNode = p.second;
        if (visited[cNode]) continue;
        visited[cNode] = true;

        for (ll i = 0; i < adj[cNode].size(); i++) {
            ll tNode = adj[cNode][i].second, weight = adj[cNode][i].first;

            // only this condition is different from dijkstra
            if (weight < edge_weight[tNode]) {
                edge_weight[tNode] = weight;
                parent[tNode] = cNode;

                ms.insert({ edge_weight[tNode], tNode });
            }
        }
    }
}

int main() {
    cin >> node >> edge;

    for (ll i = 0; i < edge; i++) {
        ll eFrom, eTo, weight;
        cin >> eFrom >> eTo >> weight;

        adj[eFrom].pb({ weight, eTo });
        adj[eTo].pb({ weight, eFrom }); // undirected
    }

    prims(0); // considering 0 as root

    cout << "\nEdge   " << "Weight" << endl;
    for (ll i = 1; i < node; i++) {
        cout << parent[i] << " - " << i << "    " << edge_weight[i] << endl;
    }
}