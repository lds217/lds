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
#define task "rbtree"

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
string str;
ll dp[maxn][5][2];
int cnt=1;
vector <int> adj[maxn];

void build(int curr,int type)
{
    FOR(i,1,type)
    {
        char c;
        cin>>c;
        adj[curr].pb(++cnt);
        build(cnt,c-'0');
    }
}

void input()
{
    char c;
    cin>>c;
    FOR(i,1,c-'0')
    {   
        // starting with 2 ??? im too lazy 
        char tmp;
        cin>>tmp;
        cnt++;
        adj[1].pb(cnt);
        build(cnt,tmp-'0') ;
    }
}

void dfs(int i)
{
    dp[i][0][0]=dp[i][0][1]=1;
    for(int j: adj[i])  dfs(j);
    if(adj[i].size()==2)
    {
        int l=adj[i][0],r=adj[i][1];
        dp[i][0][1]+=max(dp[l][1][1]+dp[r][2][1],dp[l][2][1]+dp[r][1][1]);
        dp[i][1][1]+=max(dp[l][0][1]+dp[r][2][1],dp[l][2][1]+dp[r][0][1]);
        dp[i][2][1]+=max(dp[l][1][1]+dp[r][0][1],dp[l][0][1]+dp[r][1][1]);
        dp[i][1][0]+=min(dp[l][0][0]+dp[r][2][0],dp[l][2][0]+dp[r][0][0]);
        dp[i][2][0]+=min(dp[l][1][0]+dp[r][0][0],dp[l][0][0]+dp[r][1][0]);
        dp[i][0][0]+=min(dp[l][1][0]+dp[r][2][0],dp[l][2][0]+dp[r][1][0]);
    }
    if(adj[i].size()==1)
    {
        int l=adj[i][0];
        dp[i][0][1]+=max(dp[l][1][1],dp[l][2][1]);
        dp[i][1][1]+=max(dp[l][0][1],dp[l][2][1]);
        dp[i][2][1]+=max(dp[l][0][1],dp[l][1][1]);
        dp[i][0][0]+=min(dp[l][1][0],dp[l][2][0]);
        dp[i][1][0]+=min(dp[l][0][0],dp[l][2][0]);
        dp[i][2][0]+=min(dp[l][0][0],dp[l][1][0]);
    }

}

void lds_go_goooo()
{
    dfs(1);
    cout<<max({dp[1][0][1],dp[1][1][1],dp[1][2][1]})<<' '<<min({dp[1][0][0],dp[1][1][0],dp[1][2][0]});

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
