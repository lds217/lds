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
typedef vector <int> vi;
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

struct HopcroftKarp{
    vi matchX, matchY, dist;
    int match = 0;
    vector<vi> a;
    int n, m;
    bool lockx[10000];
    bool locky[10000];
    HopcroftKarp() {}
    HopcroftKarp(int _n, int _m){
        n = _n; m = _m;
        a = vector<vi>(n+1);
        matchY = vi(m+1, -1);
        dist = matchX = vi (n+1, -1);
    }
 
    void addEdge(int u, int v) {a[u].pb(v);}
    
    int findPath(){
        int found = 0;
        queue<int> q;
        FOR (i, 1, n){
            if (lockx[i]) continue;
            if (matchX[i] < 0) dist[i] = 0, q.push(i);
            else dist[i] = -1;
        }
        while (!q.empty()){
            int x = q.front(); q.pop();
            for (int y : a[x]){
                if(locky[y]) continue;
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
            if (locky[y]) continue;
            if (matchY[y] < 0 || (dist[matchY[y]] == dist[x]+1 && DFS(matchY[y]))){
                matchY[y] = x; matchX[x] = y;
                return 1;
            }
        }
        return 0;
    }
 
    int maxMatching(){
        while (findPath()){
            FOR (i, 1, n) 
                if (matchX[i] < 0 && !lockx[i]) match += DFS(i);
        }
        return match;
    }

    

};

// End of template//
int n,m,cnt[2] = {0},dem;
int id[5000][5000];
char a[5000][5000];
void input()
{
    cin>>n>>m;
    FOR(i,1,n)
        FOR(j,1,m)
        {   
            cin>>a[i][j];
            //++dem;
            if(a[i][j]!='#') id[i][j] = (++cnt[(i+j)%2]);
           
        }
}


void lds_go_goooo()
{
    //k*4*k
    // n* m *n * sqrtn
    //(mxn-2k) 
    //ll k=-(cnt-m*n)/2;
    ll k=(cnt[0]+cnt[1])/2;
    if(k*(k-1)>=1000000)
    {
        return cout << 1000000, void();
    }
    if(cnt[0]!=cnt[1])
    {
       if (2*k*(2*k-1)/2 >= 1000000) cout << 1000000;
        else cout << 2*k*(2*k-1)/2 << endl;
        return;
    }
    
   
    
    //k/=2;
    HopcroftKarp minhanh(k,k);
    ll ans=k*(k-1);
    //cout<<ans<<endl;
    FOR(i,1,n)
        FOR(j,1,m)
        {
            if((i+j)%2)   {continue;}
            if(a[i][j]=='#')    continue;
            if(i-1>=1&&a[i-1][j]!='#') 
            { 
                minhanh.addEdge(id[i][j],id[i-1][j]);
                
               // ans+=(minhanh.maxMatching()<k-1?1:0);
            }
            
            if(i+1<=n&&a[i+1][j]!='#')
            {   
                minhanh.addEdge(id[i][j],id[i+1][j]);
              //  ans+=(minhanh.maxMatching()<k-1?1:0);
            }
            
            if(j+1<=m&&a[i][j+1]!='#')  
            {
                minhanh.addEdge(id[i][j],id[i][j+1]);
               // ans+=(minhanh.maxMatching()<k-1?1:0);
            }
            //ans+=(minhanh.maxMatching()<k-1?1:0);
            if(j-1>=1&&a[i][j-1]!='#')  
            {
                minhanh.addEdge(id[i][j],id[i][j-1]);
               // ans+=(minhanh.maxMatching()<k-1?1:0);
            }
        }
        
    int hehe= minhanh.maxMatching();
    //cout<<hehe<<endl;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++)
        {
             //minhanh.del(i,j);
             
             minhanh.lockx[i]=minhanh.locky[j]=1;
            if(minhanh.matchX[i]!=-1)
            {
                 minhanh.matchX[i]=minhanh.matchY[minhanh.matchX[i]]=-1;
                 minhanh.match--;
            }
            if(minhanh.matchY[j]!=-1)
            {
                minhanh.matchY[j]=minhanh.matchX[minhanh.matchY[j]]=-1;
                minhanh.match--;
            }
             if(minhanh.maxMatching()!=k-1)
             {
                ans++; 
             }
             minhanh.lockx[i]=minhanh.locky[j]=0;
            
             //minhanh.lock[i]=minhanh.lock[j]=0;
             if(ans>=1000000)
             {
                cout<<ans;
                return;
             }
        }

    cout<<ans;
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
/*
 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Le Thanh Dat
  `Y8P'
   `Y'
   
*/
