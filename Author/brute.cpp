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
const ll mod=27022007;
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

int n,k;

void input()
{
	cin>>k>>n;

}

int dp[100000000];
void lds_go_goooo()
{
	dp[0]=0;
	dp[1]=1;
	if(k==0)
    	n--;
	int i=2;
	while(n)
	{
	    
		dp[i]=(dp[i-1]+dp[i-2])%mod;
		cout<<dp[i]<<' ';
		if(k==0&&dp[i]%2)
		        n--;
		if(k==1&&dp[i]%2==0)
		        n--;
	  	i++;
	}
	cout<<endl;
	cout<<dp[i-1];
}

int main()
{
 //	ios_base::sync_with_stdio(false);
   // cin.tie(0);
    //freopen("3.inp", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}