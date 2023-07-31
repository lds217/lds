#include <bits/stdc++.h>
using namespace std;

#define For(i, a, b) for (int i = a, _b = (b); i <= _b; i++)
#define Rep(i, a, b) for (int i = (a); i < (b); ++i)
#define Fob(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define Debug(a,l,r) for (int i = l; i <= r; i++) cout << a[i] << " "; cout << endl
#define nl cout << endl
#define el printf("\n")
#define pb push_back
#define pf push_front
#define X first
#define Y second
#define rounding(x) fixed << setprecision(x)
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Fr(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ll long long
#define ldb long double
#define str string
#define ii pair<int,int>
#define IV inline void
#define IF inline ll

const ll N = 100001;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;

template <class X, class Y>
  X Max(X x, Y y) {
    return (x > y) ? x : y;
  }
template <class X, class Y>
  X Min(X x, Y y) {
    return (x < y) ? x : y;
  }
template <class T>
  T Abs(const T &x) {
    return (x < 0 ? -x : x);
  }
template <class X, class Y>
  X Gcd(X x, Y y) {
    if (y == 0)
      return x;
    return Gcd(y, x % y);
  }
template <class X, class Y>
  X Pow(X x, Y k) {
    ll res = 1, mul = x;
    while (k > 0) {
      if (k & 1)
        res = 1LL * res * mul % MOD;
      mul = 1LL * mul * mul % MOD;
      k >>= 1;
    }
    return res;
  }
template<class X, class Y>
  bool maximize(X &x, Y y){
    if (x < y) {
      x = y;
      return true;
    }
    return false;
  }
template<class X, class Y>
  bool minimize(X &x, Y y) {
    if (x > y){
      x = y;
      return true;
    }
    return false;
  }

IF lcm (int x, int y) { 
  return (x/Gcd(x,y))*y; 
}

#define TASK "TEST"
#define FIL "copy"
IV JUDGE(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen(TASK ".inp", "r")) {
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
  }
  if (fopen(FIL ".inp", "r")) {
    freopen(FIL ".inp", "r", stdin);
    freopen(FIL ".out", "w", stdout); 
  }
} 
IV time_calc(void) {
  cerr << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms";
}

IV add (int &a, int b, int mod=mod) {
  a+=b;
  if (a>=mod) a-=mod;
}
IV sub (int &a, int b, int mod=mod) {
  a-=b;
  if (a<0) a+=mod;
}

inline ll prod (const vector<ll> &a, const vector<ll> &b) {
  ll sum=0;
  for(int i : a) sum += i;
  ll val=sum;

  Rep(i,0,b.size()-1) val += Min(sum,b[i]);
  return val;
}

int main() {
  JUDGE(); 
  ll t=1;
  //cin >> t;
  while (t--) {
    int m,n;
    cin >> m >> n;
    vector<ll> a,b;
    for(int i=1; i<=m; i++) {
      ll x;
      cin >> x;
      a.pb(x);
    }
    for(int i=1; i<=n; i++) {
      ll x;
      cin >> x;
      b.pb(x);
    }
    //sort(all(a));
    //sort(all(b));
   cout<<prod(a,b);
  }

}