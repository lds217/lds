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
#define int ll
int n,m,p;
void input()
{
    cin>>n>>m>>p;
    
}

void sub1()
{
    vector <int> num,no;
    FOR(i,1,n)
    {
        string str;
        cin>>str;
        ll tmp=0;
        ll pw=p-1;
        FOR(i, 0,p-1)
            tmp+=pow(2,pw--)*(str[i]-'0');
        num.pb(tmp);
    //    cout<<tmp<<endl;
    }
    FOR(i,1,m)
    {
        string str;
        cin>>str;
        ll tmp=0;
        ll pw=p-1;
        FOR(i, 0,p-1)
            tmp+=pow(2,pw--)*(str[i]-'0');
        no.pb(tmp);
     //   cout<<tmp<<endl;;
    } 
    ll ans=inf;
    FOR(mask,0,MASK(p)-1)
    {
        bool flag=0;
        for(int i:no)
            if(mask==i)
            {
                flag=1;
                break;
            }
        if(flag==1)
            continue;
        
        ll cnt=0;
        for(int i:num)
        FOR(j,0,p-1)
            if(BIT(mask,j)!=BIT(i,j))
                cnt++;
        ans=min(ans,cnt);
    }
    cout<<ans;
}

void sub2()
{
    cout<<"hello anh thuan, em ko biet lam";
}

void lds_go_goooo()
{
    if(n<=20&&p<=20)
    {
        sub1();
        return;
    }
    else
        sub2();

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
    ll test_case = 1;  cin>>test_case;
    while (test_case--)
    {
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}

