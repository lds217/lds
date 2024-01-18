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
const ll maxn = 2e6 + 100;
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
ll n,m;
ll pw[maxn];
void input()
{
    cin>>n>>m;
}

void prepare()
{
    pw[0]=1;
    FOR(i,1,1000006)
        pw[i]=pw[i-1]*2,pw[i]%=1000000007;
}

ll f(int x)
{
    return 1LL*(x-1)*x/2;
}
void lds_go_goooo()
{
    vector <int> ans;
   if(f(n)<m)
    {
        cout<<-1;
        return;
    }
   // ll ans=0;
    FOR(i,1,n)
        if(f(n-i)>=m)   ans.pb(i);//=i*pw[i-1];
        else
        {
            ll tmp=m-f(n-i);
          //  cout<<tmp<<endl;
            ans.pb(tmp+i);//*pw[i-1];
            ll k=n;
            FOR(j,i+1,n) {
                    if(k==i+tmp) k--;
                    ans.pb(k);
                    k--;
                }
                break;
        }
    //reverse(ALL(ans));
    ll anss=0;
    int cnt=0;
    for(int i:ans)
        anss+=pw[cnt++]*i,anss%=1000000007;//cout<<i<<' ';
   cout<<anss;
    
    //cout<<ans;
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
    prepare();
    ll test_case = 1;  cin>>test_case;
    while (test_case--)
    {
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}

