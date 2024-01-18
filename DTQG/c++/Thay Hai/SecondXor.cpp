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

const int NUMBEROFNODES = maxn;
struct Trie{
    struct Node{
        int child[2];
        int exist, cnt;
    } nodes[NUMBEROFNODES];

    int cur; 
    Trie() : cur(0) { 
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };

    int new_node() { 
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }

    void add_string(int s) {
        int pos = 0;
        FORD(i,32,0) {
            int c = BIT(s,i);
            if (nodes[pos].child[c] == -1) {
                nodes[pos].child[c] = new_node();
            }
            pos = nodes[pos].child[c];
            nodes[pos].cnt++; 
        }
        nodes[pos].exist++; 
    }

    bool delete_string_recursive(int pos, int& s, int i) {
        if (i != 0) { 
            int c = BIT(s,i);
            bool isChildDeleted = delete_string_recursive(nodes[pos].child[c], s, i - 1);
            if (isChildDeleted) nodes[pos].child[c] = -1;
        }
        else nodes[pos].exist--; 

        if (pos != 0) {
            nodes[pos].cnt--;
            if (nodes[pos].cnt == 0) return true;
        }
        return false;
    }

    void delete_string(int s) {
        if (find_string(s) == false) return; 
        delete_string_recursive(0, s, 32); 
    }

    bool find_string(int s) {
        int pos = 0;
        for (int i = 32; i >= 0; i--) {
            int c = (s >> i) & 1;
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0); 
    }

    int query(int x) {
        int pos = 0, res = 0;
        for (int i = 32; i >= 0; i--) {
            int c = (x >> i) & 1;

            if (nodes[pos].child[c ^ 1] != -1) {
                res += (1ll << i);
                pos = nodes[pos].child[c ^ 1];
            }
            else {
                pos = nodes[pos].child[c];
            }
        }
        return res;
    }
};
Trie T;
int n;
int a[maxn];
void input()
{
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
}

ll ans=0;

void update2(int &a,int &b,int c)
{
    if(c>a)
        b=a,a=c;
    else
        b=max(c,b);
}

void lds_go_goooo()
{
    if(n<=20000)
    {
        FOR(i,1,n)
        {
            int first=a[i],second=0;
            FOR(j,i+1,n)
            {
                update2(first,second,a[j]);
                ans=max(ans,1LL*(first^second));
            }
        }
        cout<<ans;
    }
    else
    {
        ll ans=0;
        deque <int> dq;
        T.add_string(a[1]);
        dq.push_back(a[1]);
        FOR(i,1,n)
        {
            while(dq.size()>=2&&dq[1]>a[i]) T.delete_string(dq.front()),dq.pop_front();
            ans=max(ans,1LL*T.query(a[i]));
            while(!dq.empty()&&dq.back()<a[i])  T.delete_string(dq.back()),dq.pop_back();
            T.add_string(a[i]);
            dq.push_back(a[i]);
        }
        cout<<ans;
    }

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

