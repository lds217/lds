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
#define task "PER"

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

int n,q;
int a[maxn],b[maxn];
int SQRT=305;
struct Query{
	int x,y,u,v,id;
}Q[maxn];
bool sub2=1;

void input()
{
	cin>>n>>q;
	FOR(i,1,n)	cin>>a[i];
	FOR(i,1,n)	cin>>b[i];
	FOR(i,1,q)	{
		cin>>Q[i].x>>Q[i].y>>Q[i].u>>Q[i].v,Q[i].id=i;
		if(Q[i].x!=Q[i].u)	sub2=0;
		if(Q[i].y!=Q[i].v)	sub2=0;
	}
}

void sub1()
{
	FOR(i,1,q){
		int x=Q[i].x,y=Q[i].y,u=Q[i].u,v=Q[i].v;
		bool ck[10010];
		mset(ck,0);
		ll ans=0;
		FOR(i,x,y)
			if(ck[a[i]]==0)	ck[a[i]]=1;
		FOR(i,u,v)
			if(ck[b[i]])	ans++;
		cout<<ans<<"\n";
	}
}

int ans=0;
int cnta[maxn],cntb[maxn];
void add(int i)
{
	cnta[a[i]]=1;
	cntb[b[i]]=1;
	if(cnta[b[i]])
		ans++;
	if(cntb[a[i]])
		ans++;
	if(a[i]==b[i])	ans--;
}

void del(int i)
{
	cnta[a[i]]=0;
	cntb[b[i]]=0;
	if(cnta[b[i]]==0)
		ans--;
	if(cntb[a[i]]==0)
		ans--;
	if(a[i]==b[i])	ans++;
}

void sub22(){
	sort(Q+1,Q+1+q,[](Query a, Query b)
	{
		if(a.x/SQRT==b.x/SQRT)	return a.y<b.y;
		return a.x/SQRT<b.x/SQRT;
	});

	int res[maxn];
	int l=1,r=0;
	FOR(i,1,q)
	{
		while(Q[i].y>r)	add(++r);
		while(Q[i].y<r)	del(r--);
		while(Q[i].x<l)	add(--l);
		while(Q[i].x>l)	del(l++);	
		res[Q[i].id]=ans;
	}
	//cout<<r;
	FOR(i,1,q)
		cout<<res[i]<<"\n";
}
vector <int> tree[maxn];
int posb[maxn];


void build(int id,int l,int r)
{
	if(l==r)
	{
		tree[id].pb(posb[a[l]]);
		return;
	}
	int mid=(l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	merge(tree[2 * id].begin(),tree[2 * id].end(),tree[2 * id + 1].begin(),tree[2 * id + 1].end(),back_inserter(tree[id]));

}

int query( int index, int s, int e, int l, int r, int k)
{
    if (r < s || l > e)
        return 0;
    if (s >= l && e <= r) {
        return (tree[index].size()- (upper_bound(tree[index].begin(), tree[index].end(),k)- tree[index].begin()));
    }

    int mid = (s + e) / 2;
    return (query( 2 * index, s, mid, l, r, k)+ query( 2 * index + 1, mid + 1, e, l, r, k));
}

void subfull(){
	
	FOR(i,1,n)
		posb[b[i]]=i;
	build(1,1,n);
	FOR(i,1,q)
	{
		ll ans=0;
		ans+=query(1,1,n,Q[i].x,Q[i].y,Q[i].u-1);
		ans-=query(1,1,n,Q[i].x,Q[i].y,Q[i].v);
		cout<<ans<<"\n";
	}
}
// NAM MO A DI DA PHAT AC GIUP CON
void lds_go_goooo()
{
	if(n*q<=1000000)
		sub1();


		else
			subfull();
			
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
   // freopen(task".out", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
