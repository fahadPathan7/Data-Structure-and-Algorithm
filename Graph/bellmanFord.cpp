// Time Complexity: O (VE)
// Tutorial: https://www.geeksforgeeks.org/bellman-ford-algorithm-simple-implementation/
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
vector<vector<ll>> v(mx);
vector<ll> dis(mx, inf);

void bellmanFord(ll sNode) {
    dis[sNode] = 0;

    for (ll i = 0; i < node - 1; i++) {
        for (ll j = 0; j < edge; j++) {
            dis[v[j][1]] = min(dis[v[j][1]], dis[v[j][0]] + v[j][2]);
        }
    }

    for (ll i = 0; i < edge; i++) {
        if (dis[v[i][0]] + v[i][2] < dis[v[i][1]]) {
            cout << "Graph contains negative weight cycle to node" << v[i][1]
            << endl;
        }
    }
}
int main() {
    cin >> node >> edge;
    for (ll i = 0; i < edge; i++) {
        ll from, to, weight;
        cin >> from >> to >> weight;
        v[i].pb(from);
        v[i].pb(to);
        v[i].pb(weight);
    }

    bellmanFord(0);

    cout << "Vertex Distance from Source" << endl;
    for (ll i = 0; i < node; i++) {
        cout << i << " -> " << dis[i] << endl;
    }
}