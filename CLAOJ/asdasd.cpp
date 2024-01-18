#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		bool check = true;
		for (int i = 0; i < n; i++) {
			int pos = upper_bound(a.rbegin(),a.rend(),i) - a.rbegin();
			if (n - pos != a[i]) {
				check = false;
				break;
			}
		}
		if (check) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}