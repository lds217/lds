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
#define task "40"

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

char s1[100001],s2[1000001];
int n;
void input()
{
	cin>>n;
	FOR(i,1,n)
		cin>>s1[i];
	FOR(i,1,n)
		cin>>s2[i];
}
void lds_go_goooo()
{
	int ans=0;
	s1[0]=s2[0]=s1[n+1]=s2[n+1]='0';
	FOR(i,0,n-1)
	{
		if(s1[i]==s1[i+2]&&s1[i]!=s1[i+1]&&s2[i]==s2[i+2]&&s2[i]!=s2[i+1])
		{
			s1[i+1]='0'+'1'-s1[i+1];
			s2[i+1]='0'+'1'-s2[i+1];
			ans++;
		}
		if(s1[i]=='0'&&s1[i+1]=='1')	ans++;
		if(s2[i]=='0'&&s2[i+1]=='1')	ans++;
	}
	cout<<ans;
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("lights.in.10", "r", stdin);
   //freopen(task".out", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
