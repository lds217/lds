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
#define task "river"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e6+2;
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

ll n,j,m;
ll d[maxn];

void input()
{
	cin>>n>>m>>j;
}

bool check(ll k)
{
	ll cnt=0;
	FOR(i,0,n-1)
	{
		ll tmp=0;
		ll chay=i;
		if(d[i]>k)
			return 0;
		while(tmp<=k)
		{
			if(d[chay]>k)
				return 0;
			tmp+=d[chay];
			if(tmp>k)
				break;
			chay++;
			if(chay>n-1)	break;
		}
		i=chay-1;
		cnt++;
		if(cnt>j)	return 0;
	}

	return 1;
}

void lds_go_goooo()
{
	mset(d,0);
	FOR(i,0,n-1)
		d[i]=1+((1LL*(i*i))%m);
	ll ans=0;
	ll l=0,r=1e9+7;
//	cout<<check(9)<<endl;
	while(l<=r)
	{
		ll mid=(l+r)/2;
	//	cout<<l<<' '<<mid<<' '<<r<<endl;
		if(check(mid))r=mid-1,ans=mid;
		else	l=mid+1;
	}
	cout<<ans;
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
