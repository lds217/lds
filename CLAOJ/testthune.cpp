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
const ll maxn=1e7+2;
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

bool prime[maxn];
ll prefixprime[maxn];
ll number_of_prime[maxn];

void erathos()
{
	mset(number_of_prime,0);
	mset(prefixprime,0);
	for (ll i = 2; i*i <= maxn; ++i)
	{
		if (!prime[i])
		{
			for (ll j = i*i; j <= maxn; j+= i)
			{
				prime[j] = true;
			}
		}
	}
	
	for (ll i = 2; i <= maxn; ++i)
	{
		number_of_prime[i]=number_of_prime[i-1];prefixprime[i]=prefixprime[i-1];
		if (!prime[i]) number_of_prime[i]=number_of_prime[i-1]+1,	prefixprime[i]=prefixprime[i-1]+i;
	}
	
}

void input()
{

}
void lds_go_goooo()
{
	erathos();
	int q;
	cin>>q;
	//FOR(i,2,10)
	//	cout<<prefixprime[i]<<' ';
	while(q--)
	{
		int l,r,val;
		cin>>l>>r>>val;
		if(val>=r)
			cout<<(number_of_prime[r]-number_of_prime[l-1])*val-(prefixprime[r]-prefixprime[l-1]);
		else
			if(val<=l)
				cout<<-((number_of_prime[r]-number_of_prime[l-1])*val-(prefixprime[r]-prefixprime[l-1]));
			else
				cout<<(number_of_prime[val]-number_of_prime[l-1])*val-(prefixprime[val]-prefixprime[l-1])+((prefixprime[r]-prefixprime[val])-(number_of_prime[r]-number_of_prime[val])*val);
	}
}

int main()
{
 	//ios_base::sync_with_stdio(false);
    //cin.tie(0);
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
