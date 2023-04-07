#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ed << "\n";
#define el cout << '\n';
#define rep(i, a, n, b) for (int i = a; i <= n; i += b)
#define foru(i, a, n, b) for (int i = a; i <= n; i += b)
#define ALL(s) s.begin(), s.end()
#define fi first
#define se second
#define task "a"
#define mem(dp, a) memset(dp, a, sizeof dp)
#define ford(i, a, n, b) for (int i = a; i >= n; i -= b)
#define pb(x) push_back(x);
#define int long long
#define db(x) cerr << x << '\n';
#define A(a) abs(a)
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

const ll mod[4] = {998244353, (int)1e9 + 7, 987654323};
const int base[4] = {31, 311, 331};
const int INF = 1e9;
const int N = 1e5 + 2;
const int MAX = 2e5 + 2;
const int NMAX = 5e4;
int n, tree[N * 4], a[N], q, lazy[N * 4];

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}

void update(int id, int l, int r, int u, int v, int val)
{
    if (l == r)
        a[l] += val;
    if (l > r)
        return;

    if (lazy[id] != 0)
    {
        tree[id] += lazy[id];
        if (l != r)
        {
            lazy[id * 2] += lazy[id];
            lazy[2 * id + 1] += lazy[id];
        }
        lazy[id] = 0;
    }

    if (u > r || v < l)
        return;
    if (u <= l && v >= r)
    {
        tree[id] += val;
        if (l != r)
        {
            lazy[id * 2] += val;
            lazy[2 * id + 1] += val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l)
        return -1e9;
    if (lazy[id] != 0)
    {
        tree[id] += lazy[id];
        if (l != r)
        {
            lazy[id * 2] += lazy[id];
            lazy[2 * id + 1] += lazy[id];
        }
        lazy[id] = 0;
    }
    if (u <= l && v >= r)
        return tree[id];
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

signed main()
{
    cin >> n;
    FOR(x, 1, n)
    cin >> a[x];
    build(1, 1, n);
    cin >> q;
    while (q--)
    {
        int type, x, y, val;
        cin >> type;
        if (type == 1)
        {
            cin >> x >> y >> val;
            update(1, 1, n, x, y, val);
        }
        else
        {
            cin >> x >> y;
            cout << get(1, 1, n, x, y) ed;
        }
    }
}
