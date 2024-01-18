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
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f;

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

#define int ll
struct Seg{
	vector <int> tree;
    Seg(int n)
    {
    	 tree.assign(4*n+1,inf);
	}
	
	void update(ll id, ll l,ll r,ll pos,ll val)
	{
		if(l>pos||r<pos)	return;
		if(l==r)
		{
			tree[id]=val;
			return;
		}
		ll mid=(l+r)/2;
		update(2*id,l,mid,pos,val);
		update(2*id+1,mid+1,r,pos,val);
		tree[id]=min(tree[id*2],tree[id*2+1]);
	}
	
	ll get(ll id,ll l,ll r,ll u,ll v)
	{
		if(u>r)	return inf;
		if(l>v||r<u)	return inf;
		if(l>=u&&r<=v)	return tree[id];
		ll mid=(l+r)/2;
		return min(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
	}
};

void lds_go_goooo()
{
	int n,m;
	cin>>n>>m;
	int a[n+2][m+2];
	
	FOR(i,1,n)
		FOR(j,1,m)
			cin>>a[i][j];
	
	int dp[n+2][m+2];
	mset(dp,0x3f3f3f);
	vector<Seg> row(n+1,Seg(m+1)),col(m+1,Seg(n+1));
	dp[n][m]=1;
	
	col[m].update(1,1,n,n,1);
	row[n].update(1,1,m,m,1);
	FORD(i,n,1)
		FORD(j,m,1){
			if(a[i][j]==0)continue;
		//	if(i!=n)
			dp[i][j]=min(dp[i][j],min(col[j].get(1,1,n,i+1,min(n,i+a[i][j])),row[i].get(1,1,m,j+1,min(m,j+a[i][j])))+1);
		//	if(j!=m)
			if(dp[i][j]==inf)	continue;
			col[j].update(1,1,n,i,dp[i][j]);
			row[i].update(1,1,m,j,dp[i][j]);
		}
//	FOR(i,1,n)
//		FOR(j,1,m)
//			cout<<dp[i][j]<<" \n"[j==m];
	cout<<(dp[1][1]==inf?-1:dp[1][1]);
}
 

signed main()
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
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}
