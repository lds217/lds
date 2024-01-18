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
const ll maxn=2*1e4+2;
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

int n;
int a[maxn],b[maxn],dp[maxn][2];
void input()
{
	cin>>n;
	FOR(i,1,n)	cin>>a[i];
	FOR(i,1,n-1)	cin>>b[i];
}
void lds_go_goooo()
{
	//0 là tự mua, 1 là dc bao
	mset(dp,0x3f);
	dp[1][0]=a[0];
	dp[1][1]=b[n]=1e9;
	dp[2][0]=a[1]+a[2];
	dp[2][1]=b[1];
	FOR(i,3,n)
	{
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+a[i];
		dp[i][1]=dp[i-1][0]-a[i-1]+b[i-1];
	}
	cout<<min(dp[n][0],dp[n][1]);
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
