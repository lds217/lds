#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-tree-vectorize")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O")
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
#define           mp(a, b)  make_pair(a, b)
#define           int long long


void sol(){
  int n;
  cin>>n;
  vector<int> a(n + 1, 0);
  map<int,int> freq;
  FOR(i, 1, n)  
  {
    cin>>a[i];
    freq[a[i]]++;
  }
  int ans = 0, s= 0;
  vector<int> v;
  for(auto x : freq) {
    s += (x.se / 2) * 2 * x.fi;

    if(x.se % 2) {
      if(v.size() == 2) {
        s -=v[0];
        v.erase(v.begin());
      }
      v.pb(x.fi);
        s += x.fi;
    }
    if (s - x.fi > x.fi) ans = max(ans, s);
  }
  cout<<ans ed
}

// What are you doing here, Jimmy?
signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;   cin >> t;
    while(t -- ) sol();
    return 0;
}

