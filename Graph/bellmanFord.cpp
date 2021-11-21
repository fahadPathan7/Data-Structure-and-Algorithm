// Time Complexity: O (VE)
// Bellman-Ford does not work with undirected graph with negative edges as it will declared as negative cycle.
/* Tutorial: https://www.geeksforgeeks.org/bellman-ford-algorithm-simple-implementation/ */

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
vector<vector<ll>> adj(mx);
vector<ll> dis(mx, inf);

void bellmanFord(ll sNode) {
    dis[sNode] = 0;

    for (ll i = 0; i < node - 1; i++) {
        for (ll j = 0; j < edge; j++) {
            dis[adj[j][1]] = min(dis[adj[j][1]], dis[adj[j][0]] + adj[j][2]);
        }
    }

    // identifying negative cycle
    for (ll i = 0; i < edge; i++) {
        if (dis[adj[i][0]] + adj[i][2] < dis[adj[i][1]]) {
            cout << "Graph contains negative weight cycle to node: " << adj[i][1] << endl;
        }
    }
}
int main() {
    cin >> node >> edge;
    for (ll i = 0; i < edge; i++) {
        ll eFrom, eTo, weight;
        cin >> eFrom >> eTo >> weight;

        // directed edge
        adj[i].pb(eFrom);
        adj[i].pb(eTo);
        adj[i].pb(weight);

        //! for undirected graph weight must be >= 0. unless it will identify as negative loop.
        // because everytime (node - 1 times) it goes from a to b or b to a weight will decrease.
    }

    bellmanFord(0);

    // printing distances from source node
    cout << "Vertex Distance from Source" << endl;
    for (ll i = 0; i < node; i++) {
        cout << i << " -> " << dis[i] << endl;
    }
}