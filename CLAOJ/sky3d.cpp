// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#pragma GCC optimize ("O3")
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "sky"

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


bool minimize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

ll POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}

//main

vector <ll> k[maxn];
ll st,ed,n,m;
void input()
{
	cin>>n>>m;
	FOR(i,0,m-1)
	{
		ll b,p;
		cin>>b>>p;
		k[b].pb(p);
		if(i==0)
			st=b;
		if(i==1)
			ed=b;
	}
}

ll d[maxn];
void lds_go_goooo()
{
	mset(d,0x3f3f3f3f);
	d[st]=0;
queue<ii > pq;
	pq.emplace(0,st);
	while(!pq.empty())
	{
		ll du=pq.front().fi,u=pq.front().se; pq.pop();
		if(du!=d[u]) continue;
		if(u==ed)
		{
			cout<<d[u];
			return;
		}
		for(ll dis:k[u])
		{
			for(ll i=1;u+dis*i<n;i++)
				if(d[u]+i<d[u+dis*i])
				{
					d[u+dis*i]=d[u]+i;
					pq.emplace(d[u]+i,u+dis*i);
				}
			for(ll i=1;u-dis*i>=0;i++)
				if(d[u]+i<d[u-dis*i])
				{
					d[u-dis*i]=d[u]+i;
					pq.emplace(d[u-dis*i],u-dis*i);
				}
		}
	}
	cout<<-1;
	/*
	5 3
	0 2
	1 1
	4 1
	*/
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}