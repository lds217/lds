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
#define task "joiningletters"

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

string str,s;
int n;

void input()
{
	
}

ll dp[150005][5];
void lds_go_goooo()
{
	while(cin>>str)
	{
		if(str=="$")	break;
		n=str.size();
		s="ICPC";
		//mset(dp,0);
		
		FOR(i,0,4)
			dp[0][i]=dp[1][i]=0;
		FOR(i,0,n)
			dp[i][0]=1;
		if(str[0]=='I')
			dp[1][1]=1;
		FOR(i,2,n)
			FOR(j,1,4)
			{
				dp[i][j]=dp[i-1][j];
				//if(j-1==0)
				//	dp[i][j]+=1;
				//else
				if(str[i-1]==s[j-1])
					dp[i][j]+=dp[i-2][j-1];				
			}
		cout<<dp[n][4]<<"\n";
	}
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   // freopen(task".INP", "r", stdin);
   // freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
