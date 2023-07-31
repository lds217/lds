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

ll n,k;

void input()
{
	cin>>n>>k;
}

bool era[maxn];
vector <ll> prime;

void sieve()
{
	mset(era,0);
	era[0]=era[1]=1;
	for(ll i= 2;i*i<=1000000;i++)
		if(era[i]==0)
			for(ll j = i+i;j<=1000000;j+=i)
				era[j]=1;
	FOR(i,1,1000000)	if(!era[i])	prime.pb(i);
}
string str="";
vector <char> ans;
void lds_go_goooo()
{
	sieve();

	deque <ll> q; 
	
	FOR(i,1,n)
		str+=to_string(prime[i-1]);
//	k=str.size()-k;
//	cout<<str<<endl;
	n=str.size();
//	cout<<n<<k<<endl;
	ll e=0,b=0;
	for(ll i=0;i<=str.size()-k+ans.size();i++)
	{
		if(str[i]>b)
		{
			e=i;
			b=str[i];
		}
		if(i==str.size()-k+ans.size()&&ans.size()<k)
		{
			i=e+1;
			ans.pb(b);
			b=0;
		}
		cout<<e;
	}
	
		
	for(char i :ans)	cout<<i;
}

int main()
{
 	///ios_base::sync_with_stdio(false);
   // cin.tie(0);
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
