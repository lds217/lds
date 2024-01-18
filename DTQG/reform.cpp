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
int comp[maxn];
int n,m;
int timer,low[maxn],num[maxn],h[maxn];
vector <int> G[maxn],adj[maxn];
void input()
{
    cin>>n>>m;
    FOR(i,1,n)
    {
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

int bridge[maxn];

void dfs(int u,int par,int id)
{
    low[u]=num[u]=comp[id]=++timer;
    for(int v:G[u])
    {
        if(v==par)  continue;
        if(!num[v])
        {
            dfs(v,u,id);
            h[u]+=h[v];
            low[u]=min(low[u],low[v]);
            if(low[v]==num[v])
            {
                bridge[id]++;
                adj[u].pb(v);
            }

        }
        else
            low[u]=min(low[u],num[v]);
    }
}

int dp[maxn];


void lds_go_goooo()
{
    FOR(i,1,n)
        h[i]=1;
    int cur=0;
    int type=0;
    FOR(i,1,n)
    {
        if(!num[i])
            dfs(i,i,++cur);
    }
   // cout<<cur<<endl;
    if(cur==2)
    {
        cout<<comp[1]*(n-comp[1])*(m-bridge[1]-bridge[2]);
        return;
    }
    if(cur>=3)
    {
        cout<<0;
        return;
    }
    
   // FOR(i,1,n)  cout<<h[i]<<' ';
//cout<<endl;
  //  cout<<endl;
    ll ans=0;//n*(n-1)/2-m;

    FOR(i,1,n)
        if(adj[i].size())
        {
           // cout<<i<<endl;
            for(int v:adj[i])
            {
                ans+=h[v]*(n-h[v])-1;
          //      cout<<v<<' ';
            }
           // cout<<endl;
        }
        else
            ans+=n*(n-1)/2-m;
    cout<<ans;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "rbtree"
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
