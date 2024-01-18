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
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp)%mod*a % mod;
}

//main

int n,m;
int a[501][501];

void input()
{
	cin>>n>>m;
	FOR(i,1,n)
		FOR(j,1,m)
			cin>>a[i][j];
}
ll pre[501][501];

void lds_go_goooo()
{
	ll ans=0;

	FOR(i,1,n)
	{
		vector<int> premax(m+5,0),suffmax(m+5,0);
		FOR(j,1,m)
		{	
			if(a[i][j]==a[i-1][j])
				pre[i][j]=pre[i-1][j]+1;
			else
				pre[i][j]=1;
		//	cout<<pre[i][j]<<' ';
		}
	//	cout<<endl;
		stack <int> s;
		int last=0;
		FOR(j,1,m)
		{
			if(a[i][j]!=a[i][j-1])
			{
				last=j;
				while(!s.empty())	s.pop();
			}
			while(!s.empty()&&(pre[i][s.top()]>=pre[i][j]))	s.pop();
			if(s.empty())	premax[j]=last;
			else	premax[j]=s.top()+1;
			s.push(j);
		}
	//	cout<<endl;
	//	cout<<i<<endl;
	
		while(!s.empty())	s.pop();
		FORD(j,m,1)
		{
			if(a[i][j]!=a[i][j+1])
			{
				last=j;
				while(!s.empty())	s.pop();
			}
			while(!s.empty()&&(pre[i][s.top()]>=pre[i][j]))	s.pop();
			if(s.empty())	suffmax[j]=last;
			else	suffmax[j]=s.top()-1;
			s.push(j);
		}
//		FOR(j,1,m)
//			cout<<premax[j]<<' ';
//		cout<<endl;
//		FOR(j,1,m)
//			cout<<suffmax[j]<<' ';
//		cout<<endl;
		FOR(j,1,m)
			ans=max(ans,(suffmax[j]-premax[j]+1)*pre[i][j]);
	}
	cout<<ans;
		
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
