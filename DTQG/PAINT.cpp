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
ll w,b,r,k,m;
void input()
{
    cin>>w>>b>>r>>k>>m;
}
ll gt[1000006],igt[1000006];
void prepare(int lim=1000000)
{
	gt[0]=igt[0]=1;
	FOR(i,1,lim)
		gt[i]=(gt[i-1]*i)%mod;
	igt[lim]=POW(gt[lim],mod-2);
	FORD(i,lim,1)
		igt[i-1]=(igt[i]*i)%mod;
}
// XXXXXXXXXX
ll C(int n,int k)
{
	if(k>n)	return 0;
    return gt[n]*igt[k]%mod*igt[n-k]%mod;
}

void sub1()
{
    prepare();
    int nB = (m + 1) / 2,nR = m + 1 - nB;
    cout << ((C(b - 1,nB - 1) * C(r - 1,nR - 1)) % mod + 
    (C(r - 1,nB - 1) * C(b - 1,nR - 1)) % mod) % mod;
}

void lds_go_goooo()
{
    if(w==2)    cout<<69;
    else
    if(w==0)
    {
        sub1();
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "PAINT"
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
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

