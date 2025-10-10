#include<bits/stdc++.h>
using namespace std;

#define          task      "a"
#define          ll        long long
#define          FORE(i, v)  for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define          ed        << "\n";
#define          el        cout<<'\n';
#define          ALL(s)      s.begin(),s.end()
#define          fi        first
#define          se        second
#define          SQ(a)       (a)*(a)
#define          A(a)        abs(a)
#define          SZ(a)       ((int)(a.size()))
#define          REP(i,a,b)    for (int i = (a), _b = (b); i < _b; i++)
#define          FOR(i,a,b)    for (int i = (a), _b = (b); i <= _b; i++)
#define          FOD(i,r,l)    for(int i=r; i>=l; i--)
#define          MASK(x)     (1LL << (x))
#define          BIT(x, i)   ((x) & (1ULL << (i)))
#define          pii         pair<int,int>
#define          pll         pair<ll,ll>
#define          db          double
#define          II(a, b)    make_pair((a),(b))
#define          pb(x)       push_back(x)
#define          ull unsigned long long

void sol() {
    int n;
    ll k;
    cin >> n >> k;
    if (k == (ll)n * n - 1) {
      cout << "NO" ed;
      return;
    }
    cout << "YES" ed;
    char grid[1005][1005];

    ll num_full_U_rows = k / n;
    ll rem_U_cells = k % n;
    REP(r, 0, num_full_U_rows) {
      REP(c, 0, n) {
        grid[r][c] = 'U';
      }
    }
    if (num_full_U_rows < n) {
      REP(c, 0, rem_U_cells) {
        grid[num_full_U_rows][c] = 'U';
      }
    }
    if (num_full_U_rows < n) {
      int r_partial = num_full_U_rows;
      if (r_partial == n - 1) {
          REP(c, rem_U_cells, n - 1) {
            grid[r_partial][c] = 'R';
        }
        if (rem_U_cells < n) {
          grid[r_partial][n - 1] = 'L';
        }
      } else {
        REP(c, rem_U_cells, n) {
          grid[r_partial][c] = 'D';
        }
      }
    }
    REP(r, num_full_U_rows + 1, n) {
      REP(c, 0, n - 1) {
        grid[r][c] = 'R';
      }
      grid[r][n - 1] = 'L';
    }
    REP(i, 0, n) {
      REP(j, 0, n) {
        cout << grid[i][j];
      }
      el;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;  cin >> t;
    while(t -- ) sol();
    return 0;
}