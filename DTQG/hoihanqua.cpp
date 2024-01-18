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
const ll maxn = 175 + 100;
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
int a[maxn][maxn],dp[maxn][maxn][maxn],c[maxn];
int m,n,k;
void input()
{
    cin>>n>>m>>k;
    FOR(i,1,n)
        cin>>c[i];
    FOR(i,1,n)
        FOR(j,1,m)
            cin>>a[i][j];
    
}

ii first[maxn],second[maxn];

void check(ii &a,ii &b,int val,int pos)
{
    if(a.fi>val)    b=a,a={val,pos};
    else    
        b=min(b,{val,pos});
}

void lds_go_goooo()
{
    mset(dp,0x3f);
    if(c[1])
        dp[1][c[1]][1]=0;
    else
    FOR(i,1,m)
        dp[1][i][1]=a[1][i];

    FOR(i,2,n)
    {
        if(c[i]==0)
            FOR(j,1,m)
                if(i!=2)
                    FOR(l,1,k)
                    {
                        
                        if(first[l].se!=j)
                            dp[i][j][l+1]=first[l].fi+a[i][j];
                        else
                            dp[i][j][l+1]=second[l].fi+a[i][j];
                        dp[i][j][l]=min(dp[i][j][l],dp[i-1][j][l]+a[i][j]);
                    }
                else
                 FOR(z,1,m)
                {
                    FOR(l,1,k)
                    {
                        if(j!=z)
                            dp[i][j][l+1]=min(dp[i][j][l+1],dp[i-1][z][l]+a[i][j]);
                        else
                            dp[i][j][l]=min(dp[i][j][l],dp[i-1][z][l]+a[i][j]);
                    }
                }
        else
            FOR(j,c[i],c[i])
                FOR(z,1,m)
                    FOR(l,1,k)
                        if(j!=z)
                            dp[i][j][l+1]=min(dp[i][j][l+1],dp[i-1][z][l]);
                        else
                            dp[i][j][l]=min(dp[i][j][l],dp[i-1][z][l]);
        
        FOR(l,1,k)
        {
            first[l]=second[l]={inf,0};
            FOR(z,1,m)
                check(first[l],second[l],dp[i][z][l],z);
        }

    }
    ll ans=inf;
    FOR(i,1,m)
        ans=min(ans,dp[n][i][k]);
    if(ans<inf)
        cout<<ans;
    else
        cout<<-1;

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
