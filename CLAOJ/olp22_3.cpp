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
#define task "UAV"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=5*1e5+2;
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

//main

ll n,l,a[maxn];

void input()
{
	cin>>l>>n;
	FOR(i,2,n-1)
		cin>>a[i];
	a[1]=1000,a[n]=1001;
}

ll dp[maxn];
void lds_go_goooo()
{
	int u,v;
	int j=2,i=1;
    while(j<=n)
	{	
		int next=j;
		while(j-i<=l&&j<=n)
		{
		    if(a[j]%2)  next=j;
			j++;
		}
		u++;
		i=next;
	}
	//cout<<u+1;
	mset(dp,-0x3f);
	dp[n]=a[n];
	ll maxx=a[n];
	FORD(i,n-1,1)
	{
		if(a[i]%2==0)
		{
			if(i+l<=n)
				maximize(dp[i],dp[i+l]+a[i]);
			maximize(dp[i],maxx-a[i]);
		}
		maximize(maxx,dp[i]);

	}
	cout<<u+1<<' '<<dp[1];
}

int main()
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
