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
#define x first
#define y second
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

const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

pair<double,double> inter(ii a,ii b)
{
    double x=(b.second-a.second)/(a.first-b.first);
    return {x,a.first*x+a.second};
}

int n;
ii a[maxn];
void input()
{
    cin>>n;
    FOR(i,1,n)
    {
        int u,v;
        cin>>u>>v;
     //   u+=15000;
       // v+=15000;
        a[i]={u,v};
    }
}
double dist(ii a,ii b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
 int cnt;

bool cmp(ii c, ii b)
{
     if(c.x==b.x)
            if(a[1].y>a[cnt].y)
                return c.y>b.y;
            else
                return c.y<b.y; 
        return c.x<b.x;
}

bool hasinter[maxn];
void lds_go_goooo()
{

    // FOR(i,1,n)
    //     if(a[i].x==a[i+1].x)
    //         while(1){}
     vector <vector <double> > b(2,vector<double> (3,0));
    b[0][0]=a[1].x;
    b[0][1]=1;
    b[0][2]=a[1].y;
    b[1][0]=a[n].x;
    b[1][1]=1;
    b[1][2]=a[n].y;
    vector<double> ans;
    gauss(b,ans);
    double A=ans[0];
    double B=ans[1];
    vector<ii> intersect;
   cnt=n;
   intersect.pb({a[1].x,a[1].y});
    FOR(i,3,n-1)
    {
        ans.clear();
        b[0][0]=a[i-1].x;
        b[0][2]=a[i-1].y;
        b[1][0]=a[i].x;
        b[1][2]=a[i].y;
        gauss(b,ans);
        double A1=ans[0];
        double B1=ans[1];
        if(A1==A)   continue;
        pair<double,double> tmp=inter({A,B},{A1,B1});
        if(a[i].x==a[i-1].x)
            tmp={a[i].x,A*a[i].x+B};
        
        if(a[i].y==a[i-1].y)
            tmp={(a[i].y-B)/A,a[i].y};

        
        if(tmp.x>=min(a[i-1].x,a[i].x)&&tmp.x<=max(a[i].x,a[i-1].x)&&tmp.y>=min(a[i-1].y,a[i].y)&&tmp.y<=max(a[i-1].y,a[i].y))
            hasinter[i]=1,intersect.pb({tmp.x,tmp.y});
         cout<<a[i].x<<' '<<a[i].y<<' '<<hasinter[i]<<' '<<A1<<' '<<B1<<endl;
    }
   //cout<<hasinter[n]<<endl;
   hasinter[n]=1;
   // FOR(i,1,cnt)
     //   cout<<a[i].x<<' '<<a[i].y<<endl;
   // cout<<endl;
   
    intersect.pb({a[cnt].x,a[cnt].y});
   for(ii i:intersect)
       cout<<i.x<<' '<<i.y<<endl;
    int j=1;
    double area=0;
    int flag=0;
    double anss[2];
    mset(anss,0);
    FOR(i,1,n)
    {
        if(hasinter[i]&&i!=1)
        {
            area+=(a[i-1].x-intersect[j].x)*(a[i-1].y+intersect[j].y);
            area+=(intersect[j].x-intersect[j-1].x)*(intersect[j].y+intersect[j-1].y);
             cout<<abs(area)/2<<endl;
            anss[flag]+=abs(area)/2;
            hasinter[i]=0;
            area=0;
            area+=(intersect[j].x-a[i].x)*(intersect[j].y+a[i].y);
            j++;
            flag^=1;
        }
    else
        if(!hasinter[i+1])
        area+=(a[i].x-a[i+1].x)*(a[i].y+a[i+1].y);
        

    }
    cout<<setprecision(4)<<fixed<<anss[1]<<"\n"<<anss[0];
}
/*FOR(i,1,m)
	area+=(x[i]-x[i+1])*(y[i]+y[i+1]);
*/

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

