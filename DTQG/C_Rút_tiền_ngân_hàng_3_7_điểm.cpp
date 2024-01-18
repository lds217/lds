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
int n,m;
struct Data{
    int a,t,p;
} v[maxn];


void input()
{
    cin>>n>>m;
    m++;
    FOR(i,1,n)
    {
        int a,t,p;
        cin>>a>>t>>p;
        t++;
        v[i]={a,t,p};
    }
}

int dp[100005][105];

void lds_go_goooo()
{
    sort(v+1,v+n+1,[](Data a, Data b){
        return a.t<b.t;
    });
    // FOR(i,1,n)
        // cout<<v[i].a<<' '<<v[i].t<<' '<<v[i].p<<endl;
    

    FOR(i,1,n)
        FOR(j,1,m)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(v[i].t>=j&&j-v[i].p>=0)
                dp[i][j]=max(dp[i][j],dp[i-1][j-v[i].p]+v[i].a);
        }
        
    // FOR(i,1,n)
        // FOR(j,1,m)
            // cout<<dp[i][j]<<" \n"[j==m];
    //    cout<<endl;
    cout<<dp[n][m];
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
 `Y888P'      Ét <3 Su
  `Y8P'
   `Y'
   
*/
