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

struct Line{
    ll m, k;
    ll eval(ll x){
        return m*x+k;
    }
};
 
deque<Line> hull;
 
bool bad(const Line &A, const Line &B, const Line &C){
    return (B.k-A.k)*(C.m-A.m)-(C.k-A.k)*(B.m-A.m) < 0;
}
 
void add(ll m, ll k){
    Line L = {m, k};
    while (hull.size() >= 2 && bad(hull[hull.size()-2], hull.back(), L)) hull.pop_back();
    hull.push_back(L);	
}
ll n,a[maxn],c;
ll dp[maxn];
void input()
{
	cin>>n>>c;
	FOR(i,1,n)
		cin>>a[i];
}
void lds_go_goooo()
{
	add(-2*a[1],a[1]*a[1]);
	FOR(i,2,n)
	{
		while(hull.size()>=2 && hull[0].eval(a[i])>= hull[1].eval(a[i]))	hull.pop_front();
		dp[i]=hull[0].eval(a[i])+a[i]*a[i]+c;
		add(-2*a[i],dp[i]+a[i]*a[i]);
	}
	cout<<dp[n];
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
