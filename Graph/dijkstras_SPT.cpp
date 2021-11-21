// Dijkstra’s algorithm to find the shortest path from a single source vertex to
// all other vertices in the given graph. Dijkstra’s algorithm doesn’t work for
// graphs with negative weight cycles, it may give correct results for a graph
// with negative edges.
// Time Complexity: O (v + Elog V) // for this code
// (mainly the complexity is O (V ^ 2))
// Tutorial: https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/

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
vector<ll> dis(mx, inf); // distance of all node from root
vector<bool> visited(mx, 0);

void dijkstra(ll sNode) {
    dis[sNode] = 0;

    multiset<pll> ms;
    ms.insert({0, sNode});

    while(!ms.empty()) {
        pll p = *ms.begin();
        ms.erase(*ms.begin());
        ll cNode = p.second;

        if (visited[cNode]) continue; // avoiding negative cycle and revisit
        visited[cNode] = true;

        for (ll i = 0; i < adj[cNode].size(); i++) {
            ll tNode = adj[cNode][i].second, weight = adj[cNode][i].first;
            if (dis[cNode] + weight < dis[tNode]) {
                dis[tNode] = dis[cNode] + weight;

                ms.insert({dis[tNode], tNode});
            }
        }
    }
}
int main() {
    cin >> node >> edge;

    for (ll i = 0; i < edge; i++) {
        ll eFrom, eTo, weight;
        cin >> eFrom >> eTo >> weight;

        adj[eFrom].pb({weight, eTo});
        adj[eTo].pb({weight, eFrom});
    }

    dijkstra(0);

    cout << "Vertex   " << "Distance from source" << endl;
    for (ll i = 0; i < node; i++) {
        cout << i << "         " << dis[i] << endl;
    }
}