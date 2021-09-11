#include <bits/stdc++.h>
using namespace std;

#define mx 100001

long long int arr[mx], result[mx];
struct info
{
    long long int prop, sum;
} tree[mx * 4];

void init(long long int node, long long int b, long long int e)
{
    if (b == e)
    {
        tree[node].sum = arr[b];
        return;
    }
    long long int Left = node * 2;
    long long int Right = node * 2 + 1;
    long long int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void update(long long int node, long long int b, long long int e, long long int i, long long int j, long long int x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

long long int query(long long int node, long long int b, long long int e, long long int i, long long int j, long long int carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    long long int Left = node << 1;
    long long int Right = (node << 1) + 1;
    long long int mid = (b + e) >> 1;

    long long int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    long long int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    long long int n, q, a, b, c, d, t, i, count;

    cin >> t;
    while (t--)
    {
        count = 0;
        cin >> n >> q;
        init(1, 1, n);
        for (i = 0; i < q; i++)
        {
            cin >> a;
            if (a == 0)
            {
                cin >> b >> c >> d;
                update(1, 1, n, b, c, d);
            }
            else if (a == 1)
            {
                cin >> b >> c;
                result[count] = query(1, 1, n, b, c);
                count++;
            }
        }
        for (i = 0; i < count; i++)
        {
            cout << result[i];
            if (i != count - 1)
            {
                cout << endl;
            }
        }
    }
}

