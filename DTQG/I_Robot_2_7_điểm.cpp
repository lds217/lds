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
int a[201][201];
ll dp[201][201][201];
void input()
{
    cin>>n>>m;
    FOR(i,1,n)  
        FOR(j,1,m)
            cin>>a[i][j];
}


int DP(int r1,int c1,int r2,int c2)
{

    if(r1+c1!=n-r2+1+m-c2+1)return INT_MIN;
    if(r1>n||r2>n||r1<=0||r2<=0||c1>m||c1<=0||c2>m||c2<=0)
        return INT_MIN;
    if(r1==n&&c1==m)
        return a[r1][c1];
    
    if(r2==1&&c2==1)
        return a[r2][c2];
    
    ll &res=dp[r1][c1][r2];
    
    if(res!=-1)
        return res;
    res=0;
    res+=max({res,DP(r1+1,c1,r2-1,c2),DP(r1,c1+1,r2,c2-1),DP(r1+1,c1,r2,c2-1),DP(r1,c1+1,r2-1,c2)});
    
    if(r1==r2)
        return res=res+a[r1][c1];
    else
        return res=res+a[r1][c1]+a[r2][c2];
    return res;
}

void lds_go_goooo()
{
    mset(dp,-1);
    cout<<DP(1,1,n,m);//m);
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

