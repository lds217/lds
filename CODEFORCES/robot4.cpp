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
typedef vector<int> vi;
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

int n,m;
vector <vector <int>> a,vs;
map<int,vi> row[maxn], col[maxn];
void input()
{
	cin>>n>>m;
	a = vector<vi>(n+2, vi(m+2, 0));
	vs = vector<vi>(n+2, vi(m+2, 0));
	FOR(i,1,n)
		FOR(j,1,m)
		{
			cin>>a[i][j];
			row[i][a[i][j]].pb(j);
			col[j][a[i][j]].pb(i);
		}
}

int dfs(int x,int y)
{
	if(vs[x][y])	return vs[x][y];
	vs[x][y]=1;
	auto itr=row[x].upper_bound(a[x][y]);
	if(itr!=row[x].end())
		for(int j: (*itr).second)
			vs[x][y]=max(vs[x][y],1+dfs(x,j));

		
	itr=col[y].upper_bound(a[x][y]);	
	if(itr!=col[y].end())
		for(int j: (*itr).second)
			vs[x][y]=max(vs[x][y],1+dfs(j,y));
		return vs[x][y];
}
void lds_go_goooo()
{
	
	int ans=0;
	FOR(i,1,n)
		FOR(j,1,m)
			ans=max(ans,dfs(i,j));

	cout<<ans;
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
