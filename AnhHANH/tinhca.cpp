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
#define task "cc"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

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
const ll maxn=3e5+1;
const ll LOG= log2(maxn)+1;
long long LCA[maxn][LOG];

long long cs[maxn];
long long h[maxn];
long long m,n;

vector <pair<int,int>> a[maxn];


void input()
{
	cin>>n;
	FOR(i,1,n-1)
	{
		int u,v,c;
		cin>>u>>v>>c;
		a[u].pb({v,c});
		a[v].pb({u,c});
	}

}

void dfs(int u,int lvl,int par)
{
	LCA[0][u]=par;
	h[u]=lvl;
	for(ii i:a[u])
	{
		int v=i.fi;
		int dv=i.se;
		if(v==par)	continue;
		cs[v]+=cs[u]+dv;
		dfs(v,lvl+1,u);
	}
}

void init()
{
	mset(LCA,-1);
	mset(h,0);
	mset(cs,0);
	dfs(1,0,-1);
	FOR(i,1,LOG-1)
		FOR(j,1,n)
			LCA[i][j]=LCA[i-1][LCA[i-1][j]];
}

int get(int a,int b)
{
	if(h[a]>h[b])
		swap(a,b);
	int d=h[b]-h[a];
	while(d>0)
	{
		
		int i=log2(d);
		b=LCA[i][b];
		d-=(1<<i);
	}
	while(a!=b)
	{
		int i=log2(h[a]);
		while(i>0&&LCA[i][a]==LCA[i][b])	i--;
		a=LCA[i][a];
		b=LCA[i][b];
	}
	return a;
}

void lds_go_goooo()
{
	init();
	int q;
	cin>>q;
	vector<ii> ans;
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		cout<<cs[u]+cs[v]-2*cs[get(u,v)]<<"\n";
	}

}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;

        input(), lds_go_goooo();
        cout<<'\n';

    return 0;
}
