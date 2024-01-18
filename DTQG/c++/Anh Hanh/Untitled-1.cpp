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
#define f first
#define s second
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

template <class T>
bool minimize(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool maximize(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//
int n, x, y, k, delta, dem;
double ans, mi = 1e9;
bool check;
vector<pair<double, int>> a, b;
vector<int> vec[220800];
bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.f > y.f;
}
signed main()
{
    //	freopen("discounts.inp","r",stdin);
    //    freopen("discounts.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> delta >> n >> k;
    FOR(i,1,n)
    {
        cin >> x >> y;
        if (y == 1)
            b.pb({x, i});
        else
            a.pb({x, i});
    }
    sort(ALL(a), cmp);
    sort(ALL(b), cmp);
    FOR(i,0,b.size()-1)
    {
        if (dem != k - 1)
        {
            ++dem;
            ans += b[i].f / 2.0;
            vec[dem].pb(b[i].s);
        }
        else
        {
            mi = min(mi, b[i].f);
            ans += b[i].f;
            check = true;
            vec[k].pb(b[i].s);
        }
    }
    FOR(i,0,a.size()-1)
    {
        if (dem != k - 1)
        {
            ++dem;
            ans += a[i].f;
            vec[dem].push_back(a[i].s);
        }
        else
        {
            mi = min(mi, a[i].f);
            ans += a[i].f;
            vec[k].push_back(a[i].s);
        }
    }

    if (check)
        ans -= mi / 2.0;
    cout << setprecision(1) << fixed << ans << '\n';
    for (int i = 1; i <= k; ++i)
    {
        cout << vec[i].size() << " ";
        for (int j : vec[i])
            cout << j << " ";
        cout << '\n';
    }
}
/*
 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Le Thanh Dat
  `Y8P'
   `Y'

*/
