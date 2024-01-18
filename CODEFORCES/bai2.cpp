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

int q;

void input()
{
	cin>>q;
}
const int NUMBEROFNODES = maxn;
struct Trie{
    struct Node{
        int child[2];
        int exist, cnt;
    } nodes[NUMBEROFNODES];

    int cur; 
    Trie() : cur(0) { 
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };

    int new_node() { 
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }

    void add(int s) {
        int pos = 0;
        FORD(i,32,0) {
            int c = BIT(s,i);
            if (nodes[pos].child[c] == -1) {
                nodes[pos].child[c] = new_node();
            }
            pos = nodes[pos].child[c];
            nodes[pos].cnt++; 
        }
        nodes[pos].exist++; 
    }

    bool delete_string_recursive(int pos, int& s, int i) {
        if (i != 0) { 
            int c = BIT(s,i);
            bool isChildDeleted = delete_string_recursive(nodes[pos].child[c], s, i - 1);
            if (isChildDeleted) nodes[pos].child[c] = -1;
        }
        else nodes[pos].exist--; 

        if (pos != 0) {
            nodes[pos].cnt--;
            if (nodes[pos].cnt == 0) return true;
        }
        return false;
    }

    void delete_string(int s) {
        if (find_string(s) == false) return; 
        delete_string_recursive(0, s, 32); 
    }

    bool find_string(int s) {
        int pos = 0;
        for (int i = 32; i >= 0; i--) {
            int c = (s >> i) & 1;
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0); 
    }

    int get(int x) {
        int pos = 0, res = 0;
        for (int i = 32; i >= 0; i--) {
            int c = (x >> i) & 1;

            if (nodes[pos].child[c ^ 1] != -1) {
                res += (1ll << i);
                pos = nodes[pos].child[c ^ 1];
            }
            else {
                pos = nodes[pos].child[c];
            }
        }
        return res;
    }
};

vector <ii> adj[maxn];
int ans;
void dfs(int u,int par,int con,bool ok,int cur)
{
	if(con==u)
		ok=1;
	if(ok==1)
		ans=max(ans,cur);
	
	for(auto [w,v]:adj[u])
		if(v!=par)
			dfs(v,u,con,ok,cur^w); 
}

void sub2()
{
	int n=1;
	while(q--)
	{
		string s;
		int u,v;
		cin>>s;
		cin>>u>>v;
		if(s=="Add")
		{
			n++;
			adj[u].pb({v,n});
			adj[n].pb({v,u});
		}
		else
		{
			ans=0;
			dfs(u,u,v,0,0);
			cout<<ans<<endl;
		}
	}
}


void sub3()
{
	Trie T;
	int n=1;
	int sum[maxn];
	sum[1]=0;
	T.add(0);
	while(q--)
	{
		string s;
		int u,v;
		cin>>s;
		cin>>u>>v;
		if(s=="Add")
		{
			n++;
			sum[n]=sum[u]^v;
			T.add(sum[n]);
		}
		else
		{
			//ans=0;
			//dfs(u,u,v,0,0);
			cout<<T.get(sum[u])<<endl;
		}
	}
}

void lds_go_goooo()
{
	if(q<=2000)
		sub2();
	else
		sub3();
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
