// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "SUADUONG"
#define base 31
using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e6+2;
const ll mod=1e9+7;
const ll inf=1e18;


const int moveX[]={0,0,1,-1};
const int moveY[]={-1,1,0,0};

bool maximize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A>B ? A=B, true : false;
}

ll POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}

//main

string s,t;
long long dp[maxn];
long long p[maxn];
int n,m;

void input( )
{
	
}

long long gethash(int l, int r)
{
	long long ans= ((dp[r]-dp[l-1]*p[r-l+1])%mod+mod)%mod;
	return ans;
}

void lds_go_goooo()
{
	cin>>s>>t;
	n=s.size(),m=t.size();
	s=' '+s;
	t=' '+t;
	long long hasht=0;
	p[0]=1;
	dp[0]=0;
	FOR(i,1,m)	p[i]=p[i-1]*base %mod;
	FOR(i,1,m)	hasht=(hasht* base + t[i]-'a'+1)%mod;
//	cout<<hasht;
	FOR(i,1,n)dp[i]=(dp[i-1]* base  + s[i]-'a'+1)%mod;
	for(int i=1;i+m-1<=n;i++)
		if(hasht==gethash(i,i+m-1))
			cout<<i<<' ';

}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
