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
  int n;
  cin>>n;
  pair<int,int> a[3];//x, y, z
  cin>>a[0].fi>>a[0].se>>a[1].fi>>a[1].se>>a[2].fi>>a[2].se;
  FOR(i, 1, n) {
    a[0].fi = a[0].fi * 3;
    a[1].fi = a[1].fi * 3;
    a[2].fi = a[2].fi * 3;
    int cnt = 0;
    FOR (i, 0, 2) {
      cnt += (a[i].fi / a[i].se == 1 && a[i].fi != a[i].se ? 1 : 0);
      a[i].fi %= a[i].se;
    }
    if (cnt >= 2){
      cout<<0;
      return;
    }
  }
  cout<<1;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;  // cin >> t;
    while(t -- ) sol();
    return 0;
}