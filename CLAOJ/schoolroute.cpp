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

int n,m;

vector <tuple<ll,ll,ll>> adj[maxn];
ll d[maxn];

void input()
{
	cin>>n>>m;
	FOR(i,1,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({w,v,i});
		adj[v].pb({w,u,i});
	}
}

void bfs(int s)
{
	mset(d,0x3f3f);
	d[s]=0;
	priority_queue<ii,vector<ii>, greater<ii>> q;
	q.push({0,s});
	while(!q.empty())
	{
		auto [du,u]=q.top();
		q.pop();
		if(du!=d[u])	continue;
		for(auto [dv,v,i]:adj[u])
			if(minimize(d[v],du+dv))
				q.push({d[v],v});
	}
}

bool ck[maxn],vis[maxn];
void dfs(int u)
{
	if(u==1||vis[u])	return;
	
	ll curr=inf,nx=0,nx_id=0;
	for(auto [dv,v,id]:adj[u])
		if(d[u]-dv==d[v])
			if(minimize(curr,dv))
				nx=v,nx_id=id;
	vis[u]=1;
	ck[nx_id]=1;dfs(nx);
}

void lds_go_goooo()
{
	bfs(1);
	FOR(i,1,n)	cout<<d[i]<<' ';
	cout<<endl;
	ii b[maxn];
	FOR(i,2,n)	dfs(i);
	FOR(i,1,n)
		b[i]={d[i],i};
//	sort(b+2,b+n+1);
//	FOR(i,2,n)	dfs(b[i].se);
	//dfs(3);
	cout<<accumulate(ck,ck+m+1,0)<<endl;
	FOR(i,1,m)	if(ck[i])	cout<<i<<" ";
		
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
