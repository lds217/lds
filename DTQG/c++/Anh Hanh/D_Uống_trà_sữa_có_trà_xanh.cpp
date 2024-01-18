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
int n, k;
vector<ii> a, b;
void input()
{
    cin >> n >> k;
    FOR(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        if (v == 1)
            a.pb({u, i});
        else
            b.pb({u, i});
    }
}

void lds_go_goooo()
{
    ll ans = 0;
    ll tmp=k;
    vector<int> trace[maxn];
    sort(ALL(a), greater<ii>());
   // for(auto[u,v]: a)
   //     cout<<u<<' '<<v<<endl;
   int cnt=1;
    FOR(i, 0, a.size() - 1)
    {
        if(cnt==k)  break;
        ans += a[i].fi;
        trace[cnt].pb(a[i].se);
        //cout<<ans/2.0<<endl;
        cnt++;
    }
    ll pos=0;

    if(cnt!=k)
    {
        ll sum=0;
        FOR(i,cnt,k)
        {
            if(cnt==k)
               { FOR(j,pos,b.size()-1)
                trace[cnt].pb(b[j].se);
                sum+=b[j].fi
                break;
               }
            sum+=b[pos].fi;
            trace[cnt].pb(b[pos++].se);
            
            
        }
        
    }
    
  // cout<<ans/2.0<<endl;
    // ll sum = 0;
    // ll minn = inf;
    // cout<<cnt-2<<endl;
    // FOR(j, cnt-1, a.size() - 1)
    //     minn = min(minn, a[j].fi), sum += a[j].fi, trace[k].pb(a[j].se);
    // FOR(i, 0, b.size() - 1)
    //     minn = min(minn, b[i].fi), sum += b[i].fi, trace[k].pb(b[i].se);
    // cout << ans / 2.0 + sum - minn / 2.0 << endl;

    // FOR(i, 0, tmp)
    // {
    //     if (trace[i].size())
    //     {
    //         cout << trace[i].size() << ' ';
    //         for (int j : trace[i])
    //             cout << j << ' ';
    //         cout << endl;
    //     }
    // }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#define task "rbtree"
    // freopen(task".INP", "r", stdin);
    // freopen(task".OUT", "w", stdout);
    int sub = 1;
    cin >> sub;
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
