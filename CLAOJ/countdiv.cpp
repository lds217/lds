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
#define int long long
using namespace std;
typedef long long ll;
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

ll gcd(ll a,ll b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}

void input()
{

}



void lds_go_goooo()
{
	ll N,L,R;
	while(cin>>N>>L>>R)
//	cin>>N>>L>>R;
	{
		ll a[21],ans1=0,ans2=0,lcm=0;
		FOR(i,0,N-1)
			cin>>a[i];
		for(ll mask=0;mask < (1<<N);mask++)
		{
		    	int cnt=0;
				bool first=1;
			for(int j=N-1;j>=0;j--)
			{
			
				if(((mask>>j)&1)==0)	continue;
				cnt++;
				if(first)
				{
					first=0;
					lcm=a[j];
				}
				else
					lcm=(lcm*a[j])/gcd(max(lcm,a[j]),min(lcm,a[j]));
				
			}
			if(lcm==0)	continue;		
			if(cnt%2)
			{
				ans1+=R/lcm;
				ans2+=(L-1)/lcm;
			}
			else
			{
				ans1-=R/lcm;
				ans2-=(L-1)/lcm;
			}
			
		}
		cout<<ans1-ans2<<endl;
	}
}
signed  main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; 
    while(test_case--)
    {
        input(), lds_go_goooo();
        //cout<<'\n';
    }
    return 0;
}
