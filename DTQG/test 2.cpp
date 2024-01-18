#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define FOR(i, a, b) for(__typeof(b) i = a, _b = b; i <= _b; ++i)
#define FORD(i, a, b) for(__typeof(a) i = a, _b = b; i >= _b; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MASK(i) (1ll<<(i))
#define BIT(t, i) (((t)>>(i))&1)
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
const int MOD = 1e9+7;
const int N = 2e5+5;
const int INF = 0x3f3f3f3f;

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}

template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}
     * *  

int n, s, a[N], cnt[5005], ans;
int dp[5005];

int frac[N], ifrac[N];

int Pow(int a, int b, int m){
    if (b == 0) return 1;
    int t = Pow(a, b/2, m);
    t = (t%m)*(t%m);
    if (b%2 == 0) return t%m;
    return ((t%m)*(a%m))%m;
}

void pre(){
    frac[0] = 1;
    FOR (i, 1, N-1){
        frac[i] = (frac[i-1]*i)%MOD;
    }
    ifrac[N-1] = Pow(frac[N-1], MOD-2, MOD);
    FORD(i, N-2, 0){
        ifrac[i] = ((i+1)*ifrac[i+1])%MOD;
    }
}

int C(int n, int k){
    int res = frac[n];
    res *= ifrac[k]; res %= MOD;
    res *= ifrac[n-k]; res %= MOD;
    return res;
}

vector<pii> cal(int a){
    vector<pii> Elaina;
    if (cnt[a] == 0) return Elaina;
    if (a&1){
        Elaina.pb({1, {cnt[a], cnt[a]}});
        return Elaina;
    }
    vector<pii> Arya = cal(a/2);
    for (int i = 0; i < Arya.size(); i++){
        // cout << Arya[i].fi << ' ' << Arya[i].se.fi << ' ' << Arya[i].se.se << endl;
        if (Arya[i].se.se >= 2){
            Elaina.pb({Arya[i].fi*2, {C(2, Arya[i].se.fi), Arya[i].se.se/2}});
        }
        for (int j = i+1; j < Arya.size(); j++){
            Elaina.pb({Arya[i].fi+Arya[j].fi, {(Arya[i].se.fi*Arya[j].se.fi)%MOD, min(Arya[i].se.se, Arya[j].se.se)}});
        }
    }

    if (a != s) Elaina.pb({1, {cnt[a], cnt[a]}});
    return Elaina;
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
        freopen("slime.inp", "r", stdin);
        freopen("slime.out", "w", stdout);
    pre();
    cin >> n >> s;
    FOR (i, 1, n) cin >> a[i], cnt[a[i]]++;
    int c = 0;

    ans = cnt[s]*(Pow(2, n-1, MOD));
    ans %= MOD;
    vector<pii> Elaina = cal(s);
    for (auto x : Elaina){
        // cout << x.fi << ' ' << x.se.fi << endl;
        ans += (x.se.fi*(Pow(2, n-x.fi, MOD)))%MOD;
        ans %= MOD;
    }
    if (cnt[s]) Elaina.pb({1, {cnt[s], cnt[s]}});
    int m = Elaina.size();
    // cout << m << endl;
    for (int mask = 1; mask < (1<<m); mask++){
        int cnt = 0, count = 1;
        int k = 0;
        FOR (i, 0, m-1){
            if (BIT(mask, i)){
                k++;
                cnt += Elaina[i].fi;
                count *= Elaina[i].se.fi;
                count %= MOD;
            }
        }
        if (k == 1) continue;
        // cout << count << ' '<< n-cnt << endl;
        if (k%2 == 0)
            ans -= (count*(Pow(2, n-cnt, MOD)))%MOD;
        else 
            ans += (count*(Pow(2, n-cnt, MOD)))%MOD;
    }
    cout << ans;
    return 0;
}