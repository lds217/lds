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
int cnt[3][3];
string s1,s2;
void input()
{
    cin>>s1>>s2;
}


void lds_go_goooo()
{
    ll ans=0;
    mset(cnt,0);
    FOR(i,0,s1.size()-1)
    {
        if(s1[i]!='?')
            cnt[1][s1[i]-'0']++;
        cnt[2][s2[i]-'0']++;
    }
    FOR(i,0,s1.size()-1)
    {
        if(cnt[1][1] >cnt[2][1])
        {
            return cout<<-1,void();
        }
        if(s1[i]=='?')
        {
            if(s2[i]=='1')
            {
                if(cnt[1][1]>=cnt[2][1])
                {
                    s1[i]='0';
                    cnt[1][0]++;
                    ans++;
                }
                else
                {
                    s1[i]='1';
                    cnt[1][1]++;
                    ans++;
                }
            }
            else
            {
                if(cnt[1][0]>=cnt[2][0])
                {
                    s1[i]='1';
                    cnt[1][1]++;
                    ans++;
                }
                else
                {
                    s1[i]='0';
                    cnt[1][0]++;
                    ans++;
                }
            }
        }
       // cout<<s1<<endl;
    }
    //cout<<ans;
    FOR(i,0,s1.size()-1)
    {
        if(cnt[1][0]==cnt[2][0]&&cnt[1][1]==cnt[2][1])
            break;
        if(s1[i]=='0'&&s2[i]=='1')
            s1[i]='1',cnt[1][0]--,cnt[1][1]++,ans++;
    }
    //cout<<ans<<endl;
    ll tmp=0;
    FOR(i,0,s1.size()-1)
        if(s1[i]!=s2[i])    
            tmp++;

    cout<<ans+tmp/2;
    
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
    ll test_case = 1;  cin>>test_case;
    FOR(i,1,test_case)
    {
        input();
       // cout<<"Case "<<i<<": ";
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
