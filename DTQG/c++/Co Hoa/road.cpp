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
#define task "ROAD"

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


struct Flow{
    struct edge{
        int to, rev, flow, cap;
        edge(int _to, int _rev, int _flow, int _cap){
            to = _to; rev = _rev; flow = _flow; cap = _cap;
        }
    };
    int n, m, source, sink;
    vector<int> dist, cur;
    vector<vector<edge>> G;
    
    Flow(){}
 
    Flow(int _n, int _source, int _sink){
        n = _n;
        source = _source;
        sink = _sink;
        dist = vector<int>(n+1, -1);
        cur = vector<int>(n+1, 0);
        G = vector<vector<edge>>(n+1);
    }
 
    void add_edge(int u, int v, int f){
        edge a = edge(v, G[v].size(), 0, f);
        edge b = edge(u, G[u].size(), 0, 0);
        G[u].pb(a);
        G[v].pb(b);
    }
 
    int BFS(){
        FOR (i, 1, n) dist[i] = -1;
        dist[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (edge e : G[u]){
                int v = e.to;
                if (dist[v] < 0 && e.flow < e.cap){
                    dist[v] = dist[u] + 1; q.push(v);
 
                }
            }
        }
        return dist[sink] > 0;
    }
 
    int DFS(int u, int f){
        if (u == sink) return f;
        for (int &i = cur[u]; i < G[u].size(); i++){
            edge &e = G[u][i];
            int v = e.to;
            if (dist[v] == dist[u]+1 && e.flow < e.cap){
                int delta = DFS(v, min(f, e.cap-e.flow));
                if (delta > 0){
                    e.flow += delta;
                    G[v][e.rev].flow -= delta;
                    return delta;
                }
            }
        }
        return 0;
    }

     bool update_edge(int pos,int val){
        G[pos].back().cap-=val;
        if(G[pos].back().flow<=G[pos].back().cap)   return 1;
        else    return 0;
    }

    void reset()
    {
        FOR(i,1,n)
            for(auto &e:G[i])
                e.flow=0;
    }
 
    int max_flow(){
        int ans = 0;
        while (BFS()){
            FOR (i, 1 , n) cur[i] = 0;
            while(int del = DFS(source, inf)){
                ans += del;
            }
        }
        return ans;
    }
 
    vector<pair<int,ii>> show(){
        vector<pair<int,ii>> a;
        FOR (i, 1, n){
            for (auto e : G[i]){
                if (e.flow > 0){
                    a.pb({i, {e.to, e.flow}});
                }
            }
        }
        return a;
    }
 
 
};

int n,m,k;

void input()
{
    cin>>n>>m>>k;
    Flow flow(n+m+2,1,n+m+2);
    FOR(i,1,k)
    {
        int u,v;
        cin>>u>>v;
        flow.add_edge(u+1,n+v+1,1);
    }
    FOR(i,1,n)
        flow.add_edge(1,i+1,1);
    
    FOR(i,1,m)
    {
        int u;
        cin>>u;
        flow.add_edge(i+n+1,n+m+2,u);
    }
    int q;
    cin>>q;
    ll ans=flow.max_flow();
    while(q--)
    {
        cout<<ans<<"\n";
        int u,v;
        cin>>u>>v;
        if(flow.update_edge(u+n+1,v))
            continue;
        else
        {
            flow.reset();
            ans=flow.max_flow();
        }
    }
}


void lds_go_goooo()
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
