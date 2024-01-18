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
#define           BIT(x, i)          ((x) >> (i) & 1)
#define           pii          pair<int,int>
#define           db           double
#define int ll
const int mod = 1e9 + 7;
const int MOD = 1e12 + 7;
const ll INF = 1e18;
/// 998244353;
/// 1e9 + 7;
/// 1e9 + 25;
/// 999999939;
/// 1e12 + 7;
 
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
 
int random(int l, int r) {
    return l + rd() % (r - l + 1);
}
 
int mul(ll a, ll b) {
    if(a >= mod) a %= mod;
    if(b >= mod) b %= mod;
    return 1LL * a * b % mod;
}
 
int add(int a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
 
    return a;
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
 
#define task "GH"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
 
#define task "LONG"
    if(fopen(task".in","r")) {
        freopen(task".in","r",stdin);
        freopen(task".out","w",stdout);
    }
}
 
#define int ll
 
 
const int maxn = 1e7 + 2;
bool prime[maxn];
void sieve()
{
	for(int i=2;i*i<=maxn;i++)
		if(prime[i]==0)
		for(int j=i*i;j<=maxn;j+=i)
			prime[j]=1;
}
ll a,b;
void sol() {
	cin>>a>>b;
	if(a==b)
	{
		if(a==1||prime[a]==0)
		{
			cout<<-1;
			return;
		}
	}
	if(a==1&&b==2)
	{
		cout<<-1;
		return;
	}
	if(a==2&&b==3)
	{
		cout<<-1;
		return;
	}
	if(a==1&&b==3)
	{
		cout<<-1;
		return;
	}
	if(a==b)
	{
		if(a%2==0)
		{
			cout<<a/2<<' '<<b/2;
		}
		else
		{
			for(int i=2;i*i<=a;i++)
				if(a%i==0)
				{
					cout<<i<<' '<<a-i;
					return;
				}
		}
	}
	else
	{
		if(a%2!=0&&a!=1)
			a++;
		else
			if(a==2)
				a+=2;
			else
				if(a==1)
					a+=3;
		cout<<a/2<<' '<<a/2;
	}
}
 
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //ReadInp();
 	sieve();
    int t = 1;  cin >> t;
    while(t --) sol(),cout<<endl;
    return 0;
}

