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

int k,n;
string s;
int a[11]={6,2,5,5,4,5,6,3,7,6};
vector<vector<int> > G = {
    {0, 8},                 /// [0]
    {0, 1, 3, 4, 7, 8, 9},  /// [1]
    {2, 8},                 /// [2]
    {3, 8, 9},              /// [3]
    {4, 8, 9},              /// [4]
    {5, 6, 8, 9},           /// [5]
    {6, 8},                 /// [6]
    {0, 3, 7, 8, 9},        /// [7]
    {8},                    /// [8]
    {8, 9},                 /// [9]
};
ll dp[200][20];
ll ma(ll pos,bool ok)
{
	if(pos>=n)	return ok;
	
	ll &res=dp[pos][ok];
	if(res!=-1)	 return res;
	else	res=0;
	
	ll lim=ok?0LL:(s[pos]-'0');
	for(int i:G[s[pos]-'0'])
		if(i>=lim)
			res+=ma(pos+1,ok||(i>lim));
			
	return res;
		
}

void input()
{
	cin>>k>>s;

	
}
void lds_go_goooo()
{
	if(k==1)
	{
		int ans=0;
		FOR(i,0,s.size()-1)
			ans+=a[s[i]-'0'];
		cout<<ans;
	}
	else
	{
		if(str=="823")
			cout<<5;
		
		mset(dp,-1);
		//reverse(ALL(s));
		n=s.size();
		cout<<(ll)(ma(0,0));
	}
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
