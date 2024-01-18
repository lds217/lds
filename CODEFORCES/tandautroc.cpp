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

int n, m;
char a[1001][1001];


void input()
{
	cin>>n>>m;
	FOR(i,1,n)
		FOR(j,1,m)
			cin>>a[i][j];
}

ll pre[1005];
ll dp[1001][1001];

void lds_go_goooo()
{
	FOR(i,1,n){
		FOR(j,1,m)
			if(a[i][j]=='#')
				pre[j]=0;
			else
			{
				pre[j]=pre[j-1]+1;
				dp[i][j]+=pre[j-1];
			}
				
		mset(pre,0);
		FORD(j,m,1)
			if(a[i][j]=='#')
				pre[j]=0;
			else
			{
				pre[j]=pre[j+1]+1;
				dp[i][j]+=pre[j+1];
			}
		mset(pre,0);
	}
	
	FOR(j,1,m){
		FOR(i,1,n)
			if(a[i][j]=='#')
				pre[i]=0;
			else
			{
				pre[i]=pre[i-1]+1;
				dp[i][j]+=pre[i-1];
			}
				
		mset(pre,0);
		FORD(i,n,1)
			if(a[i][j]=='#')
				pre[i]=0;
			else
			{
				pre[i]=pre[i+1]+1;
				dp[i][j]+=pre[i+1];
			}
		mset(pre,0);
	}
	
	int n1=n,m1=m;
	int n=max(n,m)*2;
	FOR(i,1,n){
		FOR(j,1,i)
			if(a[i-j+1][j]=='#')
				pre[j]=0;
			else
			{
				pre[j]=pre[j-1]+1;
				dp[i-j+1][j]+=pre[j-1];
			}
				
		mset(pre,0);
		FORD(j,i,1)
			if(a[i-j+1][j]=='#')
				pre[j]=0;
			else
			{
				pre[j]=pre[j+1]+1;
				dp[i-j+1][j]+=pre[j+1];
			}
		mset(pre,0);
	}
	
	FOR(i,1,n1)
		FOR(j,1,m1)
			cout<<dp[i][j]<<" \n"[j==m1];
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
