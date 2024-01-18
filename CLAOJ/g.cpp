#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second
#define ll long long
#define ld long double
#define sz(x) ((int)(x).size())
#define all(x) 	(x).begin(), (x).end()
#define pb push_back
#define mpp make_pair
#define ve vector
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll inf = 1e18; const int iinf = 1e9;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T> inline bool chmin(T& a, T b) { return (a > b ? a = b, 1 : 0); }
template <typename T> inline bool chmax(T& a, T b) { return (a < b ? a = b, 1 : 0); }
 
inline void solve() {
	int n, m, k, t;
	cin >> n >> m >> k >> t;
 
	ve<ve<array<int,3>>> ax(n), ay(m);
	ve<array<int,3>> a(k); int ptr = 0;
 
	for (auto &[x, y, d] : a) {
		cin >> x >> y >> d;
 
		if (d == 1 || d == 3) {
			ay[y].pb({x, d == 1 ? 1 : -1, ptr++});
		}
		else {
			ax[x].pb({y, d == 2 ? 1 : -1, ptr++});
		}
	}
 
	ve<array<int,3>> ans(k);
 
	for (int x = 0; x < n; ++x) {
		auto &vec = ax[x];
		sort(all(vec));
 
		ve<array<int,3>> nw;
 
		int s = sz(vec);
		for (auto [y, d, id] : vec) {
			y = ((y + t * 1ll * d) % (2 * m) + (2 * m)) % (2 * m);
			if (y > m) y = 2 * m - y, d *= -1;
 
			if (!y || y == m) d = (!y ? 1 : -1);
			nw.pb({y, d, id});
		}
		sort(all(nw));
 
		int ptr = 0;
		for (auto &[y, d, id] : nw) {
			ans[vec[ptr++][2]] = {x, y, d == 1 ? 2 : 4};
		}
	}
 
	for (int y = 0; y < m; ++y) {
		auto &vec = ay[y];
		sort(all(vec));
 
		ve<array<int,3>> nw;
 
		int s = sz(vec);
		for (auto [x, d, id] : vec) {
			x = ((x + t * 1ll * d) % (2 * n) + (2 * n)) % (2 * n);
			if (x > n) x = 2 * n - x, d *= -1;
 
			if (!x || x == n) d = (!x ? 1 : -1);
			nw.pb({x, d, id});
		}
		sort(all(nw));
 
		int ptr = 0;
		for (auto &[x, d, id] : nw) {
			ans[vec[ptr++][2]] = {x, y, d == 1 ? 1 : 3};
		}
	}
 
	for (auto &[x, y, d] : ans) cout << x << " " << y << " " << d << '\n';
}
 
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q = 1; // cin >> q;
	while (q--) solve();
	cerr << fixed << setprecision(3) << "Time execution: " << (double)clock() / CLOCKS_PER_SEC << endl;
}