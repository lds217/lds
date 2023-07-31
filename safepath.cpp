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

ll n,m,d[maxn][maxn];
char a[maxn][maxn];
ii s,e;
queue <ii> fences; 
bool vis[maxn][maxn];
void input()
{
	
	mset(vis,0);
	mset(d,0x3f);
	cin>>n>>m;
	FOR(i,1,n)
		FOR(j,1,m)
		{
			cin>>a[i][j];
			if(a[i][j]=='S')	s={i,j};
			if(a[i][j]=='E')	e={i,i};
			if(a[i][j]=='#')	fences.push({i,j}),d[i][j]=0;
		}
}

void bfs()
{	
	while(!fences.empty())
	{
		ll x=fences.front().fi;
		ll y=fences.front().se;
		fences.pop();
		FOR(i,0,3)
		{
			ll nx=x+moveX[i];
			ll ny=y+moveY[i];
			if(nx<1||nx>n||ny<1||ny>m)	continue;
			if(d[nx][ny]>d[x][y]+1)
			{
				d[nx][ny]=d[x][y]+1;
				fences.push({nx,ny});
			}
		}
	}
}

bool check(ll k)
{
	mset(vis,0);
	queue <ii> q;
	if(d[s.fi][s.se]>=k)
		q.push(s),vis[s.fi][s.se]=1;
	
	while(!q.empty())
	{
		ll x=q.front().fi;
		ll y=q.front().se;
		q.pop();
		FOR(i,0,3)
		{
			ll nx=x+moveX[i];
			ll ny=y+moveY[i];
			if(nx<1||nx>n||ny<1||ny>m)	continue;
			if(vis[nx][ny]==0&&d[nx][ny]>=k)
			{
				vis[nx][ny]=1;
				q.push({nx,ny});
			}
		}
	}
	if(vis[e.fi][e.se])	return 1;
	else	return 0;
}

void lds_go_goooo()
{
	bfs();
/*	FOR(i,1,n)
	{
		FOR(j,1,m)	cout<<d[i][j]<<' ';
		cout<<endl;
	}*/
	ll l=0,r=maxn,ans=-1;

	while(l<=r)
	{
		
		ll mid=(l+r)/2;
		if(check(mid)) 		l=mid+1,ans=mid;
		else r=mid-1;
	}
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
