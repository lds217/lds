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
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}

//main

string s;
ll n;

void input()
{
	cin>>n>>s;
}
void lds_go_goooo()
{
	stack <char> st1,st2;
	vector<ll> ans;
	bool to1=0,to2=0;
	FOR(i,0,n-1)
	{
		if(s[i]=='(')
			if(!st2.empty()&&st2.top()==')')
			{
				st2.pop();
				ans.pb(2);
				to2=1;
			}
			else
			{
				st1.push(s[i]);
				ans.pb(1);
				to1=1;
			}
		else
			if(!st1.empty()&&st1.top()=='(')
			{
				st1.pop();
				ans.pb(1);
			}
			else
			{
				st2.push(s[i]);
				ans.pb(2);
			}
	}
	if(st1.empty()&&st2.empty())
	{
		if(to1==1&&to2==1)
			cout<<2<<endl;
		else
			cout<<1<<endl;
		if(to2*to1==0)
			FOR(i,1,n)
				cout<<1<<' ';
		else
			for(int i:ans)
				cout<<i<<' ';
	}
	else
		cout<<-1;
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
