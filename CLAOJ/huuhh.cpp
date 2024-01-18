// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define id second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "a"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*2e6+2;
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

int n;
map <ll,ll> cnt;

void input()
{
	cnt.clear();
	cin>>n;
	FOR(i,1,n)	{int x;cin>>x;cnt[x]++;}
}



ll lds(ll b,ll c)
{
	ll d=b*b-4*c;
	if(d<0)	return 0;
	
	ll x1=(b+sqrt(d))/2;
	ll x2=(b-sqrt(d))/2;
	if(x1+x2!=b||x1*x2!=c)return 0;
	if(x1==x2)	return 1LL*cnt[x1]*(cnt[x1]-1)/2LL;
	return 1LL*cnt[x1]*cnt[x2];
	
}
	


void lds_go_goooo()
{
	int q;
	cin>>q;
	while(q--)
	{
	ll b,c;
		cin>>b>>c;
		cout<<lds(b,c)<<' ';
	}		
}
int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
  //  freopen(task".INP", "r", stdin);
  //  freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
