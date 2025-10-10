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

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef int64_t LL;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

#define            task       "a"
#define             ll        long long
#define          FORE(i, v)   for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define             ed        << "\n";
#define             el        cout<<'\n';
#define            ALL(s)     s.begin(),s.end()
#define             fi        first
#define             se        second
#define            SQ(a)      (a)*(a)
#define            A(a)        abs(a)
#define            SZ(a)      ((int)(a.size()))
#define          REP(i,a,b)    for (int i = (a), _b = (b); i < _b; i++)
#define          FOR(i,a,b)    for (int i = (a), _b = (b); i <= _b; i++)
#define          FOD(i,r,l)    for(int i=r; i>=l; i--)
#define           MASK(x)      (1LL << (x))
#define           BIT(x, i)    ((x) & (1ULL << (i)))
#define           pii          pair<int,int>
#define           pll          pair<ll,ll>
#define           db           double
#define           II(a, b)     make_pair((a),(b))
#define           pb(x)        push_back(x)
#define          ull unsigned long long


int mul(int a, int b) {
    if(a >= mod) a %= mod;
    if(b >= mod) b %= mod;
    return 1ULL * a * b % mod;
}



int add(int a, int b) {
    if(a >= mod) a %= mod;
    if(b >= mod) b %= mod;
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;

    return a;
}

ll opt_mul(ll a, ll b, const ll &p) {
    ll res = 0;

    a %= p;
    b %= p;

    while(b) {
        if(b & 1) {
            res = res + a;
            if(res >= p)
                res -= p;
        }

        a = a + a;

        if(a >= p) a -= p;
        b >>= 1;
    }
    return res;
}

long long opt_pw(ll a, ll b,const ll &p) {
    ll res = 1;
    while(b) {
        if(b & 1) res = opt_mul(res, a, p);
        a = opt_mul(a, a, p);
        b = b >> 1;
    }
    return res;
}

int pw(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1)
            res = mul(res, a);
        b = b >> 1;
        a = mul(a, a);
    }
    return res;
}

ll lt(int a, int b) {
    ll res = 1;
    while(b) {
        if(b & 1)
            res = 1LL * res * a;
        b = b >> 1;
        a = 1LL * a * a;
    }
    return res;
}


LL PowerMod(LL a, LL n){
    LL ret = 1;
    while (n){
        if (n & 1){
            ret *= a;
            ret %= MOD;
        }
        a *= a;
        a %= MOD;
        n /= 2;
    }
    return ret;
}


void sol(){
  long long n, k, p;
  cin >> n >> k >>p;
  //  int tmp = 0;
  //  int cnt = 0;
    vector<long long> ans;
    for(int i = 1; i * i <= n; i ++) {
        if (n % i == 0) {
            if (k >= i && n/i <= p)
                ans.pb(i);
            
            if (i*i != n && k >= n/i && i <= p)
                ans.pb(n/i);
        }
    }
    sort(ALL(ans));
    cout<<ans.size()<<endl;
    for(int i : ans)
        cout<<i<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;// cin >> t;
    while(t -- ) sol();
    return 0;
}



