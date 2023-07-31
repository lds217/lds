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
#define int long long
long long n,m;
vector <long long> k[maxn];
long long a[maxn];
void input()
{
	cin>>n>>m;
	
	FOR(i,1,n)
	{
		if(i==1)
			cin>>a[i];
		else
		{
			int x,y;
			cin>>a[i]>>y;
			k[y].pb(i);
		}
	}
	
}
int cnt=1;
long long start[maxn];
long long ed[maxn];
void dfs(int u)
{
	start[u]=cnt++;
	for(int v:k[u])
		dfs(v);
	ed[u]=cnt;
}

long long BIT[maxn];
void add(int u,int y)
{
	while(u<maxn)
	{
		BIT[u]+=y;
		u+=u&-u;
	}
}

long long get(int u)
{
	long long sum=0;
	while(u>0)
	{
		sum+=BIT[u];
		u-=u&-u;
	}
	return sum;
}

void lds_go_goooo()
{
	
	dfs(1);
	//FOR(i,1,n)
	//	cout<<start[i]<<' ';
//	cout<<endl;
//	FOR(i,1,n)
//		cout<<ed[i]<<' ';
	while(m--)
	{
		char type;
		cin>>type;
		if(type=='p')
		{
			long long x,y;
			cin>>x>>y;
			add(start[x]+1,y);
			add(ed[x],-y);
		}
		else
		{
			int x;
			cin>>x;
			cout<<get(start[x])+a[x]<<endl;
		}
	}
}

signed main()
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
