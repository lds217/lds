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
  int n, k, c;
  cin>>n>>k>>c;
  queue<int> q;
  int cnt =0;
  vector<int> school(n + 1, 0);
  FOR(i, 1, n) {
    int id, x;
    cin>>id>>x;
    school[x]++;
    if(k && school[x] <= c) {
      cout<<id<<"\n";
      k--;
    }
    else 
      q.push(id);
  }
  while(k && !q.empty()) {
    cout<<q.front()<<"\n";
    q.pop();
    k--;
  }
}

// What are you doing here, Jimmy?
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;  // cin >> t;
    while(t -- ) sol();
    return 0;
}