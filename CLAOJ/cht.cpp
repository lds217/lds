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
const ll maxn=2*1e5+2;
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

struct CHT{
	 struct Line {
        ll slope, yIntercept;

        Line(ll slope, ll yIntercept) : slope(slope), yIntercept(yIntercept) {}

        ll val(ll x) {
            return slope * x + yIntercept;
        }

        ll intersect(Line y) {
            return (y.yIntercept - yIntercept + slope - y.slope - 1) / (slope - y.slope);
        }
    };
	
	deque<pair<Line, ll>> dq;
	
	void insert(ll slope, ll yIntercept){
		Line newLine(slope,yIntercept);
		
		while(dq.size()>1&&dq.back().se>=dq.back().first.intersect(newLine))
			dq.pop_back();
			
		if(dq.empty())
		{
			dq.emplace_back(newLine,0);
			return;
		}
		dq.emplace_back(newLine, dq.back().first.intersect(newLine));
	}
	
	ll query(ll x){
        while (dq.size() > 1) {
            if (dq[1].second <= x) dq.pop_front();
            else break;
        }
        
        return dq[0].first.val(x);
    }
};

ll h[maxn];ll dp[maxn];
ll n,c;
void input()
{
	cin>>n>>c;
}
void lds_go_goooo()
{
	FOR(i,0,n-1)	cin>>h[i];
	dp[0]=0;
	CHT cht;
	cht.insert(-2*h[0],h[0]*h[0]+dp[0]);

	FOR(i,1,n-1)
	{
		dp[i]=cht.query(h[i])+c+h[i]*h[i];
		cht.insert(-2*h[i],h[i]*h[i]+dp[i]);
	}
	cout<<dp[n-1];
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
