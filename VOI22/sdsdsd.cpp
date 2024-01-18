/**
 *                       \`*-.
 *                        )  _`-.
 *                       .  : `. .
 *                       : _   '  \
 *                       ; *` _.   `*-._
 *                       `-.-'          `-.
 *                         ;       `       `.
 *                         :.       .        \
 *                         . \  .   :   .-'   .
 *                         '  `+.;  ;  '      :
 *                         :  '  |    ;       ;-.
 *                         ; '   : :`-:     _.`* ;
 *          [WA]        .*' /  .*' ; .*`- +'  `*'
 *                      `*-*   `*-*  `*-*'
**/
/** :)) **/

#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define X first
#define Y second
#define gcd __gcd
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define bit(i, mask) ((mask) >> (i) & 1)
#define reset(x, val) memset(x, val, sizeof(x))
#define foru(i,a,b) for(int i = (a); i <= (b); ++i)
#define ford(i,a,b) for(int i = (a); i >= (b); --i)
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

template<typename T> bool maximize(T &res, const T &val) { if (res < val) { res = val; return true; } return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val) { res = val; return true; } return false; }

const ll Linf = 0x3f3f3f3f3f3f3f3f;
const int Inf = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int Lim = 1e6 + 5;
const int inv6 = 166666668;

// #define Sieve
#ifdef Sieve
    vector<int> pr;
    vector<int> lpf;
    void Linear_sieve(int n = Lim) {
        pr.assign(1, 2);
        lpf.assign(n + 1, 2);
    
        for (int x = 3; x <= n; x += 2) {
            if (lpf[x] == 2) pr.push_back(lpf[x] = x);
            for (int i = 1; i < pr.size() && pr[i] <= lpf[x] && pr[i] * x <= n; ++i)
                lpf[pr[i] * x] = pr[i];
        }
    }
#endif

// #define Ckn_calc
#ifdef Ckn_calc
    const int LIM = 1e6 + 16;
    const int MOD = Mod;
    
    int fact[LIM + 10]; /// factorial:         fact[n] = n!
    int invs[LIM + 10]; /// inverse modular:   invs[n] = n^(-1)
    int tcaf[LIM + 10]; /// inverse factorial: tcaf[n] = (n!)^(-1)
    void precal_nck(int n = LIM)
    {
        fact[0] = fact[1] = 1;
        invs[0] = invs[1] = 1;
        tcaf[0] = tcaf[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            fact[i] = (1LL * fact[i - 1] * i) % MOD;
            invs[i] = MOD - 1LL * (MOD / i) * invs[MOD % i] % MOD;
            tcaf[i] = (1LL * tcaf[i - 1] * invs[i]) % MOD;
        }
    }
    
    ll C(int n, int k) {
        ll res = fact[n];
        res *= tcaf[k], res %= Mod;
        res *= tcaf[n - k], res %= Mod;
        return res;
    }
    
    ll P(int n, int k) {
        ll res = fact[n];
        res *= tcaf[n - k], res %= Mod;
        return res;
    }
#endif

/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

const int base = 31;
const int N = 5e2 + 5;
const int K = 10 + 2;
const int dx[] = {-1, +0, +1, +0};
const int dy[] = {+0, -1, +0, +1};
const int block_size = sqrt(2e9) + 2;

int w, h, n;
char a[N][N];
int d[K][K][N][N];

pii cell[N][N][4];
int inGrid(int u, int v) {
    return (1 <= u && u <= w) && (1 <= v && v <= h) && a[u][v] != 'x';
}

int dirc(int w, char ch) {
    if (ch == 'A') 
        return (w + 1) % 4;
    else if (ch == 'C')
        return (w + 3) % 4;
    return w;
}

pii move(int u, int v, int w) {
    auto &res = cell[u][v][w];
    if (res.first != 0) return cell[u][v][w];

    int p = dirc(w, a[u][v]);
    int f = inGrid(u + dx[p], v + dy[p]);

    w = p;
    if (f)
        res = move(u + dx[w], v + dy[w], w);
    else    
        res = make_pair(u, v);
    return res;
}

int convert(char x) {
    if (x == 'x') return -1;
    if (x == '.') return 0;
    if (x == 'A' || x == 'C') return 0;
    return x - '0';
}

int prt(int x) {
    if (x != Inf) return x; else return -1;
}

void bfs(int l, int u, int v) {
    d[l][l][u][v] = 0;

    queue<pii> q;
    q.push({u, v});

    while (!q.empty()) {
        auto [u, v] = q.front(); q.pop();

        foru(w, 0, 3) {
            auto [x, y] = move(u, v, w);
            if (minimize(d[l][l][x][y], d[l][l][u][v] + 1))
                q.push({x, y});
        }
    }
}

void dijkstra(int l, int r) {
    priority_queue<pair<int, pii>> q;
    foru(i, 1, w) foru(j, 1, h) {
        if (d[l][r][i][j] != Inf)
            q.push(make_pair(-d[l][r][i][j], make_pair(i, j)));
    }

    while (!q.empty()) {
        auto [t, x] = q.top(); q.pop();
        t = -t; auto [u, v] = x;

        foru(w, 0, 3) {
            auto [x, y] = move(u, v, w);
            if (minimize(d[l][r][x][y], d[l][r][u][v] + 1))
                q.push(make_pair(-d[l][r][x][y], make_pair(x, y)));
        }
    }
} 

void merge(int l1, int r1, int l2, int r2) {
    foru(i, 1, w) foru(j, 1, h)
        minimize(d[l1][r2][i][j], d[l1][r1][i][j] + d[l2][r2][i][j]);
}

void solve() {
    cin >> n >> h >> w;
    foru(i, 1, w) foru(j, 1, h) cin >> a[i][j];

    foru(l, 1, n) foru(r, l, n)
        foru(i, 1, w) foru(j, 1, h) {
            d[l][r][i][j] = Inf;
    }

    foru(i, 1, w) foru(j, 1, h) {
        if (convert(a[i][j]) > 0)
        {
        	cout<<i<<' '<<j<<endl;
            bfs(convert(a[i][j]), i, j);
        }
    }

    foru(i,1,w){
		foru(j,1,h)
		{
			if(d[2][2][i][j]==Inf)
				cout<<0;
			else
				cout<<d[2][2][i][j];
			cout<<' ';
		}
		cout<<endl;
	}
			
    foru(len, 2, n) {
        foru(l, 1, n - len + 1) {
            int r = l + len - 1;
            foru(k, l, r - 1)
                merge(l, k, k + 1, r);
            dijkstra(l, r);
        }
    }

    /*foru(l, 1, n) foru(r, l, n) {
        cout << l << "-" << r << ":\n";
        foru(i, 1, w) foru(j, 1, h) cout << setw(3) << setfill(' ') << prt(d[l][r][i][j]) << " \n"[j == h];
        cout << "\n";
    }*/

    int ans = Inf;
    foru(i, 1, w) foru(j, 1, h)
        minimize(ans, d[1][n][i][j]);
    cout << prt(ans);
}

signed main() {
    FastIO;

    #define task "test"
    if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
    
    #ifdef Sieve
        Linear_sieve();
    #endif
    
    #ifdef Ckn_calc
        precal_nck();
    #endif
    
    int ntest = 1;
    // cin >> ntest;
    while (ntest--) {
        solve();
        cout << "\n";
    }

    return 0;
}

/**  /\_/\
 *  (= ._.)
 *  / >TL \>AC
**/