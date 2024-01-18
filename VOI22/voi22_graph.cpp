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

int n,b;
int a[maxn];
int cnt=0;
void input()
{
	cin>>n>>b;
	FOR(i,1,n)
	{
		cin>>a[i];
		if(a[i]==-1)
			cnt++;
	}
}


int ans=0;


void sub1()
{

}

void sub2()
{
	int pos=0;
	FOR(i,1,n)
		if(a[i]==-1)
		{
			pos=i;
			break;
		}
	ll ans=0;
	FOR(i,0,pos-1)
	{
		bool ok=1;
		a[pos]=i;
		FOR(j,1,n)
		{
			ll sum=a[j];
			FOR(z,j+1,n)
				if(a[z])
					sum++;
			if(sum>b){
				ok=0;
				break;
			}
		}
		if(ok)
			ans++;
	}
	cout<<ans;
}
int dp[maxn][maxn]
void sub3()
{
	
}

void sub4()
{
	
}

void lds_go_goooo()
{
//	sub2();
	sub3()	;
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
