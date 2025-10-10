#include<bits/stdc++.h>
using namespace std;

#define            task       "a"
#define             ll        long long
#define          FORE(i, v)   for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define             ed        << "\n";
#define             el        cout<<'\n';
#define            ALL(s)     s.begin(),s.end()
#define             fi        first
#define             se        second
#define            SQ(a)      (a)*(a)
#define            A(a)        abs(a)
#define            SZ(a)      ((int)(a.size()))
#define          REP(i,a,b)    for (int i = (a), _b = (b); i < _b; i++)
#define          FOR(i,a,b)    for (int i = (a), _b = (b); i <= _b; i++)
#define          FOD(i,r,l)    for(int i=r; i>=l; i--)
#define           MASK(x)      (1LL << (x))
#define           BIT(x, i)    ((x) & (1ULL << (i)))
#define           pii          pair<int,int>
#define           pll          pair<ll,ll>
#define           db           double
#define           II(a, b)     make_pair((a),(b))
#define           pb(x)        push_back(x)
#define          ull unsigned long long

const int mod = 1e9 + 7;
const ll MOD = 998244353;
const ll INF = 1e18 + 2;
/// 998244353;
/// 1e9 + 7;
/// 1e9 + 25;
/// 999999939;
/// 1e12 + 7;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll random(ll l, ll r) {
    return l + rd() % (r - l + 1);
}


int mul(int a, int b) {
    if(a >= mod) a %= mod;
    if(b >= mod) b %= mod;
    return 1ULL * a * b % mod;
}



int add(int a, int b) {
    if(a >= mod) a %= mod;
    if(b >= mod) b %= mod;
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;

    return a;
}

ll opt_mul(ll a, ll b, const ll &p) {
    ll res = 0;

    a %= p;
    b %= p;

    while(b) {
        if(b & 1) {
            res = res + a;
            if(res >= p)
                res -= p;
        }

        a = a + a;

        if(a >= p) a -= p;
        b >>= 1;
    }
    return res;
}

long long opt_pw(ll a, ll b,const ll &p) {
    ll res = 1;
    while(b) {
        if(b & 1) res = opt_mul(res, a, p);
        a = opt_mul(a, a, p);
        b = b >> 1;
    }
    return res;
}

int pw(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1)
            res = mul(res, a);
        b = b >> 1;
        a = mul(a, a);
    }
    return res;
}

ll lt(int a, int b) {
    ll res = 1;
    while(b) {
        if(b & 1)
            res = 1LL * res * a;
        b = b >> 1;
        a = 1LL * a * a;
    }
    return res;
}


template <class T> inline bool minimize(T &a, const T &b) {
    return (a > b ? (a = b),1 : 0);
}

template <class T> inline bool maximize(T &a, const T &b) {
    return (a < b ? (a = b),1 : 0);
}



void ReadInp() {
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

#define task "a"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

#define task "CAKE"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

#define task "disrupt"
    if(fopen(task".in","r")) {
        freopen(task".in","r",stdin);
        freopen(task".out","w",stdout);
    }
}

int arr[100005];

void sol(){
    int n;
    cin>>n;
  
    FOR(i, 1, n) {
      cin >> arr[i];
    }
    vector<int> pre(n + 2, 0), suff(n + 2, n + 1);

    stack<int> minn;
    FOR(i, 1, n) {
      while(!minn.empty() && arr[minn.top()] >= arr[i] ) minn.pop();
      if (!minn.empty())
        pre[i] = minn.top();
      minn.push(i);
      
    }
    while(!minn.empty()) minn.pop();

    FOD(i, n, 1) {
      while(!minn.empty() && arr[minn.top()] >= arr[i] ) minn.pop();
      if (!minn.empty())
        suff[i] = minn.top();
      minn.push(i);
    }
    int l, r;
    long long ans = 0;
    FOR(i, 1, n) {
      if (maximize(ans, 1LL * arr[i] * (suff[i] - pre[i] - 1))) {
        l = pre[i] + 1;
        r = suff[i] -1 ;
      }
      
    }
    cout<<l<<" " << r<< " "<<ans;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
   // ReadInp();

    int t = 1;   // cin >> t;
    while(t -- ) sol();

    return 0;
}