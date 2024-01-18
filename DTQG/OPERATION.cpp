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
const ll inf = 0x3f3f3f3f3f;

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
int n,m,k;
vector <int> adj[maxn];
int dist[21][maxn];
bool checked[maxn];
vector <int> c;

void input()
{
    cin>>n>>m>>k;
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i,1,k)
    {
        int u;
        cin>>u;
        checked[u]=1;
        c.pb(u);
    }
}

void sub2()
{
    int dist[maxn];
    mset(dist,0x3f3f3f3f);
    queue<int> q;
    q.push(c[0]);
    dist[c[0]]=0;
    while(!q.empty())
    {
        int u=q.front();
        if(u==c[1])
        {
            cout<<dist[u];
            return;
        }
        q.pop();
        for(int v: adj[u])
            if(minimize(dist[v],dist[u]+1))
                q.push(v);
    }
    cout<<-1;
}

void bfs(int id)
{
    queue <int> q;
    q.push(c[id]);
    dist[id][c[id]]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v: adj[u])
            if(minimize(dist[id][v],dist[id][u]+1))
                q.push(v);
    }
}

ll dp[MASK(20)+1];

void lds_go_goooo()
{
    if(k%2)
    {
        cout<<-1;
        return;
    }
    if(k==2)
    {
        sub2();
        return;
    }
    mset(dist,0x3f3f3f3f);
    mset(dp,0x3f3f3f3f);
    dp[0]=0;
    FOR(i,0,k-1)
        bfs(i);
    
    FOR(mask,0,MASK(k)-1)
        FOR(i,0,k-1)  
            FOR(j,0,k-1)
            if(i!=j && BIT(mask,j)==0 && BIT(mask,i)==0)
            {
                int newMask=mask|MASK(i)|MASK(j);
                minimize(dp[newMask],dp[mask]+dist[i][c[j]]);
            }  
    if(dp[MASK(k)-1]==inf)
    cout<<-1;
    else    
        cout<<dp[MASK(k)-1];

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "OPERATION"
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