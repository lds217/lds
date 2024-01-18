// Created by BJMinhNhut
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(__typeof(b) i = a, _b = b; i <= _b; ++i) 
#define FORD(i, a, b) for(__typeof(a) i = a, _b = b; i >= _b; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MASK(i) (1ll<<(i))
#define BIT(t, i) (((t)>>(i))&1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

/***Common Functions***/
template <class T>
bool minimize(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool maximize(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

/***End of Template***/
int n;
const int N = 105, MAX = 2005;
int d[N];
int dp[N][MAX];
bool opt[N][MAX];
const int INF = 1e9;

void Input() {
    cin >> n;
    FOR(i, 1, n) cin >> d[i];
}

void Solve() {
    memset(dp, 0x3f, sizeof dp);
    memset(opt, 0, sizeof opt);
    dp[1][0] = 0;
    FOR(i, 1, n) FOR(s, 0, MAX-1) if (dp[i][s] < INF) {
        if (s+d[i] < MAX && minimize(dp[i+1][s+d[i]], max(dp[i][s], s+d[i]))) opt[i+1][s+d[i]] = 1;
        if (s-d[i] >= 0 && minimize(dp[i+1][s-d[i]], dp[i][s])) opt[i+1][s-d[i]] = 0;
    }
    FOR(i,1,n)
    {
    	FOR(j,0,6)
    		cout<<opt[i][j]<<' ';
    	cout<<endl;
	}
    if (dp[n+1][0] < INF) {
        string ans = "";
        int s = 0;
        FORD(i, n+1, 2) {
            if (opt[i][s]) ans.pb('U'), s -= d[i-1];
            else ans.pb('D'), s += d[i-1];
        }
        reverse(ALL(ans));
        cout << ans;
    } else cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Input(), Solve();
    return 0;
}
