// Template //
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <array>
#include <cassert>
#include <random>

#define FOR(i, a, b) for (ll i = a, _b = b; i <= _b; i++)
#define FORD(i, a, b) for (ll i = a, _b = b; i >= _b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define task "FRIENDSHIP"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

template <class T>
bool minimize(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool maximize(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//
int n, q, m;
const int offset = 301;
vector<int> adj[650];
ll d[500000];
ii a[maxn];
void input()
{
    cin >> m >> n;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        v += 301;
        a[i] = {u, v};
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
ll res = inf;
void bfs(int i, int x, int x2)
{
    queue<int> q;
    mset(d, 0x3f);
    q.push(i);
    d[i] = 0;
    while (!q.empty())
    {
        int u = q.front();
        if (u == x || u == x2)
        {
            minimize(res, d[u]);
            return;
        }
        q.pop();
        for (int v : adj[u])
            if (minimize(d[v], d[u] + 1))
                q.push(v);
    }
}

void lds_go_goooo()
{
    
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        res = inf;
        bfs(a[u].fi, a[v].se, a[v].fi);
        bfs(a[u].se, a[v].se, a[v].fi);
        if (res == inf)
            cout << -1 << endl;
        else
            cout << res + 1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen(task ".IN", "r", stdin);
    //freopen(task ".OUT", "w", stdout);
    // int sub=1;
    // cin>>sub;
    ll test_case = 1; // cin>>test_case;
    while (test_case--)
    {
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}