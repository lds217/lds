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

int n,m;
char [maxn][maxn];
vector<ii> nhim,chau;
void input()
{
	cin>>n>>m;
	FOR(i,1,n)
	{
		cin>>a[i];
		if(a[i]=='X')	nhim.pb({i,j});
		if(a[i]=='L')	chau.pb({i,j})
	}
}
void lds_go_goooo()
{
	while(ok)
	{
		int nhim_chon_chau[200];
		mset(nhim_chon_chau,-1);
		int optchau=-1;
		FOR(i,0,nhim.size()-1)
		{
			int opt=-1;
			FOR(j,0,chau.size()-1)
				if(opt==-1|| dist(i,opt)>dist(i,j))
					opt=j;

			nhim_chon_chau[i]=opt;
			if(optchau==-1 || dist(i,opt)<dist(optchau,nhim_chon_chau[optchau]))
				optchau=i;
		}
		
		
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
