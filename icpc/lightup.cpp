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
  char a[35][35];
  bool vs[35][35];
  memset(a, 0, sizeof(a));
  memset(vs, 0, sizeof(vs));
  FOR (i, 1, n)
    FOR(j, 1, n)
      cin>>a[i][j];
  

  FOR (i, 1, n)
    FOR(j, 1, n) {
      if (a[i][j] >='0' && a[i][j] <= '4') {
        int cnt = 0;
        FOR(z, 0, 3)
          cnt+= (a[i+moveX[z]][j+moveY[z]] =='?');
        if (cnt != a[i][j]-'0') {
          cout<< 0;
          return;
        }
      }
      if (a[i][j] == '?') {
        FOR(z, 0, 3) {
          if (a[i+moveX[z]][j+moveY[z]] =='?') {
            cout<<0;
            return;
          }
        }
        vs[i][j] = 1;
        int x = i + 1;
        int y = j;
        while (a[x][y] == '.') {
          vs[x][y] = 1;
          x++;
        }
        if (a[x][y]=='?')
        {
            cout<<0;
            return;
          }
        x = i - 1; y = j;
        while (a[x][y] == '.') {
          vs[x][y] = 1;
          x--;
        }
         if (a[x][y]=='?')
        {
            cout<<0;
            return;
          }
        x = i; y = j - 1;
        while (a[x][y] == '.' ) {
          vs[x][y] = 1;
          y--;
        }
         if (a[x][y]=='?')
        {
            cout<<0;
            return;
          }
        x = i; y = j + 1;
        while (a[x][y] == '.' ) {
          vs[x][y] = 1;
          y++;
        }
         if (a[x][y]=='?')
        {
            cout<<0;
            return;
          }
        
      }
    }

  FOR(i, 1, n)
    FOR(j, 1, n) {
      if ((a[i][j] == '.' || a[i][j] == '?') && !vs[i][j]) {
       // cout<<"ko";
        cout<< 0;
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