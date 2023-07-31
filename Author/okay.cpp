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
#define task "banhkhuc"

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

int n,k;
struct susss {
	int node,bitmask,cost;
};
bool must[505];
vector <ii> ke[505];
int mustid[505];
void input()
{
	cin>>n>>k;
	FOR(i,1,n)
		FOR(j,1,n)
		{
			int u;
			cin>>u;
			if(u)
				if(j==1)
					ke[i].pb({n+1,u});
				else
				ke[i].pb({j,u});
		}
		FOR(i,1,k)
		{
			int u;
			cin>>u;
			mustid[u]=i-1;
			must[u]=1;
		}
		mustid[n+1]=k;
		must[n+1]=1; 
}

ll dis[505][200000];

void lds_go_goooo()
{
	queue <sus> q;
	q.push({1,0,0});
	mset(dis,0x3f);
	dis[1][0]=0;
	while(!q.empty())
	{
		sus u=q.front();
		q.pop();
		if(u.cost!=dis[u.node][u.bitmask])	continue;
		for(ii i:ke[u.node])
		{
			int v=i.first;
			int dv=i.second;
			int newmask=u.bitmask;
			if(must[v])
			{
				int vid=mustid[v];
				newmask|= (1<<vid);
			}
			int newcost=u.cost+dv;
			if(newcost<dis[v][newmask])
			{
				dis[v][newmask]=newcost;
				q.push({v,newmask,newcost});
			}
		}
	}
/*	FOR(i,1,n+1)
	{
		FOR(j,0,pow(2,3))
			if(dis[i][j]<1e9)
			cout<<dis[i][j]<<' ';
			else
			cout<<0<<' ';
		cout<<endl;
	}*/
		
		cout<<dis[n+1][(1<<(k+1))-1];	
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
