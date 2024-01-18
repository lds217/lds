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
const ll maxn=2*1e5+2;
const ll mod=998244353;
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
    return b%2==0 ? (tmp*tmp)%mod : ((tmp*tmp)%mod*a) % mod;
}

//main

struct lds{
	int u,v,w;
} a[maxn];

int n,s,r[maxn],sz[maxn];
void input()
{
	cin>>n>>s;
	FOR(i,1,n-1)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[i]={u,v,w};
	}
	FOR(i,1,n)	r[i]=i,sz[i]=1;
}

int get(int u)
{
	return (r[u]!=u?r[u]=get(r[u]):u);
}

void unite(int u,int v)
{
	int du=get(u);
	int dv=get(v);
	r[du]=dv;
	sz[dv]+=sz[du];
}

void lds_go_goooo()
{
	sort(a+1,a+n,[](lds a,lds b)
	{
		return a.w<b.w;
	});
	int ans=1;
	FOR(i,1,n-1)
	{
		int su=sz[get(a[i].u)];
		int sv=sz[get(a[i].v)];
		ans=ans*POW(s-a[i].w+1,1LL*su*sv-1)%mod;
		unite(a[i].u,a[i].v);
	}
	cout<<ans;
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
