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
typedef pair<double, double> ii;
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
struct point{
    double x,y,r,m;
};
double dist(ii a,ii b)
{
	return (double)sqrt(pow(a.fi-b.fi,2)+pow(a.se-b.se,2));
}

double dista(point a, ii c ,ii b)
{
    ii s={a.x,a.y};
    double A=dist(s,b);
    double B=dist(s,c);
    double C=dist(b,c);
    double P=(A+B+C)/2;
    double tmp=2*sqrt(P*(P-A)*(P-B)*(P-C))/C;
 //   cout<<A<<' '<<B<<' '<<tmp<<endl;
    if(sqrt(A*A-tmp*tmp)>C)
        return B;
    else
        if(sqrt(B*B-tmp*tmp)>C)
            return A;
        else
            return tmp;
}

int n,m;
double d;
point a[maxn];
ii b[maxn];



void input()
{
    cin>>n>>m>>d;
    FOR(i,1,n)
    {
        double x,y,r,mi;
        cin>>x>>y>>r>>mi;
        a[i]={x,y,r,mi};
    }
    b[1]={0,0};
    FOR(i,2,m+1)
        cin>>b[i].fi>>b[i].se;
    b[m+2]=b[1];
}




//bool taken[maxn];
void lds_go_goooo()
{
   // FOR(i,1,n)
     //   cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].r<<' '<<a[i].m<<endl;
    // cout<<a[1].x<<' '<<a[1].y<<endl;
    // cout<<b[1].fi<<' '<<b[1].se<<endl;
    // cout<<b[2].fi<<' '<<b[2].se<<endl;
    // cout<<dista(a[1],b[1],b[2])<<endl;
   // mset(taken,0);
    ll ans=0;
    FOR(i,1,n)
    {
        FOR(j,1,m+1)
        {
            double l=dista(a[i],b[j],b[j+1]);
            if(l-(d+a[i].r)<=0 )
            {
               // taken[i]=1;
                ans+=a[i].m;
                break;
            }
        }
    }
    cout<<ans;
    //  FOR(i,1,n)
    //      cout<<taken[i]<<' ';
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

