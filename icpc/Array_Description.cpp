#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-tree-vectorize")
#define           task      "a"
#define           ll        long long
#define           FORE(i, v)  for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define           ed        << "\n";
#define           el        cout<<'\n';
#define           ALL(s)      s.begin(),s.end()
#define           fi        first
#define           se        second
#define           SQ(a)       (a)*(a)
#define           A(a)        abs(a)
#define           SZ(a)       ((int)(a.size()))
#define           REP(i,a,b)    for (int i = (a), _b = (b); i < _b; i++)
#define           FOR(i,a,b)    for (int i = (a), _b = (b); i <= _b; i++)
#define           FOD(i,r,l)    for(int i=r; i>=l; i--)
#define           MASK(x)     (1LL << (x))
#define           BIT(x, i)   ((x) & (1ULL << (i)))
#define           pii         pair<int,int>
#define           pll         pair<ll,ll>
#define           db          double
#define           II(a, b)    make_pair((a),(b))
#define           pb(x)       push_back(x)
#define           ull unsigned long long

#define int long long
const int MOD = 1e9 + 7;
void sol(){
  int n, m;
  cin>>n>>m;
   vector<int> a(n +1, 0);
  FOR(i, 1, n)  cin>>a[i];

  // dp[i][j] is the number of satisfied array at i and we choose j
  // if we choose j, we must add the count of previous but -1, 0, + 1
  int dp[n + 5][m + 5];
  memset(dp, 0, sizeof(dp));
  
  if (a[1]==0)
    FOR(i,1, m)
      dp[1][i]=1;
  else
    dp[1][a[1]] = 1;
  FOR(i, 1, n)
    if (a[i] == 0)
      FOR(j, 1, m) {

        (dp[i][j] += (dp[i-1][j]+ (dp[i-1][j+1] +  dp[i-1][j-1])% MOD) % MOD)%= MOD;
   
      }
    else {
      (dp[i][a[i]] += ((dp[i-1][a[i]-1] + dp[i-1][a[i]]) % MOD+ dp[i-1][a[i]+1]) % MOD) %MOD;
    }

  int ans = 0;
  FOR(i, 1, m)
    (ans += dp[n][i])%= MOD;
  cout<<ans;
}

// What are you doing here, Jimmy?
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;  // cin >> t;
    while(t -- ) sol();
    return 0;
}