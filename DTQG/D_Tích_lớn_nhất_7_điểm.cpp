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
#define int ll
int n,k;
int a[maxn];
void input()
{

    cin>>n>>k;
    mset(a,0);
    FOR(i,1,n)
        cin>>a[i];
}


void lds_go_goooo()
{
    ll ans=1;
    sort(a+1,a+n+1);
    
    if(a[n]<=0&&k%2==0)
    {
        FOR(i,1,k)
            ans=(ans*a[i])%mod;
        cout<<ans;
        return;
    }
    if(a[n]<0&&k%2==1)
    {
        FORD(i,n,n-k+1)
            ans=(ans*a[i])%mod;
        cout<<(ans%mod+mod)%mod;
        return;
    }
    if(a[n]==0&&k%2==1)
    {
        cout<<0;
        return;
    }
    int i=1;int j=n;
    if(k%2==1)
    {
        ans*=a[j];
        ans=(ans%1000000007+1000000007)%1000000007;
        j--;
        k--;
    } 
    k/=2;
    FOR(o,1,k)
    {
        // cout << i << ' ' << j << ' ';
        ll ansL=a[i]*a[i+1];        
        ll ansR=a[j]*a[j-1];
        if(ansL>ansR)
        {   
            // cout << ansL << endl;
            ansL%=1000000007;
            ansR%=1000000007;
            ans*=ansL,ans=(ans%1000000007+1000000007)%1000000007,i+=2;
        }
        else
        {
            // cout << ansR << endl;
            ansL%=1000000007;
            ansR%=1000000007;
            ans*=ansR,ans=(ans%1000000007+1000000007)%1000000007,j-=2;
        }
    }
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
    ll test_case = 1; cin>>test_case;
    while (test_case--)
    {
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}
