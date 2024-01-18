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
const ll maxn = 2e6 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}

template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}



// End of template//
string s;
ll dp[maxn],hashT[maxn],POW[maxn],suff[maxn];
const ll MOD=1000000007;
const int base = 37;
ll n;
#define int ll
long long gethashT(long i, long j)
{
	return(hashT[j]-hashT[i-1]*POW[j-i+1]+MOD*MOD)%MOD;
}

void prepare()
{
	POW[0]=1;
	FOR(i,1,n)
	{
		POW[i]=(POW[i-1]*base)%MOD;
		hashT[i]=(hashT[i-1]*base+s[i]-'a'+1)%MOD;
	}
	
}



void input()
{
    cin>>s;
    n=s.size();
    s=' '+s;
    prepare();
    
}


void lds_go_goooo()
{
    FORD(i,n,1)
    {
        int l=i,r=n;
        int res=0;
        while(l<=r)
        {
            
            int m=(l+r)/2;
            if(gethashT(1,m-i+1)==gethashT(i,m))
                l=m+1,res=m;
            else
                r=m-1;
           
        }
         suff[i]=max(res-i+1,suff[i+1]);
    }

    int q;
    cin>>q;
    while(q--)
    {
        int u;
        cin>>u;
        cout<<suff[u]<<endl;
    }
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
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}
/*
 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Le Thanh Dat
  `Y8P'
   `Y'
   
*/
