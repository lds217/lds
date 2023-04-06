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
#define task ""

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e4+2;
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
        // Main Function //

int R,C;
char a[maxn][maxn];
int d[maxn][maxn];
void input()
{
	cin>>R>>C;
	FOR(i,1,R)	FOR(j,1,C)	cin>>a[i][j];
}

void solve()
{
	int ans=0,cur=0;
	queue<ii> q[2];
	
	mset(d,-1);
	d[1][1]=1;
	q[0].push({1,1});
	while(q[0].size()!=0||q[1].size()!=0)
	{
		int u=q[cur].front().fi, v=q[cur].front().se;
		ans=max(ans,d[u][v]);
		q[cur].pop();
		FOR(i,0,3)
		{
			int du = u + moveX[i];
			int dv = v + moveY[i];
		
			if(a[u][v]==a[du][dv]&&d[du][dv]==-1)
			{
				d[du][dv]=d[u][v];
				q[cur].push({du,dv});
			}
			if(a[du][dv]==('T'+'B'-a[u][v])&&d[du][dv]==-1)
			{
				d[du][dv]=d[u][v]+1;
				q[1-cur].push({du,dv});
			}
		}
		if(q[cur].empty()) cur =1-cur;
	}
	cout<<ans;
}

int main()
{
   // ios_base::sync_with_stdio(false);
   // cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
