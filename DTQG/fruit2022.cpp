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
const ll maxn = 2e4 + 100;
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
const int LOG=23;
int n,q;
int c[maxn];
vector <int> adj[maxn];
int LCA[maxn][25];
int h[maxn];

void dfs(int u, int lvl, int par)
{
	h[u]=lvl;
	LCA[u][0]=par;
	for(int v: adj[u])
		if(v!=par)
			dfs(v,lvl+1,u);
}

void init()
{
	dfs(1,1,-1);
	for(int i=1;i<=LOG;i++)
		for(int j=1;j<=n;j++)
			if(LCA[j][i-1]!=-1)
			{
				int par= LCA[j][i-1];
				LCA[j][i]=LCA[par][i-1];
			}
			
}
int getLCA(int a, int b)
{
	if(h[b]<h[a])
		swap(a,b);
	int d=h[b]-h[a];

	while(d>0)
	{
		int i= log2(d);
		b=LCA[b][i];
		d-=(1<<i);
	}
	if(a==b)return a;
	FORD(i,LOG,0)
		if(LCA[a][i]!= -1 && LCA[a][i]!= LCA[b][i])
			a=LCA[a][i],b=LCA[b][i];
	
	return LCA[a][0];
}

void input()
{
    cin>>n>>q;
    FOR(i,1,n)
        cin>>c[i];
    FOR(i,1,n-1)    
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
int dem[maxn];

void to(int u,int v)
{
    dem[c[u]]++;
    if(u==v)return;
    to(LCA[u][0],v);
}

void lds_go_goooo()
{
    init();
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int cha=getLCA(u,v);
     //  cout<<u<<' '<<v<<' '<<cha<<endl;
        mset(dem,0);
        to(u,cha);
       to(v,cha);
        dem[c[cha]]--;
        bool flag=0;
        //cout<<dem[1]<<' '<<cha<<' ';
        FOR(i,0,n)
            if(dem[i]>(h[u]+h[v]-2*h[cha]+1)/2)
            {
                cout<<i;
                flag=1;
                break;
            }
        if(flag==0)
            cout<<-1;
        cout<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "rbtree"
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
