// cre: Nguyen Ngoc Hung - Train VOI 2024 :>

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

using namespace std;

#define    SORT_UNIQUE(v)  sort(ALL(v)),(v).resize(unique(ALL(v))-(v).begin())
#define        __nnhzzz__  signed main()
#define          BIT(i,j)  ((i>>j)&1LL)
#define           MASK(i)  (1LL<<i)
#define           RALL(x)  (x).rbegin(),(x).rend()
#define            ALL(x)  (x).begin(),(x).end()
#define             SZ(x)  (int)(x).size()
#define                fi  first
#define                se  second
#define               INF  0x3f3f3f3f
#define                ll  long long
#define               ull  unsigned long long
#define                ld  long double
#define                vi  vector<int>
#define               vvi  vector<vi>
#define              vvvi  vector<vvi>
#define             vvvvi  vector<vvvi>
#define               pii  pair<int,int>
#define              vpii  vector<pii>
#define      RESET(x,val)  memset((x),(val),sizeof(x))
#define REPDIS(i,be,en,j)  for(int i = (be); i<=(en); i+=j)
#define     REPD(i,be,en)  for(int i = (be); i>=(en); i--)
#define      REP(i,be,en)  for(int i = (be); i<=(en); i++)
//-------------------------------------------------------------//
const int oo = 1e9,LOG = 20,MAXN = 1e4+7,N = 11;
const int MOD = 1e9+7,MOD1 = 1e9+207,MOD2 = 1e9+407,MOD3 = 998244353;
//-------------------------------------------------------------//
template<typename T1, typename T2> bool mini(T1 &a, T2 b){if(a>b){a=b;return true;}return false;}
template<typename T1, typename T2> bool maxi(T1 &a, T2 b){if(a<b){a=b;return true;}return false;}
template<typename T> T gcd(T a, T b) { while(b) { a %= b; swap(a,b); } return a; }
template<typename T> T lcm(T a, T b) { return a/gcd(a,b)*b; }

/*
----------------------------------------------------------------
    END OF TEMPLATE
----------------------------------------------------------------
    Nguyen Ngoc Hung - nnhzzz
    Training for VOI24 gold medal
----------------------------------------------------------------
*/

using T = tuple<int,int,int,int>;

vpii adj[MAXN];
int f[MAXN][N][N];

void solve(){
    int n,m,p,l,k; cin >> n >> m >> p >> l >> k;
    REP(i,1,m){
        int u,v,w; cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    priority_queue<T,vector<T>,greater<T>> heap;
    memset(f,0x3f3f3f3f,sizeof f);
    heap.emplace(0,1,0,0); f[1][0][0] = 0;
    while(SZ(heap)!=0){
        auto [w1,u,l1,k1] = heap.top(); heap.pop();
        if(w1!=f[u][l1][k1]){
            continue;
        }
        if(u==n){
            cout << w1;
            return ;
        }
        for(auto [v,w]:adj[u]){
            if(k1<k && mini(f[v][1][k1+1],w1+p)){
                heap.emplace(f[v][1][k1+1],v,1,k1+1);
            }
            if(l1>0 && l1<l && mini(f[v][l1+1][k1],w1)){
                heap.emplace(f[v][l1+1][k1],v,l1+1,k1);
            }
            if(mini(f[v][0][k1],w1+w)){
                heap.emplace(f[v][0][k1],v,0,k1);
            }
        }
    }
}

__nnhzzz__{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define name "test"
    if(fopen(name".inp","r")){
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }
    #define name1 "nnhzzz"
    if(fopen(name1".inp","r")){
        freopen(name1".inp","r",stdin);
        freopen(name1".out","w",stdout);
    }

    int test = 1;

    while(test--){
      solve();
    }
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
    return 0;
}
