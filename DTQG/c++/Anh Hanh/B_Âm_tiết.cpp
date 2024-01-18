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
string s;
char vowels[]={'a','e','i','o','u'};
string dvowel[]={"oo","oa","au","iou"};
void input()
{
    cin>>s;
}


void lds_go_goooo()
{
    // case1
    int numofvowels=0;
    FOR(i,0,s.size()-1)
        for(char j: vowels)
            if(s[i]==j) numofvowels++;

    FOR(i,1,s.size()-1)
    {
        string tmp1="";
        string tmp2="";
        //if(i==1)
        //cout<<s[i-1]<<endl;
            tmp1+=s[i-1];
            tmp1+=s[i];
       //cout<<tmp1<<endl;
       // else
       if(i>=2)
       {
            tmp2+=s[i-2];
            tmp2+=s[i-1];
            tmp2+=s[i];
       }
        for(string j:dvowel)
            if(tmp1==j)
                numofvowels--;
            else
                if(tmp2==j)
                    numofvowels--;   
    }
    if(s[s.size()-1]=='e')  numofvowels--;
    string tmp;
    tmp+=s[s.size()-2];tmp+=s[s.size()-1];
    bool flag=1;
    for(char j:vowels)
        if(s[s.size()-3]==j)
            flag=0;
    if(tmp=="le"&&flag)
        numofvowels++;
    if(numofvowels<=1)
        cout<<1;
    else
        cout<<numofvowels;

    
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
/*
 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Le Thanh Dat
  `Y8P'
   `Y'
   
*/
