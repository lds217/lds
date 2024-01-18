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
const ll mod = 1e9+7;
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
int n;
int a[maxn],tmp[maxn];
/*
    a1, a2,....ai|...an
    f(i)= sigma(f(j)) j+1 -> i
    f(0)= 1
    // f(i) += f(j) if gcd từ j+1 đến i > 1
    f(0)=1
*/
int tree[4*maxn];
void build(int id,int l, int r)
{
    if(l==r)
    {
        tree[id]=tmp[l];
        return;
    } 
    int m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    tree[id]=gcd(tree[id*2],tree[id*2+1]);
}

long long get(int id, int l, int r, int u, int v)
{
     if (v < l || u > r)
        return 0;
    if (u <= l && v >= r)
        return tree[id];
    int mid=(l+r)/2;

    return gcd(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

void input()
{
    cin>>n;
    FOR(i,1,n)  cin>>tmp[i];
}

ll dp[maxn],pre[maxn],opt[maxn];

void lds_go_goooo()
{
    ll ans=0;
    build(1,1,n);
    int k=1;
    while(k<=n&&get(1,1,n,1,k)>1) k++;
    int l;
    while(1)
    {
        l=k;
        while(l<=n&&get(1,1,n,k-1,l)>1)l++;
        if(l==k)    break;
        k=l;
    }

    //cout<<k<<' '<<l-1<<endl;
    vector <int> a;
    a.pb(0);
    FOR(i,k,n)  a.pb(tmp[i]);
    FOR(i,1,k-1)  a.pb(tmp[i]);
    mset(tree,0);
    FOR(i,1,n)
        tmp[i]=a[i];
    
    build(1,1,n);
    dp[0]=1;
    //opt[k-1]=k-1;
    
    FOR(i,1,n)
    {
        //  dp[i]=0;
        FORD(j,i-1,0)
        {
            if(get(1,1,n,j+1,i)>1)
            {
                (dp[i]+=dp[j])%=mod;
                //opt[i]=j;
            }
            else
                break;
            //pre[i]+=pre[i-1];
        }
    }

 
    cout<<dp[n];
    
}

signed main()
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
