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
#define           ed        << "\n"
#define           el        cout<<'\n'
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

const int N = 2e5 + 5;
const int inf = 4e18;
int a[N];

int cost3(int x, int y, int z) {
    return max({x, y, z}) - min({x, y, z});
}

int solve_linear(const vector<int>& v) {
    int k = SZ(v);
    if (k == 0) return 0;
    
    vector<int> dp(k + 1, inf);
    dp[0] = 0;

    FOR(i, 1, k) {
        if (i >= 2 && dp[i - 2] != inf) {
            dp[i] = min(dp[i], dp[i - 2] + A(v[i - 1] - v[i - 2]));
        }
        if (i >= 3 && dp[i - 3] != inf) {
            dp[i] = min(dp[i], dp[i - 3] + cost3(v[i - 3], v[i - 2], v[i - 1]));
        }
    }
    return dp[k];
}

void sol(){
    int n;
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    int min_cost = inf;

    //No wraparound
    vector<int> v_full;
    FOR(i, 1, n) v_full.pb(a[i]);
    int linear_cost = solve_linear(v_full);
    if (linear_cost != inf) {
        min_cost = min(min_cost, linear_cost);
    }
    if (n >= 2) {
        vector<int> sub_v;
        FOR(i, 2, n - 1) sub_v.pb(a[i]);
        int sub_cost = solve_linear(sub_v);
        if (sub_cost != inf) {
            min_cost = min(min_cost, A(a[n] - a[1]) + sub_cost);
        }
    }
    if (n >= 3) {
        vector<int> sub_v;
        FOR(i, 3, n - 1) sub_v.pb(a[i]);
        int sub_cost = solve_linear(sub_v);
        if (sub_cost != inf) {
            min_cost = min(min_cost, cost3(a[n], a[1], a[2]) + sub_cost);
        }
    }
    if (n >= 3) {
        vector<int> sub_v;
        FOR(i, 2, n - 2) sub_v.pb(a[i]);
        int sub_cost = solve_linear(sub_v);
        if (sub_cost != inf) {
            min_cost = min(min_cost, cost3(a[n - 1], a[n], a[1]) + sub_cost);
        }
    }

    cout << min_cost ed;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;   cin >> t;
    while(t -- ) sol();
    return 0;
}
