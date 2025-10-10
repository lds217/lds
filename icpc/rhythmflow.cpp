#include<bits/stdc++.h>
using namespace std;

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

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

int cost(int x,int y) {
  if (abs(x - y) >=0 && abs(x-y) <= 15) return 7;
  if (abs(x - y) > 15 && abs(x-y) <= 23) return 6;
  if (abs(x - y) > 23 && abs(x-y) <= 43) return 4;
  if (abs(x - y) > 43 && abs(x-y) <= 102) return 2;
  return 0;
}

#define int long long
void sol(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 2), b(m + 2);
  int dp[m + 2][n + 2];
  memset(dp, 0, sizeof(dp));
  FOR (i, 1, n)
    cin >> a[i];

  FOR (i, 1, m)
    cin >> b[i];

  FOR (i, 1, m) {
    FOR (j, 1, n) {
      dp[i][j] = max({dp[i-1][j-1] + cost(a[j], b[i]), dp[i-1][j], dp[i][j-1]});
      //cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<dp[m][n];
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;  // cin >> t;
    while(t -- ) sol();
    return 0;
}