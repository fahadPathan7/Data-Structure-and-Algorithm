// time complexity: O (v + e)

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
ll node, edge, t = 1;
vector<ll> sTime(mx), eTime(mx);
vector<ll> traverse;
vector<ll> adj[mx];
vector<bool> visited(mx, 0);

void dfs(ll cNode) {
    traverse.pb(cNode);
    visited[cNode] = 1;
    sTime[cNode] = t++;

    for (ll i = 0; i < adj[cNode].size(); i++) {
        if (!visited[adj[cNode][i]]) {
            dfs(adj[cNode][i]);
        }
    }

    eTime[cNode] = t++;
}
int main() {
    cin >> node >> edge;

    for (ll i = 0; i < edge; i++) {
        ll a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a); // for unorder edge
    }

    dfs(0); // single source dfs with 0 as starting node

    //Todo: can print traversal order, staring and ending time. and many more ...
}