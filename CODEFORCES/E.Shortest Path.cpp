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
const ll maxn=2*1e3+2;
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

ll n,m,q;
vector <ll> k[maxn];
void input()
{
	cin>>n>>m>>q;
}

ll d[maxn];
map <array<int,3>,bool> avoid;
bool vis[maxn][maxn];
ll trace[maxn][maxn];
void dijkstra()
{
	mset(vis,0);
	queue <array<int,2>> q;
	q.push({0,1});
	mset(d,0x3f);
//	vis[0][1]=1;
	FOR(i,0,maxn-1)
		vis[i][1]=1;
	d[1]=0;
	ll cnt=0;
	while(!q.empty())
	{
		ll x=q.front()[0],y=q.front()[1];
		q.pop();
		for(ll z:k[y])
		{
			
			if(avoid[{x,y,z}])	continue;
			
			if(vis[y][z]==0)
			{
				d[z]=min(d[z],cnt);
				vis[y][z]=1;
				q.push({y,z});
			}
			if(z==n)
				return;
		}
		cnt++;
	}
}

void lds_go_goooo()
{
	FOR(i,1,m)
	{
		ll u,v;
		cin>>u>>v;
		k[u].pb(v);
		k[v].pb(u);
	}
	FOR(i,1,q)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		avoid[{x,y,z}]=1;
	}
	dijkstra();
	FOR(i,1,n)
		cout<<d[i]<<' ';
	cout<<endl;
	cout<<d[n];
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
