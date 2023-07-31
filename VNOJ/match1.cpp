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
#define task "match1"

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

int n,m,matchX[maxn],used[maxn];
vector <int> k[maxn];
int vertex=0;
void input()
{
	cin>>n>>m;
	int u,v;
	while(cin>>u>>v)
		k[u].pb(v),vertex++;
}
int cur;

bool dfs(int u){
	if(used[u]==cur)	return 0;
	used[u]=cur;
	for(int v:k[u])
	{
		if(matchX[v]==0||dfs(matchX[v]))
		{
			matchX[v]=u;
			return 1;
		}
	}
	return 0;
}

void lds_go_goooo()
{
	int res=0;
	for(cur=1;cur<=vertex;cur++)
		res+=dfs(cur);
	cout<<res<<endl;
	FOR(i,1,n)
		if(matchX[i])
			cout<<matchX[i]<<' '<<i<<endl;
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
