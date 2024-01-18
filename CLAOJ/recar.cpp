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
const ll maxn=3*1e4+2;
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

string s;
int h[maxn];
int a,b,c,n,k;
void input()
{
	cin>>a>>b>>c>>n>>k;
	cin>>s;
	h[0]=0;
	FOR(i,1,n)
	{
		if(s[i-1]=='R')
			h[i]=h[i-1];
		if(s[i-1]=='D')
			h[i]=h[i-1]-1;
		if(s[i-1]=='G')
			h[i]=h[i-1]+1;
	}
	int offset=*min_element(h,h+n+1);
	FOR(i,0,n)
		h[i]-=offset;
}
int pos[maxn],prepos[maxn];

void findpos()
{
	mset(prepos,-1);
	FOR(i,0,n)
	{
		pos[i]=prepos[h[i]];
		prepos[h[i]]=i;
	}
}

ll dp[maxn][1000];
void lds_go_goooo()
{
	findpos(); //để lưu vị trí chứa chiều cao đó gần nhất bên trái
	// gọi dp[i][j] là chi phí tối ưu khi xây đến vị trí i và có j cây cầu, hầm dc xây
	mset(dp,0x3f);
	int bridge=0; //số cầu đã xây
	dp[0][0]=0;
	FOR(i,1,n)
	{
		if(h[i]==h[i-1])// không thay đổi
			FOR(j,0,min(k,bridge))
				dp[i][j]=dp[i-1][j]+a;
		else
		{
			if(pos[i]==-1) // nếu không có điểm nào phía trước
			{
				FOR(j,0,min(k,bridge))
					dp[i][j]=dp[i-1][j]+b;
			}
			else // nếu có điểm phía trước, xây cầu thoai!!!
			{
				bridge++;
				dp[i][0]=dp[i-1][0]+b;
				FOR(j,1,min(k,bridge))
					dp[i][j]=min(dp[i-1][j]+b,dp[pos[i]][j-1]+c*(i-pos[i])); //không xây cầu hoặc xây thim 1 cây cầu từ vị trí cùng độ cao
			}
		}
	}
	ll ans=1e9;
	FOR(i,0,min(k,bridge))
		ans=min(ans,dp[n][i]);
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
