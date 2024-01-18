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
const ll maxn = 2e5 + 500;
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
int n,a[maxn],dp[maxn];
int maxx;
void input()
{
    cin>>n;
    FOR(i,1,n)   cin>>a[i],maxx=max(maxx,a[i]);
}


int cnt[maxn];
void sub2()
{
    mset(dp,0x3f);
    ll cnt=0;
    dp[0]=0;
    FOR(i,1,n)
    {
        cnt=0;
        FOR(j,i,n)
        {
            if(a[j]!=j-i+1)
                cnt++;
            dp[j]=min(dp[j],dp[i-1]+cnt);
        }
    }
    cout<<dp[n];
}

void sub3()
{  
    mset(dp,0x3f);
    ll cnt=0;
    dp[0]=0;
    FOR(i,1,n)
    {
        cnt=0;
        FOR(j,i,min(i+201,n))
        {
            if(a[j]!=j-i+1)
                cnt++;
            dp[j]=min(dp[j],dp[i-1]+cnt);
        }
    }
    cout<<dp[n];
}

void sub4()
{  
    mset(dp,0x3f);
    ll cnt=0;
    dp[0]=0;
    FOR(i,1,n)
    {
        cnt=0;
        FOR(j,i,min(n,i+2000))
        {
            if(a[j]!=j-i+1)
                cnt++;
            dp[j]=min(dp[j],dp[i-1]+cnt);
        }
    }
    cout<<dp[n];
}



void lds_go_goooo()
{
    if(n<=2000)
        sub2();
    else
        if(maxx<=200)
            sub3();
        else
            sub4();
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "MSEQ"
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