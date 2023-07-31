#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ed << "\n";
#define el cout<<'\n';
#define rep(i,a,n,b) for(int i=a;i<=n;i+=b)
#define foru(i,a,n,b) for(int i=a;i<=n;i+=b)
#define ALL(s) s.begin(),s.end()
#define fi first
#define se second
#define task "a"
#define mem(dp,a) memset(dp,a,sizeof dp)
#define ford(i,a,n,b) for(int i=a; i>=n; i-=b)
#define pb(x) push_back(x);
#define db(x) cerr<<x<<'\n';
#define A(a) abs(a)
#define SZ(x) ((int) (x.size()))
#define FOR(i,l,r) for(int i=l; i<=r; i++)
#define REP(i,l,r) for(int i=l; i<r; i++)
#define FOD(i,r,l) for(int i=r; i>=l; i--)
#define LT(x) (1LL << (x))
#define BT(x,i) ((x) >> (i) & 1)

const ll mod[] = {998244353,(int)1e9+7,987654323};
const int base[] = {31,311,331};
const int INF = 1e9 ;
const int N = 5e5 + 10;
const int MAX = 2e5 + 12;
const int NMAX =  5e4 + 23;

// const ll MOD = 1e9 + 7;
template <class T> inline bool minimize(T &a, const T &b) {
    return (a > b ? (a = b),1 : 0);
}
template <class T> inline bool maximize(T &a, const T &b) {
    return (a <= b ? (a = b),1 : 0);
}

template <typename T> istream& operator >> (istream& in, vector<T>& v) {
    for (auto &it : v) in >> it;
    return in;
}
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) {
    for (auto it : v) os << it << " ";
    return os;
}
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1,T2>& p) {
    in >> p.first >> p.second;
    return in;
}
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p) {
    os << p.first << " " << p.second;
    return os;
}
ll MOD = 1e9 + 7;
#define int ll
void ADD(int &a,const int &b) {
    a += b;
    if(a >= MOD) a -= MOD;
}

int t;
int n,k;

struct matrix {
    int a[2][2] = {{0,0},{0,0}};

    matrix operator * (const matrix& other) {
        matrix product;
        for(int i : {0,1})
            for(int j : {0,1})
                for(int k : {0,1})
                    ADD(product.a[i][j], (a[i][k] * other.a[k][j]) % MOD);
        return product;
    }
};

matrix b;

matrix lt(ll n) {
    if(n == 1)
        return b;
    matrix p = lt(n / 2);
    p = p * p;

    if(n & 1)
        p = p * b;
    return p;
}

int f[1000006];
ll pos[1000006];

int getFibo(ll i) {
    if(i == 1 || i == 2) return 1;
    if(i == 3) return 2;
    matrix tmp;

    tmp.a[0][0] = 2;
    tmp.a[0][1] = tmp.a[1][0] = 1;
    tmp.a[1][1] = 1;

    tmp = tmp * lt(i - 3);
    return tmp.a[0][0];
}



void gogo() {
    ll i;
    cin >> n >> i >> MOD;

    f[1] = getFibo(i);
    f[2] = getFibo(i+1);
	cout<<f[1]<<' '<<f[2];
	cout<<endl;
    memset(pos, -1, sizeof pos);

    FOR(id,i+2,i+n-1){
        int j = id - i + 1;
        f[j] = f[j-1];
        ADD(f[j], f[j-2]);
    }
	FOR(i,1,n)	cout<<f[i]<<' ';
	cout<<endl;
    pos[0] = i-1;
    int s = 0;

    FOR(id,i,i+n-1){
        int j = id - i + 1;
        ADD(s, f[j]);
        if(pos[s] != -1){
            cout << id - pos[s] << ' ';
            FOR(j,pos[s]+1,id) cout << j << ' ';
            cout ed
           // return ;
        }
        pos[s] = id;
    }

    cout << 0 ed
    return;
}



inline void fre(bool t,int test = 1) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#define task "SCORING"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
#define task "a"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    if(t) cin >> test;
    while(test --) gogo();
}

signed main() {
    b.a[0][0] = b.a[1][0] = b.a[0][1] = 1;
    b.a[1][1] = 0;

    fre(1);
    return 0;
}
