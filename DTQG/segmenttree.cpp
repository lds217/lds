#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int node[40000], a[10000];

int getmax(int id, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return -1e9;
    if (u <= l && v >= r)
        return node[id];
    int mid = (l + r) / 2;
    int maxL = getmax(id * 2, l, mid, u, v);
    int maxR = getmax(id * 2 + 1, mid + 1, r, u, v);
    return max(maxL, maxR);
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        node[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    node[id] = max(node[2 * id], node[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        a[l] = val;
        node[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    node[id] = max(node[id * 2], node[id * 2 + 1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int x = 1; x <= n; x++)
        cin >> a[x];
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
            update(1, 1, n, x, y);
        else
            cout<<getmax(1, 1, n, x, y)<<endl;
    }
    return 0;
}