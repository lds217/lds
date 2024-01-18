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
    return b%2==0 ? (tmp*tmp)%mod : ((tmp*tmp%mod)*a) % mod;
}

//main
#define int ll
int n,k;
int a[maxn];
int cnt[maxn];

bool era[maxn];
vector <int> primes;
int p=0;
long long gt[2000005],igt[2000005];
void input()
{
	cin>>n>>k;
	FOR(i,1,n){
	cin>>a[i],cnt[a[i]]++;
	if(era[a[i]])
		p++;
	}
}

void prepare(int lim=1000000)
{
	era[1]=era[0]=1;
	gt[0]=igt[0]=1;
	FOR(i,1,lim)
		gt[i]=(gt[i-1]*i)%mod;
	igt[lim]=POW(gt[lim],mod-2);
	FORD(i,lim,1)
		igt[i-1]=(igt[i]*i)%mod;
	
	for(int i=2;i*i<=100005;i++)
		if(era[i]==0)
			for(int j=i*i;j<=100005;j+=i)
				era[j]=1;
			FOR(i,2,5)
		if(era[i]==0)
			primes.pb(i);	
}

ll C(int n,int k)
{
	if(k>n)	return 0;
    return gt[n]*igt[k]%mod*igt[n-k]%mod;
}


ll dp[maxn];
void lds_go_goooo()
{
//	dp[1]=cnt[primes[0]];
//cout<<p<<endl;

//for(int i:primes)	cout<<i<<' ';
//cout<<endl;
dp[0]=1;
	for(int i:primes)
	{
	
		FORD(j,primes.size(),1)
			dp[j]=(dp[j]+dp[j-1]*cnt[i])%mod;
		FOR(i,1,n)
			cout<<dp[i]<<' ';
	}

	
	ll ans=0;
	FOR(i,0,k)	
		(ans+=dp[i]*C(p,k-i))%=mod;
	cout<<ans;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    prepare();
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
