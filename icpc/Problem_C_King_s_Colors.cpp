#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

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



const int MOD = 1e9 + 7;
const int mod = MOD;
#define N 2501
#define LL long long

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


LL fac[N], ifac[N];

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

inline void precompute(){
    int i;
    fac[0] = 1;
    for (i = 1; i < N; i++){
        fac[i] = (i * fac[i - 1]) % MOD;
    }
    ifac[N - 1] = PowerMod(fac[N - 1], MOD - 2);
    for (i = N - 2; i >= 0; i--){
        ifac[i] = ((i + 1) * ifac[i + 1]) % MOD;
    }
}

LL com(int n, int r){
    LL ret = fac[n];
    ret *= ifac[r];
    ret %= MOD;
    ret *= ifac[n - r];
    ret %= MOD;
    return ret;
}

void sol(){
  long long n, k;
  cin>>n>>k;
  FOR(i,1,n-1) {
    int tmp;
    cin>>tmp;
  }
  long long sign = 1;
  long long ans = 0;
  
  FOD(i, k, 1) {
    long long cur = (mul(i, opt_pw(i - 1, n-1, mod)) * com(k, i)) % mod;
    ans = add(ans, cur * sign);
    sign *= -1;
  }
  cout<<ans;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
   // ReadInp();
    precompute();
    int t = 1;  // cin >> t;
    while(t -- ) sol();
    return 0;
}
