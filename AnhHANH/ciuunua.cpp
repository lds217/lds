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
#define task "haitumtp"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2207+5;
const ll mod=26051968;
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
#define int long long
//main

ll a[maxn][maxn];
ll dp[maxn][maxn];
int n,m;
void input()
{
	cin>>n>>m;
	FOR(i,0,n-1)
		FOR(j,0,m-1)
		{
			cin>>a[i][j];
			dp[i][j]=1e18;
			if(j==0)
				dp[i][j]=a[i][j];
		}
}
void lds_go_goooo()
{
	
	FOR(j,0,m-2)
		FOR(i,0,n-1)
			{
				dp[(i*i) % n][j+1]=min(dp[(i*i) % n][j+1],dp[i][j]+a[(i*i) % n][j+1]);
				dp[(i*i*i) % n][j+1]=min(dp[(i*i*i) % n][j+1],dp[i][j]+a[(i*i*i) % n][j+1]);
				dp[(i*i*i*i) % n][j+1]=min(dp[(i*i*i*i)% n][j+1],dp[i][j]+a[(i*i*i*i) % n][j+1]);
			}
					

		ll ans=1e18;
	FOR(i,0,n-1)
		ans=min(ans,dp[i][m-1]);
	cout<<ans;		
}

signed main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
