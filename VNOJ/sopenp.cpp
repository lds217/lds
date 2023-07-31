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
const ll maxn=pow(2,20)+1;
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

ll n,l,r;ii a[maxn];ll compress[maxn];
ll dupp[maxn];

void input()
{
	cin>>n>>l>>r;
	FOR(i,0,n-1)
		cin>>a[i].fi,a[i].se=i;
}

ll get(ll x)
{
	mset(dupp,0);
	if(x==0)	return 0;
	int cnt=0;
	int curr=-1;
	ll ans=0;
	FOR(i,0,n-1)
	{
		if(cnt<=x&&curr!=n)
			for(curr=curr+1;curr<n;curr++)
			{
				if(dupp[compress[curr]])
					dupp[compress[curr]]++;
				else
				{
					cnt++;
					dupp[compress[curr]]=1;
				}
				if(x<cnt)	break;
			}
		ans+=curr-i;
		dupp[compress[i]]--;
		if(!dupp[compress[i]]) cnt--;
	}
	return  ans;
}

void lds_go_goooo()
{
	sort(a,a+n);
	int pos=0;
	compress[a[0].se]=0;
	FOR(i,1,n-1)
		if(a[i].fi!=a[i-1].fi)
			compress[a[i].se]=++pos;
		else
			compress[a[i].se]=pos;
	cout<<get(r)-get(l-1);
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
