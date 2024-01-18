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
typedef vector<ll> vi;
const ll maxn = 3e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}

template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//
#define int ll

const int N = 3e5 + 5;
int dist[N],sz[N],bigChild[N],n,k;
long long ans,cnt[3 * N];
vector<int>g[N];

void dfs1(int u,int par) {
    sz[u] = 1;
    bigChild[u] = -1;
    for (auto v: g[u]) {
        if (v == par) continue;
        dist[v] = dist[u] + 1;
        dfs1(v,u);
        sz[u] += sz[v];
        if (bigChild[u] == -1 || sz[v] > sz[bigChild[u]])
            bigChild[u] = v;
    }
}

void calc(int u,int par,int anc) {
    if (k - dist[u] + 2 * dist[anc] >= 0) ans += cnt[k - dist[u] + 2 * dist[anc]];
    for (auto v: g[u]) {
        if (v == par) continue;
        calc(v,u,anc);
    }
}

void add(int u,int par,int val) {
    cnt[dist[u]] += val;
    for (auto v: g[u]) {
        if (v == par) continue;
        add(v,u,val);
    }
}

void dfs2(int u,int par,bool keep) {
    for (auto v: g[u]) {
        if (v == par || v == bigChild[u]) continue;
        dfs2(v,u,0);
    }
    if (bigChild[u] > 0) dfs2(bigChild[u],u,1);
    cnt[dist[u]]++;
    ans += cnt[dist[u] + k];
    for (auto v: g[u]) {
        if (v == par || v == bigChild[u]) continue;
        calc(v,u,u);
        add(v,u,1);
    }
    if (!keep) add(u,par,-1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("tree-distance.inp","r",stdin);
    freopen("tree-distance.out","w",stdout);
    int t;
    cin >> t >> n >> k;
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,-1);
    dfs2(1,-1,1);
    cout << ans << "\n";
}
