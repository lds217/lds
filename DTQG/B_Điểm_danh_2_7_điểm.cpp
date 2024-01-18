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
const ll maxn = 1e5 + 100;
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
int n,k1,k2;
void input()
{
    cin>>n>>k1>>k2;
}
//Tấn sẽ được đi thi cuối kỳ nếu Tấn sủi không quá k1 ngày và không đi học muộn k2 ngày liên tiếp.
// XXXX

ll dpnext[20][20],dp[20][20];


void lds_go_goooo()
{
    dp[0][0]=1;
    FOR(i,1,n)
    {
        
        FOR(j,0,k1)
            FOR(z,0,k2-1)
            {
                //học
                (dpnext[j][0]+=dp[j][z])%=mod;
                //nghỉ
                (dpnext[j+1][0]+=dp[j][z])%=mod;
                //đi trễ
                (dpnext[j][z+1]+=dp[j][z])%=mod;
            }
         FOR(j,0,k1)
            FOR(z,0,k2-1)
                dp[j][z]=dpnext[j][z],dpnext[j][z]=0;
    }
        ll ans=0;
        FOR(i,0,k1) 
            FOR(j,0,k2-1)
                (ans+=dp[i][j])%=mod;
    cout<<ans;

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

