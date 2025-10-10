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

#define int long long
void sol(){
  int n;
  cin>>n;
  double ans = INT_MAX;
  while(n--) {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double a = (y2 - y1) / (x2 - x1);
    double b = y1 - a * x1;
    if (b >= 0 && x1 * x2 <= 0)
      ans = min(ans , b);
  }
  if (ans == INT_MAX) {
    cout<<"-1.0";
  } else {
    cout<<fixed<<setprecision(16)<<ans;
  }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;  // cin >> t;
    while(t -- ) sol();
    return 0;
}