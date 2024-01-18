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
#define int ll
int n, k;
vector<int> a;
void input()
{
    a.clear();
    cin >> n >> k;
    FOR(i, 1, n)
    {
        int u;
        cin >> u;
        a.pb(u);
    }
}

bool taken[maxn];
bool ck()
{
    FOR(i, 0, n - 1)
    if (taken[i] == 0)
        return 1;
    return 0;
}

bool check(int x)
{
    multiset <int> s;
    FOR(i,0,n-1)
    {
        s.insert(a[i]);
        if(a[i]>x)
            return 0;
    }
    int sets = 0;
    while(!s.empty())
    {
        int tmp=x;
        while(tmp&&!s.empty())
        {
            auto it =s.upper_bound(tmp);
            if(it==s.begin())break;
            it--;
            tmp-=*it;
            s.erase(it);
        }
        sets++;
    }
    if (sets <= k)
        return 1;
    else
        return 0;
}



void lds_go_goooo()
{
    // cout<<check(19)<<endl;
    int l = 0, r = 1e9;
    int ans = 0;
    //cout<<check(9);
    while (l <= r)
    {

        int mid = (l + r) / 2;
        if (check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
#define task "rbtree"
    // freopen(task".INP", "r", stdin);
    // freopen(task".OUT", "w", stdout);
    // int sub=1;
    // cin>>sub;
    ll test_case = 1;
    cin >> test_case;
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
