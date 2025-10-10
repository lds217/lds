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

#define int long long
void sol(){
  int n, x;
  cin>>n >>x;
  vector<int> a(n + 1, 0), b(n + 1, 0);
  FOR (i, 1, n)  cin>>a[i];
  FOR (i, 1, n)  cin>>b[i];

  int l = 0, r = 2000000000, tmp = 0, ans_val = 0;
  while(r >= l) {
    int mid = l + (r - l) / 2;
    int cnt = 0;
    FOR(i, 1, n) {
      if (a[i] < mid) continue;
      cnt += (a[i] - mid) / b[i] + 1;
    }
    
    if (cnt >= x) {
      ans_val = mid; 
      tmp = cnt;  
      l = mid + 1;  
    }
    else {
      r = mid - 1;
    }
  }

  long long ans_max = 0;
  FOR(i, 1, n)
  {
    if (a[i] < ans_val) continue;
    long long t = (a[i] - ans_val) / b[i] + 1;
    long long sum_for_item_i = t * a[i] - b[i] * t * (t - 1) / 2;
    ans_max += sum_for_item_i;
  }

  ans_max = ans_max - ans_val * (tmp - x);
  cout<<ans_max<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;  cin >> t;
    while(t -- ) sol();
    return 0;
}