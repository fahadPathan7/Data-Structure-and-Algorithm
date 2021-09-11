// The algorithm is to solve all pair shortest path problem.
// Time Complexity: O (V ^ 3)
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
ll graph[10000][10000];
ll dis[10000][10000];

void floydWarshall() {
    for (ll k = 0; k < node; k++) {
        for (ll i = 0; i < node; i++) {
            for (ll j = 0; j < node; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
int main() {
    cin >> node;

    // entering the weights of every vertex from the other vertices.
    // if there is no edge , enter -1.
    for (ll i = 0; i < node; i++) {
        for (ll j = 0; j < node; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) graph[i][j] = inf;
            dis[i][j] = graph[i][j];
        }
    }

    floydWarshall();

    cout << endl;
    for (ll i = 0; i < node; i++) {
        for (ll j = 0; j < node; j++) {
            if (dis[i][j] == inf) cout << "INF ";
            else cout << dis[i][j] << "  ";
        }
        cout << endl;
    }
}