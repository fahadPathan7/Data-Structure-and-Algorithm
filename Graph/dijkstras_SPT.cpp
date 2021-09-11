// Dijkstra’s algorithm to find the shortest path from a single source vertex to
// all other vertices in the given graph. Dijkstra’s algorithm doesn’t work for
// graphs with negative weight cycles, it may give correct results for a graph
// with negative edges.
// Time Complexity: O (v + Elog V)
// (mainly the complexity is O (V ^ 2))
// Tutorial: https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/

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
vector<pair<ll, ll>> graph[mx]; // {weight, node}
vector<bool> sptSet(mx, 0); // visited array
vector<ll> dis(mx, inf); // shortest distance

void dijkstra(ll sNode) {
    dis[sNode] = 0;
    multiset<pair<ll, ll>> s; // {weight, node}
    s.insert({ 0, sNode });

    while (!s.empty()) {
        pair<ll, ll> p = *s.begin();
        s.erase(s.begin());

        ll x = p.second; // node
        if (sptSet[x]) continue; // it is used to avoid negative cycle
        sptSet[x] = true;

        for (ll i = 0; i < graph[x].size(); i++) {
            ll w = graph[x][i].first, v = graph[x][i].second;

            if (dis[x] + w < dis[v]) {
                dis[v] = dis[x] + w;
                // to take the minimum weighted vertex, we should also enter the
                // weight of the vertex in the set.
                s.insert({ dis[v], v });
            }
        }
    }
}
int main() {
    cin >> node >> edge;

    for (ll i = 0; i < edge; i++) {
        ll a, b, weight;
        cin >> a >> b;
        cin >> weight;
        graph[a].pb({ weight, b });
        graph[b].pb({ weight, a });
    }
    dijkstra(0);

    cout << "Vertex   " << "Distance from source" << endl;
    for (ll i = 0; i < node; i++) {
        cout << i << "         " << dis[i] << endl;
    }
}