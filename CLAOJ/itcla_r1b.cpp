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
#define task "divpow"

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

long long n;

void input()
{
	cin>>n;
}

long long cnt(long long x)
{
	long long sum=0;
	for(long long i=1;i*i<=x;i++)
		if(x%i==0)
		{
			if(i*i==x)
				sum+=1;
			else
				sum+=2;
		}
	return sum;
}

void lds_go_goooo()
{
	double p=1;

	while(1)
	{
		long long k=pow(p,cnt(p));
		if(k==n)
		{
			cout<<p;
			return;
		}
		else
			if(k>n)
			{
				cout<<-1;
				return;
			}
		p++;
		
	}
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
