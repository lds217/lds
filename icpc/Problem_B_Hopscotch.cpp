#include<bits/stdc++.h>
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
#define N 1000006
#define LL long long

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
  long long n, x, y;
  cin>>n>>x>>y;
  long long max_steps = min(n/x, n/y);

  long long ans = 0;
  for (int i = 1; i <= max_steps; i++) {
    long long way_x = com(n-i*x + i -1, i -1 );
    long long way_y = com(n-i*y + i -1 , i -1 );
    (ans += (way_x * way_y) %MOD)%= MOD;
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