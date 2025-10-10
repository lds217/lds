#include<bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(), (a).end()
#define task "kbsiudthw"

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 2277;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vi a(n);
        map<int, int> cnt;
        for(int &x : a) cin >> x, cnt[x]++;
        int ans = 0, s= 0;
        vi vec;
        for (auto x : cnt){
            s += (x.se / 2) * 2 * x.fi;
            if (x.se & 1){
                if (vec.size() == 2) {
                    s -= vec[0];
                    vec.erase(vec.begin());
                }
                vec.pb(x.fi);
                s += x.fi;
            }
            if (s - x.fi > x.fi) ans = max(ans, s);
        }
        cout << ans << '\n';
    }


    return 0;
}