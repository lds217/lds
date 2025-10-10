#include <bits/stdc++.h>
using namespace std;

#define MULTITEST 0
#define debug(x) cerr << "Line " << __LINE__ << ": " << #x << "=" << (x) << endl;
#define debugv(v) cerr << "Line " << __LINE__ << ": " << #v << " [ "; for(auto _i:v) cerr << _i << " "; cerr << "]\n";
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;

int MOD = (int)1e9 + 7;

int modpow(int base, int p) {
  int ans = 1;
  while (p > 0) {
    if (p & 1) {
      ans = (ans * base) % MOD;
    }
    base = (base * base) % MOD;
    p >>= 1;
  }
  return ans;
}

void solve() {
  // Write your code here
  int n; cin >> n;
  int m;
  cin>>m;
  vi a(n);
  for (auto &v: a) cin >> v;

  vi fact(max(2LL, n + 1), 1);
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  vi invFact(fact.size(), 1);
  for (int i = 0; i < fact.size(); i++) {
    invFact[i] = modpow(fact[i], MOD - 2);
  }

  vector<array<int, 2>> zeroRange;
  int prev = -1;
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      if (prev != i - 1) {
        zeroRange.push_back({prev, i - 1});
      }
      prev = i;
    }
  }
  if (a[n - 1] == 0) {
    zeroRange.push_back({prev, n - 1});
  }

  int ans = 1;

  auto choose = [&](int a, int b) {
    // a choose b;
    return (((fact[a] * invFact[b]) % MOD)* invFact[a - b]) % MOD;
  };

  for (auto &v: zeroRange) {
    if (v[0] == -1 || v[0] == n - 1) {
      int cnt = modpow(3LL, v[1] - v[0]);
      ans = (ans * cnt) % MOD;
    } else {
      int left = a[v[0]];
      int maxChange = v[1] - v[0];
      int tot = 0;
      for (int j = -1; j <= 1; j++) {
        int right = a[v[1] + 1] + j;
        int diff = right - left;
        if (abs(diff) > maxChange) continue;
        for (int i = 0; i <= maxChange; i++) {
          int j = i - diff;
          if (j > maxChange - i || j < 0) continue;
          int ones = choose(maxChange, i);
          int neg = choose(maxChange - i, j);
          ones = (ones * neg) % MOD;
          tot = (tot + ones) % MOD;
        }
      }
      ans = (ans * tot) % MOD;
      
    }
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  if(MULTITEST) cin >> t;
  else t = 1;
  while (t--) {
    solve();
  }
}