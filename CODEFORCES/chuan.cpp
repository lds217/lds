#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define          FOR(i,a,b)    for (int i = (a), _b = (b); i <= _b; i++)

int mp[300000];

void sol(){
    vector <vector <int>> f;
    vector <int> a, lst;

    int n, k; cin >> n >> k;

    a = vector <int> (n + 1, 0);
    lst = vector <int> (n + 1, 0);

    f = vector <vector<int>> (n + 1, vector <int> (k + 1, 1e9));

    FOR(i, 1, n) cin >> a[i];

    f[1][0] = 0;

    FOR(i, 1, n - 1){
        mp[a[i] + 100000] = i;

        FOR(j, 0, k) if(f[i][j] < 1e9){

            if(a[i] != a[i + 1]) f[i + 1][j] = min(f[i + 1][j], f[i - 1][j] + 1);
            if(a[i] != a[i + 1] && j + 1 <= k)
                f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j]);

            f[i + 1][j] = min(f[i + 1][j], f[mp[a[i + 1] + 100000]][j] + i - mp[a[i + 1] + 100000]);
        }
    }

    int ans = 1e9;

    FOR(i, 0, k) ans = min(ans, f[n][i]);

    cout << ans << '\n';

    FOR(i, 1, n)
        mp[a[i] + 100000] = 0;
}

int main(){
    ios_base :: sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t --){
        sol();
    }
}
