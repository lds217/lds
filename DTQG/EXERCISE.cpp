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
int n,q;
int a[maxn],b[maxn];
 int maxx=0;
    vector <ii> query;
    ll  ans[105][100000];
void input()
{
    cin>>n>>q;
    FOR(i,1,n)  cin>>a[i];
    FOR(i,1,n)  cin>>b[i];
}

void sub1()
{
    FOR(i,1,n)
        ans[0][i]=a[i];
    
    FOR(i,1,maxx)
        FOR(j,1,n)
            ans[i][j]=ans[i-1][b[j]];
        
    FOR(i,0,q-1)
        cout<<ans[query[i].fi][query[i].se]<<"\n";
}
 bool vs[maxn];
vector <int> adj[maxn];
int h[maxn];
int par[maxn][25];


void dfs(int u,int p ,int lvl)
{
    vs[u]=1;
    h[u]=lvl;
    par[u][0]=p;
    for(int v:adj[u])
        if(v!=p&&vs[v]==0) 
            dfs(v,u,lvl+1);
}

void full()
{

    FOR(i,1,n)
        adj[i].pb(b[i]),adj[b[i]].pb(i);
    FOR(i,1,n)
        if(vs[i]==0)
            dfs(i,i,0);
    FOR(i,1,19)
        FOR(j,1,n)
            par[j][i]=par[par[j][i-1]][i-1];
  //  FOR(i,1,n)
    //    cout<<h[i]<<' ';
    FOR(i,0,q-1)
    {
        int u=query[i].se;
        int k=min(query[i].fi,h[u]);
        FOR(j,0,19)
            if(BIT(k,j))
                u=par[u][j];
     //       cout<<u<<' ';
        cout<<a[u]<<'\n';
    }
}
void lds_go_goooo()
{
   
    FOR(i,1,q)
    {
        int u,v;
        cin>>u>>v;
        query.pb({u,v});
        maxx=max(maxx,u);
    }
    
    if(maxx<=150)
    {
        sub1();
        return;
    }
    else
    {
      //  cout<<2222;
        full();
        return;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "EXERCISE"
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
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

