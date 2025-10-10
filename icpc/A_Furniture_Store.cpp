#include<bits/stdc++.h>
using namespace std;

#define            task       "a"
#define             ll        long long
#define          FORE(i, v)   for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define             ed        << "\n";
#define             el        cout<<'\n';
#define            ALL(s)     s.begin(),s.end()
#define             fi        first
#define             se        second
#define            SQ(a)      (a)*(a)
#define            A(a)        abs(a)
#define            SZ(a)      ((int)(a.size()))
#define          REP(i,a,b)    for (int i = (a), _b = (b); i < _b; i++)
#define          FOR(i,a,b)    for (int i = (a), _b = (b); i <= _b; i++)
#define          FOD(i,r,l)    for(int i=r; i>=l; i--)
#define           MASK(x)      (1LL << (x))
#define           BIT(x, i)    ((x) & (1ULL << (i)))
#define           pii          pair<int,int>
#define           pll          pair<ll,ll>
#define           db           double
#define           II(a, b)     make_pair((a),(b))
#define           pb(x)        push_back(x)
#define          ull unsigned long long

vector<int> divs[200005];

void prep() {
    for(int i = 2; i < 200005; i++ ) {
        for(int j = i; j < 200005; j += i) divs[j].pb(i);
    }
}


void sol(){
    int n;
    cin>>n;
    int prev = INT_MAX;
    vector<int> ans;
    FOR(i,1,n) {
      int x;
      cin>>x;
      if (prev < x) {
        ans.pb(i);
      }
      prev = x;
    }
    cout<<ans.size()<<endl;
    for(int i : ans)
      cout<<i<<" ";
    cout<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    prep();
    int t = 1;  cin >> t;
    while(t -- ) sol();
    return 0;
}