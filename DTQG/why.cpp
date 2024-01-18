// Template //
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <array>
#include <cassert>
#include <random>

#define FOR(i, a, b) for (ll i = a, _b = b; i <= _b; i++)
#define FORD(i, a, b) for (ll i = a, _b = b; i >= _b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}

template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//
int n,m,w[maxn],h[maxn],up[maxn][21];
vector <int> adj[maxn];
void input()
{
    cin>>n>>m;
    FOR(i,1,n)  cin>>w[i];
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void dfs(int u, int lvl, int par)
{
	h[u]=lvl;
	up[u][0]=par;
	for(int v: adj[u])
		if(v!=par)
			dfs(v,lvl+1,u);
}

int __gcd(int a, int b) { 
    if (b == 0) { 
        return a; 
    } 
    return gcd(b, a % b); 
}


int LCA(int a, int b)
{
	if(h[b]<h[a])
		swap(a,b);
	int d=h[b]-h[a];

	while(d>0)
	{
		int i= log2(d);
		b=up[b][i];
		d-=(1<<i);
	}
	if(a==b)return a;
	FORD(i,20,0)
		if(up[a][i]!= -1 && up[a][i]!= up[b][i])
			a=up[a][i],b=up[b][i];
	
	return up[a][0];
}

void dfsup(int u,int v,int k)
{
    if(u==v)
        return;
    w[u]+=k;
    dfsup(up[u][0],v,k);
}

int dfsans(int u,int v)
{
    if(up[u][0]==v)
        return w[u];
    return __gcd(w[u],dfsans(up[u][0],v));
}


void lds_go_goooo()
{
    dfs(1,1,-1);
	for(int i=1;i<=20;i++)
		for(int j=1;j<=n;j++)
			if(up[j][i-1]!=-1)
			{
				int par= up[j][i-1];
				up[j][i]=up[par][i-1];
			}
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int u,v,k;
            cin>>u>>v>>k;
    
            int cha=LCA(u,v);
           // cout<<cha<<endl;
           w[cha]+=k;
            dfsup(u,cha,k);
            dfsup(v,cha,k);
        }
        else
        {
            int u,v;
            cin>>u>>v;
            int cha=LCA(u,v);
          //  cout<<cha<<endl;
            ll ans=__gcd(dfsans(u,cha),__gcd(dfsans(v,cha),w[cha]));
            cout<<ans<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "GCDIX"
    // freopen(task".INP", "r", stdin);
    // freopen(task".OUT", "w", stdout);
    // int sub=1;
    // cin>>sub;
    ll test_case = 1; // cin>>test_case;
    while (test_case--)
    {
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}

