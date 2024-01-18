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
const ll maxn = 2e6 + 100;
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
ll  dp[maxn];
ii edge[maxn];
ll f[maxn],g[maxn],h[maxn];

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
            update(first, second, g[v], v);

    for (int v : adj[u])
        if (v != par )
        {
            fout[v] = max(fout[u] + w[v], fout[v]);
            fout[v] = max(fout[v], (g[v] == first.fi ? second.fi +w[u] : first.fi  + w[u])+w[v]);
            dfsout(v, u);
        }
}
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

void update3(ll &a, ll &b, ll &c, ll d)
{
    if (d > a)
        c=b,b = a, a = d;
    else
        if(d>b)
            c = b, b = d;
        else
            c=max(d,c);
}

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


void ma(int u,int par)
{
    ll first=0,second=0,firstfirst=0,secondsecond=0,thirdthird=0;
    for(int v:adj[u])
        if(v!=par)
        {
            update2(first,second,h[v]);
            update3(firstfirst,secondsecond,thirdthird,g[v]);
        }

    for(int v:adj[u])
        if(v!=par)
        {
            ma(v,u);
            dp[u]=max({h[v]+(h[v]==first?second:first),dp[v],dp[u],h[v]+fout[u]+(g[v]==firstfirst?secondsecond:firstfirst)});
            if(g[v]==firstfirst)
                dp[u]=max(dp[u],h[v]+secondsecond+thirdthird+w[u]);
            else
                if(g[v]==secondsecond)
                    dp[u]=max(dp[u],h[v]+firstfirst+thirdthird+w[u]);
                else
                    dp[u]=max(dp[u],h[v]+firstfirst+secondsecond+w[u]);
        }
}

void lds_go_goooo()
{
    if(n<=1000)
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
        return;
    }
    mset(dp,0);
    ll res=0;
    fout[1]=w[1];
    dfs(1,-1);
    dfsout(1,-1);
    ma(1,-1);
    cout<<dp[1];
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
