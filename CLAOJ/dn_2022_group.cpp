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
long long x[500005],y[500005];
long long d[500005];
bool eratos[10000000];
vector <long long> k[500005];
long long m,n,p;
long long dupx[100000],dupy[1000000];
void pre_era()
{
	mset(eratos,0);
	eratos[0]=eratos[1]=1;
	for(int i=2;i*i<=1e6;i++)
		if(eratos[i]==0)
			for(int j=i*i;j<=1e6;j+=i)
				eratos[j]=1;
}

void input()
{
	pre_era();
	long long tmp;
	cin>>tmp;
	int a[100001];
	m=tmp;
	FOR(i,1,tmp)	cin>>a[i];
	int track=1;
	FOR(i,1,tmp-1)
		FOR(j,i+1,tmp)
			if(i!=j)
			if(eratos[a[i]+a[j]]==0)
			{

				k[i].pb(j);
			}
	FOR(i,1,m)
	{
		cout<<i<<" ";
		for(int j:k[i])
			cout<<j<<' ';
		cout<<endl;
	}
}

bool bfs()
{
	queue <int> q;
	FOR(i,1,m)
		if(x[i]==0)
			d[i]=0,q.push(i);
		else
			d[i]=1e9;
	d[0]=1e9;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(d[u]<d[0])
			for(int v: k[u])
				if(d[y[v]]>=1e9)
				{
					d[y[v]]=d[u]+1;
					q.push(y[v]);
				}
	}
	
	return (d[0]<1e9);
}

bool dfs(int u)
{
	if(u==0)	return 1;
	for(int v:k[u])
		if(d[y[v]]==d[u]+1)
			if(dfs(y[v]))
			{
				x[u]=v;
				y[v]=u;
				return 1;
			}
	d[u]=1e9;
	return 0;
}

void lds_go_goooo()
{
	int cnt=0;
	
	while(bfs())
	{	
		FOR(i,1,m)
			if(x[i]==0)
				if(dfs(i))
					cnt++;
	}
	FOR(i,0,m)
	cout<<i<<' '<<x[i]<<endl;
	cout<<cnt-1;
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
