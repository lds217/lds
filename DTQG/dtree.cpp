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
int fin[maxn],fout[maxn];
vector <int> adj[maxn];
void dfsin(int u, int par)
{
    fin[u]=0;
    for(int v:adj[u])
        if(v!=pa||block[v]==0)
        {
            dfsin(v,u);
            fin[u]=max(fin[u],fin[v]+1);
        }
}
 
void update(int &a,int &b, int c)
{
    if(c>a)   b=a,a=c;
    else   b=max(b,c);
}
 
void dfsout(int u, int par)
{
    int first=-1,second=-1;
    for(int v:adj[u])   if(v!=par||block[v]==0)
        update(first,second,fin[v]);
    for(int v:adj[u]) if(v!=par||block[v]==0) 
    {
        fout[v]=max(fout[u]+1,1);
        fout[v]=max(fout[v],(fin[v]==first?second:first)+2);
        dfsout(v,u);
    }
}
int n,q;
void input()
{
    cin>>n>>q;
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }  
}

bool deleted[maxn];
bool block[maxn];
bool started=0;
bool isleaf[maxn];
int dfs(int u,int par)
{
    if(block[u])    return;
    for(int v: adj[u])
    {
        if(v==par)  continue;
        if(deleted[v]==1||isleaf[v]==1&&)
        {
            block[v]=1;
            dfs(v,u);
        }
    }
    adj[u].clear();
}


void lds_go_goooo()
{
    FOR(i,1,n)
        if(adj[u].size()==1)
            isleaf[u]=1;
    while(q--)
    {
        int x;
        cin>>x;
        started=0;
        deleted[x]=1;
        if(isleaf[x])
        {
            dfs(x,-1);
            if(started)
            fout[1]=0;
            dfsin(1,-1);
            dfsout(1,-1);
        }
    }
}

int main()
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

