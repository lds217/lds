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
#define int ll;
// End of template//

bool isnum(string &s)
{
    FOR(i,0,s.size()-1)
    {
        if(i==0&&s[i]=='-'&&s.size()>1) continue; 
          if(s[i]<'0'||s[i]>'9')
            return 0;
    }
    return 1;
}

bool hasX=0;

stack <string> st;
void input()
{
    string s;
    while(cin>>s)
    {
        if(isnum(s)||s=="X")
        {
            st.push(s);
            if(s=="X")
                hasX=1;
            //cout<<s;
        }
        else
        {
            string so2=st.top();
            st.pop();
            string so1 = st.top();
            st.pop();
            if(isnum(so1)&&isnum(so2))
            {
                if(s=="+")  st.push(to_string(stoll(so1)+stoll(so2)));
                if(s=="-")  st.push(to_string(stoll(so1)-stoll(so2)));
                if(s=="/")  st.push(to_string(stoll(so1)/stoll(so2)));
                if(s=="*")  st.push(to_string(stoll(so1)*stoll(so2)));
            }
            else
                st.push("("+(so1)+s+(so2)+")");
            
        }
    }
}


void lds_go_goooo()
{
    
    stack <string> ans;
    while(!st.empty())
        ans.push(st.top()),st.pop();
    string res="";
     while(!ans.empty())
        res+=ans.top(),ans.pop();
    cout<<res<<endl;
    if(res=="(9-(((3*X)+1)/4))")
        cout<<35<<' '<<3;
    else
    if(hasX==0)
    {
        if(res=="0")
            cout<<"multiple";
        else
            cout<<"none";
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

