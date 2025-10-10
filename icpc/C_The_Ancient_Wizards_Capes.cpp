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

const int mod = 676767677; 

int check(int n, const vector<long long>& a, char initial_cape) {
    vector<char> c(n + 5);
    c[0] = initial_cape;
    FOR(i,1,n-1){
      long long diff = a[i] - a[i - 1];
      int righc = (c[i - 1] == 'R');
      if (diff + righc == 1) {
        c[i] = 'L'; 
      } else if (diff + righc == 0) {
        c[i] = 'R';
      } else {
        return 0;
      }
    }
    vector<int> prefix_L(n + 5, 0);
    vector<int> suffix_R(n + 5 , 0);
    prefix_L[0] = (c[0] == 'L');
    FOR(i,1,n) {
      prefix_L[i] = prefix_L[i-1] + (c[i] == 'L');
    }
    suffix_R[n - 1] = (c[n -1] == 'R');
    FOD(i, n-2, 0) {
      suffix_R[i] = suffix_R[i + 1] + (c[i] == 'R');
    }
    REP(i,0,n) {
      if (a[i] != prefix_L[i] + suffix_R[i]) {
        return 0;
      }
    }
    return 1;
}

void sol(){
  int n;
  cin>>n;
  vector<long long > a(n);
  FOR(i,0,n-1)
    cin>>a[i];

  if (n==1)
  {
    cout<<2<<"\n";
    return;
  }
  long long ans = 0;
  ans = check(n, a, 'L');
  ans+= check(n, a, 'R');
  cout<<ans<<"\n";
}

// 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;   cin >> t;
    while(t -- ) sol();
    return 0;
}