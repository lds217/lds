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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1, 0), cnt(n + 2, 0), cur(n +1, 0);
  FOR(i, 1, n)  {
    cin>>a[i];
    cnt[a[i]]++;
  }
  FOR(i,0,n)  {
    if (cnt[i]% k ) {
        cout<<0<<endl;
        return;
    }
    cnt[i]/=k;
  }

  int res = 0;
  for(int l = 1, r = 1; r>=l && r <= n; r++) {
    cur[a[r]]++;
    while (cur[a[r]] > cnt[a[r]]) {
        cur[a[l]]--;
        l++;
      }
    res += (r - l + 1);
  }
  cout<<res<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;  cin >> t;
    while(t -- ) sol();
    return 0;
}