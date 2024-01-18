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
const ll maxn = 100;
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

int n;
char a[maxn][maxn];
ll row[maxn],col[maxn];
bool ck[maxn];

bool check()
{
    bool mid=0;
    FOR(i,1,n)
    {
        if(col[i]>2||col[i]==0)     return false;
        if(col[i]==1&&mid==1)   return false;
        if(col[i]==1&&mid==0)   mid=1;
    }

    mid=0;
    FOR(i,1,n)
    {
        if(row[i]>2||row[i]==0)     return false;
        if(row[i]==1&&mid==1)   return false;
        if(row[i]==1&&mid==0)   mid=1;
    }

    FOR(i,1,n)  
        FOR(j,1,n)
            if(a[i][j]=='X'&&row[i]!=col[j])   
                return false;
    mset(ck,0); 
    //cout<<"test"<<endl;
    FOR(i,1,n)
    {
        if(ck[i]||row[i]==1) continue;
        vector <int> hihi,hoho;
        FOR(j,1,n)   if(a[i][j]=='X') hihi.pb(j);
        FOR(x,1,n)
        {
            if(x==i)    continue;
            FOR(j,1,n) if(a[x][j]=='X') hoho.pb(j);   
            if(hihi[0]==hoho[0]&&hihi[1]==hoho[1])
            {
                ck[i]=ck[x]=1;
                break;
            }
            hoho.clear();
        }
        if(ck[i]==0) return false;
    }
    return true;

}

// End of template//

void input()
{
    mset(row,0);
    mset(col,0);
    cin>>n;
    FOR(i,1,n)
        FOR(j,1,n)
        {
            cin>>a[i][j];
            if(a[i][j]=='X')
                col[j]++,row[i]++;
        }

    if(check()) 
    {
        cout<<"POSSIBLE";
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
        
}


void lds_go_goooo()
{
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
    int cnt=0;
    ll test_case = 1;  cin>>test_case;
    while (test_case--)
    {
        cout<<"Case #"<< ++cnt<<": ";
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}
