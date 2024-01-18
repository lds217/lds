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
#define int ll
using namespace std;
typedef int64_t ll;
typedef vector <int> vi;
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

struct Hopcroftkarp{
    vi dist, matchX, matchY;
    vector<vi> a;
    int n, m;
 
    Hopcroftkarp() {}
    Hopcroftkarp(int _n, int _m){
        n = _n; m = _m;
        a = vector<vi> (n+1);
        //matchX = vi(n+1,-1);
        dist = matchX = vi(n+1, -1);
        matchY = vi(m+1, -1);        
    }
 
    void addEdge(int u, int v){a[u].pb(v);}
 
    int findPath(){
        int found = 0;
        queue<int> q;
        FOR (i, 1, n){
            if (matchX[i] < 0) dist[i] = 0, q.push(i);
            else dist[i] = -1;
        }
 
        while (!q.empty()){
            int x = q.front(); q.pop();
            for (int y : a[x]){
                if (matchY[y] < 0) found = 1;
                else if (dist[matchY[y]] < 0){
                    dist[matchY[y]] = dist[x] + 1;
                    q.push(matchY[y]);
                }
            }
        }
 
        return found;
    }
 
    int DFS(int x){
        for (int y : a[x]){
            if (matchY[y] < 0 || (dist[matchY[y]] == dist[x] + 1 && DFS(matchY[y]))){
                matchY[y] = x; matchX[x] = y;
                return 1;
            }
        }
        return 0;
    }
 
    int maxMatching(){
        int match = 0;
        while (findPath()){
            FOR (i, 1, n)
                if (matchX[i] < 0) match += DFS(i);
        }
        return match;
    }

};

vector <int> ans;
int n,m,k;

vector<int> adj[250];
char a[250];
char b[250];
int ind[250][250];
void input()
{
    cin>>n>>m>>k;
    FOR(i,1,n+m)
        cin>>a[i],a[i]-='0';
    FOR(i,1,n+m)
        cin>>b[i],b[i]-='0';
}
bool vis[205];
bool Find(int u,bool state)
{
    if(a[u]!=b[u]&&state==1)  
    {
        a[u]=1-a[u];
        return 1;
    }
    vis[u]=1;
    for(int v : adj[u])
    {
        if(vis[v])continue;
        
        if(Find(v,1))
        {
            int tmp=u,tmp2=v;
            if(tmp2<tmp)
            swap(tmp,tmp2);
            ans.pb(ind[tmp][tmp2-n]);
            return 1;
        }
    }
    return 0;
}

void lds_go_goooo()
{
    Hopcroftkarp ma(n,m);
     FOR(i,1,k)
    {
        int u,v;
        cin>>u>>v;
        ind[u][v]=i;
        adj[u].pb(v+n);
        adj[v+n].pb(u);
        if(a[u]!=b[u]&&a[v+n]!=b[v+n])  ma.addEdge(u,v);
    }
    
    ma.maxMatching();
    FOR(i,1,n)
    {
        if(ma.matchX[i]!=-1)
        {
            a[i]=1-a[i],a[n+ma.matchX[i]]=1-a[n+ma.matchX[i]];
            ans.pb(ind[i][ma.matchX[i]]);
        }
    }
    queue<int> q;
    FOR(i,1,n+m)
        if(a[i]!=b[i])
            q.push(i);
        
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        if(a[u]==b[u])continue;
        mset(vis,0);
        if(!Find(u,0))   
        {   
            cout<<-1;   return;

        else
            a[u]=1-a[u];

    }
    cout<<ans.size()<<endl;
    for(int i: ans)
        cout<<i<<' ';
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
/*
 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Le Thanh Dat
  `Y8P'
   `Y'
   
*/
