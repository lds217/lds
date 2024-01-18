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
#define task "rbtree"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e5 + 100;
const ll mod = 111539786;
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

bool check[1005][1005];
ll dp[105][105][5000];
ll n,m,k,s;
void input()
{
    cin>>m>>n>>k>>s;
    FOR(i,1,s)
    {
        int u,v;cin>>u>>v;
        check[u][v]=1;
    }
}


void lds_go_goooo()
{
   // dp[0][0][0]=1;
   // FOR(i,1,m)  dp[i][0][0]=1;
   // FOR(i,1,n)  dp[0][i][0]=1;
    // gọi dp[i][j][c] là số cách để tạo ra mê cung thỏa
    // tại ô thứ (i,j) khi đã sử dụng được c cạnh
   // FOR(i,0,m)
    //    FOR(j,0,n) dp[i][j][0]=1;
    /*

    */
    ll e = s+k-1+(n+1)*(m+1);
    e-=(m+n);
    dp[0][n][0]=1;
    //cout<<e<<endl;
    //ll ans=0;
    FOR(i,1,m)
        FOR(j,1,n)
            FOR(c,1,e)
            {
                if(c>=2)
                {
                    if(j==1) (dp[i][j][c]+=dp[i-1][n][c-2])%=mod;
                    else (dp[i][j][c]+=dp[i][j-1][c-2])%=mod;
                }
                if(!check[i][j])
                {
                    if(i!=m&&!check[i+1][j])
                    {
                        if(j==1) (dp[i][j][c]+=dp[i-1][n][c-1])%=mod;
                        else    (dp[i][j][c]+=dp[i][j-1][c-1])%=mod;
                    }
                    if(j!=n&&!check[i][j+1])
                    {
                        if(j==1) (dp[i][j][c]+=dp[i-1][n][c-1])%=mod;
                        else    (dp[i][j][c]+=dp[i][j-1][c-1])%=mod;
                    }
                }
                   
            }
    //ll ans=0;
    //FOR(i,1,e)
        cout<<dp[m][n][e]<<endl;
   // cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
