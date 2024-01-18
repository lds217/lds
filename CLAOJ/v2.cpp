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
#define task "DULICH"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e5+2;
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

int n,m,x;
vector <ii> adj[maxn];
int tickets[maxn];
void input()
{
	cin>>n>>m>>x;
	FOR(i,1,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({w,v});
		adj[v].pb({w,u});
	}
	FOR(i,1,n)
		cin>>tickets[i];
}
ll d[maxn][2];
void bfs(int st,int t)
{
	priority_queue<ii, vector<ii>,greater<ii>> q;
	q.push({0,st});
	d[st][t]=0;
	while(!q.empty())
	{
		auto [du,u]=q.top();q.pop();
		if(du!=d[u][t])	continue;
		for(auto [dv,v]: adj[u])
			if(minimize(d[v][t],d[u][t]+dv))
				q.push({d[v][t],v});	
	}

}

void lds_go_goooo()
{
	mset(d,0x3f);
	bfs(1,0);
	bfs(n,1);
		ll ans=1e9;
	FOR(i,1,n)
	{
		//int left;
		//if(d[i][0]<=x)
		//	d[i][1]-=(x-d[i][0]);
		double s=0,s1=0;
		if(d[i][0]>x)
			s=(d[i][0]-x)/x;
		if((d[i][0]-x)%x)
			s++;
		if(d[i][1]>tickets[i]*x)
			s1=(d[i][1]-tickets[i]*x)/x;
		if((d[i][1]-tickets[i]*x)%x)
			s1++;
		minimize(ans,s1+s);
	
		//cout<<i<<' '<<s1+s<<endl;
	}
	cout<<ans;
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
   // freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
