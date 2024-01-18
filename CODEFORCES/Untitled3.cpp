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

string s;
ll k;
ll cost[501][501];
ll dp[501][501];
void input()
{
	cin>>k;
	cin>>s;
}



ll DP(int pos,int used)
{
	if(pos==s.size()-1&&used==0)	return 0;
	if(pos==s.size()-1||used==0)	return inf;
	ll &res=dp[pos][used];
	if(res!=-1)
		return res;
	res=inf;
	FORD(i,s.size()-1,pos)
		res=min(res,DP(i,used-1)+cost[pos][i]);
	return res;
}

void lds_go_goooo()
{
	 FOR(i, 0, s.size()-1){
        FOR(j, i, s.size()-1){
            int len = (j - i + 1) / 2;
            FOR(x, 1, len)
                if(s[i + x - 1] != s[j - x + 1]) cost[i][j] ++;
        }
    }
	mset(dp,-1);
	cout<<DP(0,k);
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
