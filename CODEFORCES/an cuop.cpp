#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int N = 100;
int a[N + 10];
 
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x,y,n;
		cin >> x >> y >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<bool>f(1e6 + 10,false);
		int sum = 0;
		f[0] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = sum; j >= 0; j--) 
				if (f[j]) f[j + a[i]] = true;
			sum += a[i];
			for (int i = 0; i <= sum; i++) 
				cout<<f[i]<<' ';
			cout<<endl;
		}
		
		int ans = 1e9 + 7;
		for (int i = 0; i <= sum; i++) 
			if (f[i])
				ans = min(ans,max((i + x - 1) / x,(sum - i + y - 1) / y));
		cout << ans << "\n";
	}
}