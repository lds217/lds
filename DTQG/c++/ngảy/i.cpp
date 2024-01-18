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
vector <int> a[10000];
void input()
{
    cin>>n>>m;
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            int u;
            cin>>u;
            a[i].pb(u);
        }
        sort(ALL(a[i]));
        a[i].pb(i);
    }
}

bool cmp(vector <int> a, vector <int> b)
{
    FOR(i,0,m-1)
        if(a[i]==b[i]) continue;
        else    if(a[i]>b[i])return false;
    return true;
}
ll dp[maxn];

void lds_go_goooo()
{
    sort(a+1,a+n+1);
    ll res=0;
    vector <int> ans[maxn];
    FOR(i,1,n)
    {
        dp[i]=1;
        FOR(j,1,i-1)
            if(cmp(a[j],a[i])) dp[i] = max(dp[j]+1,dp[i]); 
            ans[dp[i]].pb(a[i].back());
            res=max(res,dp[i]);
    }
    cout<<res<<endl;
    FOR(i,1,res)
        if(ans[i].size())
        {
            cout<<ans[i].size()<<' ';
            for(int j: ans[i])
                cout<<j<<' ';
            cout<<endl;
        }
}

signed main()
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
