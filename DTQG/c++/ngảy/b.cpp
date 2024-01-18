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
#define task "rbtree"

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
int n,m;
int dp[maxn][3];
int vis[maxn][3];
bool found[maxn][3];
vector <int> adj[maxn][3];
void input()
{
    cin>>n>>m;
    mset(dp,-1);
    FOR(i,1,m)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u][c-1].pb(v);
       
    }
}

bool check(int u,int c)
{
    
    if(vis[u][c]==2)return 0;
    if(vis[u][c]==1) return found[u][c]=1;
    //if(u==4)
        //cout<<"hiii";
    if(found[u][c]) return 1;
    vis[u][c]=1;
    
    for(int v: adj[u][1-c])
        if(check(v,1-c))
            return found[u][c]= 1;
    vis[u][c]=2;
    return 0;
}

int dfs(int u, int c)
{
    if(dp[u][c]!=-1)    return dp[u][c];
    int best=0;
    for(int v: adj[u][1-c])
    {
        //if(check(u,1-c))    continue;
        best=max(best,dfs(v,1-c)+1);
    }
    return (dp[u][c]=best);
    
}


void lds_go_goooo()
{ 
    FOR(i,1,n)
    {
        if(check(i,0)||check(i,1))  cout<<-1<<endl;
        else    cout<<max(dfs(i,0),dfs(i,1))<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
