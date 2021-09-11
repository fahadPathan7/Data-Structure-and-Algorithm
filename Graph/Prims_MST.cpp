/* A spanning tree of a graph G is a tree that includes every vertex of G and is a subgraph of G (every edge in the tree belongs to G) (no cycle is allowed). The cost of the minimum spanning tree is the minimum sum of the weights of all the edges in the tree. */
// Time Complexity, for adjacency matrix : O (V ^ 2)
// for adjacency list : O (E log V) (should follow dijkstra for this)
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
ll parent[mx];
ll node;
vector <bool> mstSet(mx, 0); // to identify the visited nodes.
vector <ll> key(mx, inf); // to store minimum weight.

ll minKey() {
    // for finding the minimum weighted node which is not visited yet.
    ll minIndex, min = inf;
    for (ll v = 0; v < node; v++) {
        if (mstSet[v] == false && key[v] < min) {
            minIndex = v, min = key[v];
        }
    }

    return minIndex;
}
void prim(ll graph[5][5]) {
    key[0] = 0;
    parent[0] = -1;

    for (ll i = 0; i < node - 1; i++) {
        ll x = minKey();
        mstSet[x] = true;

        for (ll v = 0; v < node; v++) {
            if (graph[x][v] && mstSet[v] == false && graph[x][v] < key[v]) {
                parent[v] = x;
                key[v] = graph[x][v];
            }
        }
    }
}
int main()
{
    node = 5;
    // can be used adjacencylist
    // here in the graph, the values are the weights of the connected nodes.
    ll graph[5][5] = { { 0, 2, 0, 6, 0 },
                  { 2, 0, 3, 8, 5 },
                  { 0, 3, 0, 0, 7 },
                  { 6, 8, 0, 0, 9 },
                  { 0, 5, 7, 9, 0 } };
    prim(graph);

    cout << "Edge   " << "Weight" << endl;
    for (ll i = 1; i < node; i++) {
        cout << parent[i] << " - " << i << "    " << key[i] << endl;
    }
}