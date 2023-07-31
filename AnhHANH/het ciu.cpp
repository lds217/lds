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
#define task "distance"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=3*1e5+2;
const ll mod=26051968;
const ll inf=1e18;
const ll LOG = log2(3e5+1)+2;
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
struct lp{
	ll height,cost;
};
int n,LCA[maxn][LOG];
lp h[maxn];

vector <ii> a[maxn];

void input()
{
	cin>>n;
	FOR(i,1,n-1)
	{
		int u,v,c;
		cin>>u>>v>>c;
		if(u==v)
			continue;
		a[u].pb({v,c});
		a[v].pb({u,c});
	}
}

void dfs(int cur,int lvl, int sum,int par)
{
	h[cur]={lvl,sum};
	LCA[0][cur]=par;
	for(ii i: a[cur])
	{
		int v=i.fi;
		int dv=i.se;
		if(v==par)
			continue;
		dfs(v,lvl+1,sum+dv,cur);
	}

}

void init()
{
	mset(LCA,-1);
	mset(h,0);
	dfs(1,0,0,-1);
	FOR(i,1,LOG-1)
		FOR(j,1,n)
			LCA[i][j]=LCA[i-1][LCA[i-1][j]];
}

int getlca(int a,int b)
{
	if(h[a].height>h[b].height)
		swap(a,b);
	int d=h[b].height-h[a].height;

	while(d>0)
	{
		
		int i=log2(d);
		b=LCA[i][b];
		d-=(1<<i);
	}
	while(a!=b)
	{
		int i=log2(h[a].height);
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
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		if(u==v)
			cout<<0;
		else
		cout<<h[u].cost+h[v].cost-2*h[getlca(u,v)].cost<<"\n";
	}
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;

        input(), lds_go_goooo();
        cout<<'\n';

    return 0;
}
