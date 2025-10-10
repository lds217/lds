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




void sol(){
  int n;
  cin>>n;
  vector<long long> v(2 *n + 1, 0);
  vector<long long> pre(2 *n + 1, 0), suff(2 *n + 2, 0), alternate (2 *n + 1, 0);
  for(int i = 1; i <= 2 *n; i++) {
    cin>>v[i];
    pre[i] = pre[i - 1] + v[i];
    alternate[i] = alternate[i - 1] + (i % 2 ? -1LL : 1LL) * v[i]; 
  }

  for(int i = 2 * n; i >= 1; i--)
    suff[i] = suff[i + 1] + v[i];
  
  for(int k = 1; k <= n; k++) {
    cout<<-pre[k] + suff[2 * n - k + 1] + (k % 2 ? 1LL : -1LL)  * (alternate[2 * n - k] - alternate[k])<<' ';
  }
  cout<<endl;
}

// 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;   cin >> t;
    while(t -- ) sol();
    return 0;
}