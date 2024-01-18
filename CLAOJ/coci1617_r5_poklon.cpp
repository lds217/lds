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
const ll maxn=5e5+2;
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
const int SQRT = sqrt(maxn)+2;
int n,q,a[maxn],l=1,r=0,ans,res[maxn];
int cnt[maxn];
struct query{
	int l,r,id;
}qry[maxn];
ii st[maxn];
void input()
{
	cin>>n>>q;
	FOR(i,1,n)	cin>>st[i].fi,st[i].se=i;
	sort(st+1,st+n+1);
	int cnt=0;
	FOR(i,1,n)
	{
		if(st[i].fi!=st[i-1].fi)
			cnt++;
		a[st[i].se]=cnt;
	}
}

void add(int x)
{
	cnt[x]++;
	if(cnt[x]==2)
		ans++;
	if(cnt[x]==3)
		ans--;
}

void sub(int x)
{
	if(cnt[x]==3)
		ans++;
	if(cnt[x]==2)
		ans--;
	cnt[x]--;
	
}



void lds_go_goooo()
{
	FOR(i,1,q)
	{
		int l,r;
		cin>>l>>r;
		qry[i]={l,r,i};
	}
	
	sort(qry+1,qry+q+1,[&](query a, query b)
	{
		if(a.l/SQRT!=b.l/SQRT)	return a.l/SQRT<b.l/SQRT;
		return a.r<b.r;
	});
//	cout<<qry[1].l<<' '<<qry[1].r<<' '<<qry[1].id;
	FOR(i,1,q)
	{
		while(qry[i].r>r)	add(a[++r]);
		while(qry[i].r<r)	sub(a[r--]);
		while(qry[i].l<l)	add(a[--l]);
		while(qry[i].l>l)	sub(a[l++]);	
		res[qry[i].id]=ans;
	}
	FOR(i,1,q)
		cout<<res[i]<<endl;
}

int main()
{
 	//ios_base::sync_with_stdio(false);
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
