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
const ll maxn = 1e7;
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
#define int ll
int n,d;
long long a[maxn],node[maxn],vals[maxn],dp[maxn];
vector <int> compress;
void input()
{
    
    cin>>n>>d;
    FOR(i,1,n) 
    {
        cin>>a[i];
        compress.pb(a[i]);
        compress.pb(a[i]-d);
        compress.pb(a[i]+d);
    }
    sort(ALL(compress));
    compress.resize(unique(ALL(compress))-compress.begin());
}

int id(int x,int t)
{
    if(t==0)
        return lower_bound(ALL(compress),x)-compress.begin()+1;
    else
        return upper_bound(ALL(compress),x)-compress.begin();
}

void update(int id, int l, int r, int pos, int val)
{
    if(pos<l||pos>r)return;
    if(l==r)
    {
        node[id]=val;
        return ;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    node[id]=node[id*2]+node[id*2+1];
}

long long get(int id, int l, int r, int u, int v)
{
    if (v < l || u > r)
        return 0;
    if (u <= l && v >= r)
        return node[id];
    int mid=(l+r)/2;
    long long sumL=get(id*2,l,mid,u,v);
    long long sumR=get(id*2+1,mid+1,r,u,v);
    return sumL+sumR;
}


ll ans=0;
void lds_go_goooo()
{
    FOR(i,1,n)
    {
        dp[i]=get(1,1,3e5+10,id(a[i]+d,0),3e5+10);
        update(1,1,3e5,id(a[i],0),1);
        // cout<<dp[i]<<' ';
    }  
    mset(node,0);

    FORD(i,n,1)
    {
        dp[i]*=get(1,1,3e5+10,1,id(a[i]-d,1));
        update(1,1,3e5,id(a[i],0),1);
        ans+=dp[i];
    }
    // FOR(i,1,n)
    //     cout<<dp[i]<<' ';
    cout<<ans<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "INVD"
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

