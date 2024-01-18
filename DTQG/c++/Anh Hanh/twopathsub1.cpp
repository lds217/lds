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
ll fin[maxn], fout[maxn];
int n;

ll w[maxn];
vector<int> adj[maxn];
ll dp[maxn][5];
ii edge[maxn];
// dp 0: Tổng của 2 chuổi dài nhất
// dp 1: chuỗi dài nhất
// dp 2: chuỗi đến lá dài nhất + chuỗi dài nhất mà khong phải nó
// dp 3: chuỗi cha dài nhất là con của dp[0][1]
// dp 4 chuỗi đến lá dài nhất
void dfsin(int u, int par)
{
    fin[u] = 0;
    for (int v : adj[u])
        if (v != par )
        {
            dfsin(v, u);
            /*fin[u] = max(fin[u], fin[v] + w[v]);
            dp[u][0] = max(dp[u][0], dp[u][1] + dp[v][1]); // The largest chain in the subtree + the largest child node in the subtree a chain
            dp[u][0] = max(dp[u][0], dp[v][0]);              // Transfer directly from child node
            dp[now][0] = max(dp[now][0], dp[x][2] + dp[now][4]); // The chain and subtree from the child node subtree to the leaf node The inner chain to the leaf node forms a chain through the current node + a chain that does not intersect with it
            dp[now][0] = max(dp[now][0], dp[now][2] + dp[x][4]); // Similar to the above transfer

            dp[now][1] = max(dp[now][1], dp[x][1]);              // Transfer directly from child node
            dp[now][1] = max(dp[now][1], dp[now][4] + dp[x][4]); // The chain and subtree from the child node subtree to the leaf node The inner chain to the leaf node forms a chain through the current node

            dp[now][2] = max(dp[now][2], dp[x][2] + a[now]);              // Directly transfer from the child node to the leaf in the subtree of the child node The chain of nodes extends to the current node
            dp[now][2] = max(dp[now][2], dp[x][4] + dp[now][3] + a[now]); // Similar to the above transfer
            dp[now][2] = max(dp[now][2], dp[now][4] + dp[x][1]);          // Transfer directly according to the definition of dp[][2]

            dp[now][3] = max(dp[now][3], dp[x][1]); // Transfer directly according to the definition of dp[][3]

            dp[now][4] = max(dp[now][4], dp[x][4] + a[now]);*/
        }
}

void update(ii &a, ii &b, int c, int v)
{
    if (c > a.fi)
        b.fi = a.fi, b.se = a.se, a.fi = c, a.se = v;
    else
        b = max(b, {c, v});
}

void dfsout(int u, int par)
{
    ii first = {-1, 0}, second = {-1, 0};
    for (int v : adj[u])
        if (v != par )
            update(first, second, fin[v], v);
    // cout << u << ":" << first.fi << ' ' << first.se << ' ' << second.fi << ' ' << second.se << endl;
    for (int v : adj[u])
        if (v != par )
        {
            fout[v] = max(fout[u] + w[v], w[v]);
            fout[v] = max(fout[v], (fin[v] == first.fi ? second.fi + w[first.se] + w[u] : first.fi + w[second.se] + w[u]));
            dfsout(v, u);
        }
}
ll al = 0;
void input()
{
    mset(dp, 0);
    cin >> n;
    FOR(i, 1, n)
    cin >> w[i];
    FOR(i, 1, n - 1)
    {
        int u, v;
       
        cin >> u >> v;
         edge[i] = {u, v};
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

ll f[maxn],g[maxn],h[maxn];

void update2(ll &a, ll &b, ll c)
{
    if (c > a)
        b = a, a = c;
    else
        b = max(b, c);
}



void dfs(int u, int par)
{
    ll first=0,second=0;
    f[u]=g[u]=h[u]=w[u];
    for(int v:adj[u])
    {
        if(v==par)continue;
        dfs(v,u);
        maximize(g[u],g[v]+w[u]);
        maximize(h[u],h[v]);
        update2(first,second,g[v]);
    }
     maximize(f[u],max(g[u],first+second+w[u]));
     maximize(h[u],f[u]);
    
     
}

void lds_go_goooo()
{
    ll res=0;
    FOR(i,1,n-1)
    {
        auto [u,v]= edge[i];
        dfs(u,v);
        dfs(v,u);
        res=max(res,h[u]+h[v]);
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#define task "twopaths"
    // freopen(task".INP", "r", stdin);
    // freopen(task".OUT", "w", stdout);
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
/*
 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Le Thanh Dat
  `Y8P'
   `Y'

*/
