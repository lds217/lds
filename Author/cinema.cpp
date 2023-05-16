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
#define task "30"

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

long long a[maxn],pre[maxn];
long long n,q;
long long tree[4000000],tree1[4000000];

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = pre[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

int getmax(int id, int l, int r, int u, int v)
{
    if (v < l || u > r)
        return -1e9;
    if (u <= l && v >= r)
        return tree[id];
    int mid = (l + r) / 2;
    return max(getmax(id*2,l,mid,u,v),getmax(id*2+1,mid + 1, r,u,v));
}

void build1(int id, int l, int r)
{
    if (l == r)
    {
        tree1[id] = pre[l];
        return;
    }
    int mid = (l + r) / 2;
    build1(id * 2, l, mid);
    build1(id * 2 + 1, mid + 1, r);
    tree1[id] = min(tree1[id * 2], tree1[id * 2 + 1]);
}

int getmin(int id, int l, int r, int u, int v)
{
    if (v < l || u > r)
        return 1e9;
    if (u <= l && v >= r)
        return tree1[id];
    int mid = (l + r) / 2;
    return min(getmin(id*2,l,mid,u,v),getmin(id*2+1,mid + 1, r,u,v));
}
void input()
{
	cin>>n>>q;
	FOR(i,1,n)
		cin>>a[i];
	
	
}
void lds_go_goooo()
{
	FOR(i,1,n)
		pre[i]=pre[i-1]+a[i];
	
	build(1, 1, n);
	build1(1, 1, n);
	
	
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		cout<<getmax(1,1,n,v,n)-getmin(1,1,n,1,u-1)<<endl;
	}
	
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
