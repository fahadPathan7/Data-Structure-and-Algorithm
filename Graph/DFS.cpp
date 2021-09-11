// Time complexity: O(v+e)
// This is undirected multi source dfs code
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
#define grey 2
#define black 3
int Time = 1;
int stime[mx], etime[mx], node, edge;
int color[mx];
vector<ll> traverse;
vector<vector<ll>> v(mx);

void dfsVisit(ll x) {
    traverse.pb(x);
    color[x] = grey;
    stime[x] = Time++;

    for (ll i = 0; i < v[x].size(); i++) {
        if (color[v[x][i]] == white) dfsVisit(v[x][i]);
    }

    color[x] = black;
    etime[x] = Time++;
}
void dfs() {
    for (ll i = 0; i < node; i++) {
        color[i] = white;
    }

    // for multi source dfs
    for (ll i = 0; i < node; i++) {
        if (color[i] == white) dfsVisit(i);
    }
}

int main() {

    cin >> node >> edge;
    for (ll i = 0; i < edge; i++) {
        ll a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a); // for undirected edges
    }

    dfs();

    // printing the traversal order
    for (ll i = 0; i < traverse.size(); i++) cout << traverse[i] << " ";
    cout << endl;
    // printing the starting and ending time of the nodes
    for (ll i = 0; i < node; i++) {
        cout << "Node " << i << ": " << stime[i] << " " << etime[i] << endl;
    }
}
