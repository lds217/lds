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

string s;
ll pre[maxn];
ll n;
void input()
{
	cin>>s;
	n=s.size();
	s="#"+s;
}

bool ck(char &c)
{
	return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
 } 

void prepare()
{
	FOR(i,1,n+5)
		if(ck(s[i]))
			pre[i]=pre[i-1]+1;
		else
			pre[i]=pre[i-1];
}

void lds_go_goooo()
{
	mset(pre,0);
	prepare();
	//FOR(i,0,n)
	//	cout<<pre[i]<<" ";
//	cout<<n<<endl;
	FOR(l,1,n)
		FOR(r,l+2,n)
		{
			ll mid=r-1;
			while(mid>=(l+r+1)/2)
			{
				if(pre[l+r-mid]-pre[l-1]>=2&&s.substr(l,r-mid+1)==s.substr(mid,r-mid+1)&&pre[mid-1]-pre[l+r-mid]>=1)
				{
				//	cout<<l<<' '<<mid<<' '<<r<<endl;
					cout<<"Spell!";
					return;
				}
			mid--;	
			}
		}
	cout<<"Nothing.";
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    FOR(i,1,test_case)
    {
         input();cout<<"Case #"<<i<<": " ;lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}