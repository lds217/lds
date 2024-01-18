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
const ll maxn = 2e3 + 100;
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
#define int ll
int __gcd(int a, int b) { 
    if (b == 0) { 
        return a; 
    } 
    return gcd(b, a % b); 
}

// End of template//
struct Point{
    int x,y;
} p[maxn];

int n;
void input()
{
    cin>>n;
    FOR(i,1,2*n)
        cin>>p[i].x>>p[i].y;
}



void lds_go_goooo()
{

    FOR(i,1,n)
    {
        map <ii,int> m;
        FOR(j,1,2*n)
        {
            int X=p[j].x-p[i].x;
            int Y=p[j].y-p[i].y;
            int gcd=__gcd(X,Y);
            if(j>=n+1)
            {
                if(m[{X/gcd,Y/gcd}]!=0)
                {
                    cout<<i<<' '<<m[{X/gcd,Y/gcd}]<<' '<<j<<endl;
                    return;
                }
            }
            else
                if(i!=j)   
                    m[{X/gcd,Y/gcd}]=j;

            }
    }

    FORD(i,2*n,n+1)
    {
        map <ii,int> m;
        FORD(j,2*n,1)
        {
            int X=p[j].x-p[i].x;
            int Y=p[j].y-p[i].y;
            int gcd=__gcd(X,Y);
            if(j<=n)
            {
                if(m[{X/gcd,Y/gcd}]!=0)
                {
                    cout<<i<<' '<<m[{X/gcd,Y/gcd}]<<' '<<j<<endl;
                    return;
                }
            }
            else
                if(i!=j)   
                    m[{X/gcd,Y/gcd}]=j;

            }
    }
   
   
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
/*
 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Ét <3 Su
  `Y8P'
   `Y'
   
*/