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
const ll maxn=2e5+100;
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
#define ll int
int q;
struct Query{
	string type;
	int u,v,id;
}Q[maxn];
bool cksub3=1;
vector <ii> adj[maxn];

void input()
{
	cin>>q;
	FOR(i,1,q)
	{
		string type;
		int u,v;
		cin>>type>>u>>v;
		Q[i]={type,u,v,i};
		if(type=="Query"&&u!=1)
			cksub3=0;
	}
}
int fin[maxn];
int fout[maxn];
int cnt=0,ans=0;
//void tour(int u,int par)
//{
//	fin[u]=++cnt;
//	for(auto [v,w]:adj[u])
//		if(v!=par)
//			tour(v,u);
//	fout[u]=++cnt;
//}
//
//bool u_con_s(int u,int v)
//{
//	return(fin[v]<=fin[u]&&fout[u]<=fout[v]);
//}
//
//void dfs(int u,int par,int s, int cur)
//{
//	if(u_con_s(u,s))	ans=max(ans,cur);
//	for(auto[v,w]:adj[u])
//		if(v!=par)
//			dfs(v,u,s,cur^w);
//}
//
//struct Trie{
//	struct Node{
//		int child[2];
//		int exist,cnt;
//	} nodes[200000*26];
//	
//	int cur=0;
//	Trie(){
//		cur=0;
//		mset(nodes[0].child,-1);
//		nodes[0].exist=nodes[0].cnt=0;
//	}
//	
//	int new_node()
//	{
//		cur++;
//		mset(nodes[cur].child,-1);
//		nodes[cur].exist=nodes[cur].cnt=0;
//		return cur;
//	}
//	
//	void add_number(int x) {
//        int pos = 0;
//        for (int i = 31; i >= 0; i--) {
//            int c = (x >> i) & 1;
//            if (nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
//            pos = nodes[pos].child[c];
//            nodes[pos].cnt++;
//        }
//        nodes[pos].exist++;
//    }
//
//
//	int query(int x) {
//	    int pos = 0, res = 0;
//	    for (int i = 31; i >= 0; i--) {
//	        int c = (x >> i) & 1;
//	
//	        if (nodes[pos].child[c ^ 1] != -1) {
//	            res += (1ll << i);
//	            pos = nodes[pos].child[c ^ 1];
//	        }
//	        else {
//	            pos = nodes[pos].child[c];
//	        }
//	    }
//	   	return res;
//	}
//};
//
//void sub2()
//{
//	int n=1;
//	FOR(i,1,q)
//	{
//		auto [type,u,v,id]=Q[i];
//		if(type=="Add")
//		{
//			n++;
//			adj[n].pb({u,v});
//			adj[u].pb({n,v});
//			mset(fin,0);
//			mset(fout,0);
//			cnt=0;
//			tour(1,-1);
//		}
//		else
//		{
//			ans=0;
//			dfs(u,u,v,0);
//			cout<<ans<<'\n';
//		}
//	}
////	FOR(i,1,n)
////		cout<<fin[i]<<' ';
////	cout<<endl;
////	FOR(i,1,n)
////		cout<<fout[i]<<' ';
//}
//
//void sub3()
//{
//	Trie T;
//	int sum[maxn];
//	mset(sum,0);
//	sum[1]=0;
//	T.add_number(sum[1]);
//		int n=1;
//	FOR(i,1,q)
//	{
//		auto [type,u,v,id]=Q[i];
//		if(type=="Add")
//		{
//			n++;
//			sum[n]=sum[u]^v;
//			T.add_number(sum[n]);
//		}
//		else
//		{
//			cout<<T.query(sum[u])<<'\n';
//		}
//	}
//}
int sum[maxn];
void dfss(int u,int par,int curr)
{
	sum[u]=curr;
	fin[u]=++cnt;
	for(auto[v,w]: adj[u])
		if(v!=par)
			dfss(v,u,curr^w);
	fout[u]=cnt;
}

int tree[200000*25][2];
set<int> store[200000*25];

void add(int x,int pos)
{
	int now=0;
	FORD(i,29,0)
	{
		int c=BIT(x,i);
		if(tree[now][c]==0)
			tree[now][c]=++cnt;
		now=tree[now][c];
		store[now].insert(pos);
	}
}

bool check(int na,int l,int r){
    return store[na].lower_bound(l) != store[na].upper_bound(r);
}

ll get(int val,int l,int r){
	
    int now = 0;
    ll ans = 0;
 
    FORD(i,29,0){
        bool p = (val >> i & 1);
        int up = tree[now][p ^ 1];
        if(up && check(up,l,r)){
            ans += MASK(i);
            now = up;
        }
        else if(check(tree[now][p], l, r))
            now = tree[now][p];
        else
            return ans;
        if(!now) return ans;
    }
 
    return ans;
}

void full()
{
	int n=1;
//	mset(tree,-1);

	FOR(i,1,q)
	{
		auto [type,u,v,id]=Q[i];
		if(type=="Add")
		{
			n++;
			adj[u].pb({n,v});
		}
	}
	mset(fin,0);
	mset(fout,0);
	cnt=0;
	n=1;
	dfss(1,-1,0);
		add(0,1);
	FOR(i,1,q)
	{
		auto [type,u,v,id]=Q[i];
		if(type=="Add")
		{
			n++;
			add(sum[n],fin[n]);
		}
		else
		{
			cout<<get(sum[u],fin[v],fout[v])<<'\n';
		}
	}
}

void lds_go_goooo()
{
//	if(q<=2000)
//		sub2();
//	else
//		if(cksub3)
//			sub3();
//		else
			full();
}

signed main()
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
