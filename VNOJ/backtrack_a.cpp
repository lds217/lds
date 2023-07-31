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
int n,k;
long long c[55][55];
bool vs[55*55];
long long ans=1e9;
vector <long long> vis,res;
void input()
{
	cin>>n>>k;
	FOR(i,1,n)
		FOR(j,1,n)
			cin>>c[i][j];
}

void Try(int u,long long w,int d)
{
	if(ans==k+1)	return;
	if(k==d)
	{
		if(ans>w+c[u][1])
		{
			ans=w+c[u][1];
			res.clear();
			res.pb(1);
			for(int x:vis)
				res.pb(x);
		}
		return;
	}
	
	FOR(v,1,n)
	{
		if(u!=v)
		if(vs[v]==0)
		{
			if(ans==k+1)	return;
			if(ans<=w+c[u][v]) continue;
			vs[v]=1;
			vis.pb(v);
			Try(v,w+c[u][v],d+1);
			vis.pop_back();
			vs[v]=0;
		}
	}
}

void lds_go_goooo()
{
	vs[1]=1;
	k--;
	Try(1,0,0);
	cout<<ans<<'\n';
	for(int x:res)
		cout<<x<<' ';
	
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
