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

struct epl{
	int point,hs,goal,ind;
} a[maxn];

int n,m;

void input()
{
	cin>>n>>m;
	FOR(i,1,n)
		a[i].ind=i;
	FOR(i,1,m)
	{
		int team1,team2;
		string result;
		cin>>team1>>team2;
		cin>>result;
		int res1=result[0]-'0';
		int res2=result[2]-'0';
		a[team1].goal+=res1;
		a[team2].goal+=res2;
		a[team1].hs+=res1-res2;
		a[team2].hs+=res2-res1;
		if(res1>res2)
			a[team1].point+=3;
		else
			if(res2>res1)
				a[team2].point+=3;
			else
			{
				a[team1].point+=1;
				a[team2].point+=1;	
			}	
	}
}
void lds_go_goooo()
{
	sort(a+1,a+n+1,[](epl a, epl b)
	{
		if(a.point>b.point)
			return 1;
		else
			if(a.point==b.point)
			{
				if(a.hs>b.hs)
					return 1;
				else
					if(a.hs==b.hs)
					{
						if(a.goal<b.goal)
							return 1;
						else
							if(a.goal==b.goal)
							{
								if(a.ind>b.ind)
									return 1;
							}
							else
								return 0;
					}
					else
						return 0;
			}
			else
				return 0;
	});
	//cout<<a[2].goal;
	int ans[maxn];
	FOR(i,1,n)
		cout<<a[i].ind<<endl;
	
	//FOR(i,1,n)
//		ans[a[i].ind]=i;
//	FOR(i,1,n)
//		cout<<ans[i]<<' ';
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
