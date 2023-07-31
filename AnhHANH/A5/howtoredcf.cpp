// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "cheating"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=(2<<18) + 5;
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

ll n,m,s;
struct lds{
	ll ability,cost,id;
}helper[maxn];

pair<int,int> a[maxn];
void input()
{
	cin>>n>>m>>s;
//	swap(n,m);
//	mset(tmp,0);
//	mset(a,0);
	FOR(i,1,m)	cin>>a[i].fi,a[i].se=i;
	FOR(i,1,n)	cin>>helper[i].ability;
	FOR(i,1,n)	cin>>helper[i].cost,helper[i].id=i;
}

bool check(ll dis)
{
	ll i=m,j=n;
	priority_queue <ll, vector <ll>, greater <ll>> q;
	ll sum=0;
	while(i>0)
	{
		while(j>0&&a[i].fi<=helper[j].ability)	q.push(helper[j].cost),j--;
		if(q.empty())	return 0;
		sum+=q.top();
		i-=dis;
		q.pop();
	}
	return sum<=s;
}



void lds_go_goooo()
{
	sort(a+1,a+m+1,[](ii a,ii b)
	{
		return ((a.fi<b.fi) || (a.fi==b.fi&&a.se<b.se));
	});
	sort(helper+1,helper+n+1,[](lds a,lds b)
	{
		return ((a.ability<b.ability ) || (a.ability==b.ability && a.cost<b.cost));
	});

	if(a[m].fi>helper[n].ability)
	{
		cout<<"NO";
		cout<<endl;
		return ;
	}
	ll l=1,r=m,ans=-1;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	if(ans==-1)	cout<<"NO"<<endl;
	else
	{
		int res[maxn];
		int i=m,j=n;
		priority_queue <ii, vector <ii>, greater <ii>> q;
		while(i>0)
		{
			while(j>0&&a[i].fi<=helper[j].ability)	q.push({helper[j].cost,helper[j].id}),j--;
			for(int z=i;z>max(0LL,i-ans);z--)	res[a[z].se]=q.top().se;
			i-=ans;
			q.pop();
		}
		cout<<"YES"<<endl;
		FOR(i,1,m)
			cout<<res[i]<<' ';
	}

}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll sub=0;
    cin>>sub;
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        	cout<<endl;
    }
    return 0;
}
