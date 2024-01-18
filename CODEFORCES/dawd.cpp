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

int n,m,k;
ll dp[126][126][126];
int a[155][155];
int pre[126][126];
bool check(int x,int y,int w,int z)
{
	return (pre[w][z]-pre[w][y-1]-pre[x-1][z]+pre[x-1][y-1]!=0);
	FOR(i,x,w)
		FOR(j,y,z)
			if(a[i][j]==2)	return 1;		
	return 0;
}

int DP(int i,int j,int k)
{
	if(k==1&&check(i,j,n,m))	return 1;
	ll &res=dp[i][j][k];
	if(res!=-1)	return res;
	res=0;
	FOR(x,i+1,n)
		if(check(i,j,x-1,m))
		(res+=DP(x,j,k-1))%=1000000000+7;
	
	FOR(x,j+1,m)
	if(check(i,j,n,x-1))
		(res+=DP(i,x,k-1))%=1000000000+7;
		
	return res;
}

void input()
{
	mset(dp,-1);
	cin>>n>>m>>k;
	FOR(i,1,n)
		FOR(j,1,m)
		{
			cin>>a[i][j];
			pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]	;
			if(a[i][j]==2)	pre[i][j]++;
			
		}
}
void lds_go_goooo()
{
	cout<<DP(1,1,k);
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
