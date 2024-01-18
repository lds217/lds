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
const ll mod = 1e9+7;
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
ll n,k;
int a[maxn];
int pre[maxn];
int dp[21][500005];

int sol(int l,int r,int mid,int val)
{
    return val*(mid-l+1)-(pre[mid]-pre[l-1])+ -val*(r-mid) + (pre[r]-pre[mid]);
}

ll calc(int l,int r)
{
    if(l==r)    return 0;
    int median=(r+l)/2;
    int mid=(a[median]+a[median+1])/2;
    return min({sol(l,r,median,a[median]),sol(l,r,median+1,a[median+1]),sol(l,r,median,mid)});

   
}

void comp(int i,int l,int r,int optl,int optr)
{
    if(r<l) return;
    int mid=(l+r)/2;
    ii best={inf,-1};
    FOR(j,optl,min(optr,mid))
        if(minimize(best.fi,calc(j,mid)+dp[i-1][j-1]))
            best.se=j;
    ll opt=best.se;
    dp[i][mid]=best.first;
    comp(i,l,mid-1,optl,opt);
    comp(i,mid+1,r,opt,optr);
}


void lds_go_goooo()
{
    cin>>n>>k;
    FOR(i,1,n)
        cin>>a[i];
    
    sort(a+1,a+n+1);
    FOR(i,1,n)
        pre[i]+=a[i]+pre[i-1]; 
    // FOR(i,1,n)
    //     cout<<pre[i]<<' ';
    // cout<<endl;
    FOR(i,1,n)
        dp[1][i]=calc(1,i);//cout<<dp[1][i]<<" ";
    
    FOR(i,2,k)
        comp(i,1,n,1,n);
    cout<<dp[k][n];
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
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}
