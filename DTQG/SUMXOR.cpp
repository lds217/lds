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

template <class T>
bool minimize(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool maximize(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//
int n, m;
int a[21][maxn];

struct Node
{
    int lazy, val;
} Tree[21][maxn * 4];
void input()
{
    cin >> n;
    FOR(i, 1, n)
    {
        int u;
        cin >> u;
        FOR(j, 0, 20)
        a[j][i] = BIT(u, j);
    }
   /* FOR(i, 0, 5)
    FOR(j, 1, n)
    cout << a[i][j] << " \n"[j == n];*/

    cin >> m;
}

void build(int row, int id, int l, int r)
{
    if (l == r)
    {
        Tree[row][id].val = a[row][l];
        return;
    }
    int mid = (l + r) / 2;
    build(row, 2 * id, l, mid);
    build(row, 2 * id + 1, mid + 1, r);
    Tree[row][id].val = Tree[row][id * 2].val + Tree[row][id * 2 + 1].val;
}

void down(int id, int row, int l, int r)
{
    int &t = Tree[row][id].lazy;
    int mid = (l + r) / 2;
    if (t % 2)
    {
        Tree[row][2 * id].val = (mid - l + 1) - Tree[row][2 * id].val;
        Tree[row][2 * id].lazy ^= 1;
    }
    if (t % 2)
    {
        Tree[row][2 * id + 1].val = (r - (mid + 1) + 1) - Tree[row][2 * id + 1].val;
        Tree[row][2 * id + 1].lazy ^= 1;
    }
    t = 0;
}

void update(int id, int l, int r, int u, int v, int val, int row)
{
    if (r < u || l > v)
        return;
    if (r <= v && l >= u)
    {
        Tree[row][id].val = (r - l + 1) - Tree[row][id].val;
        Tree[row][id].lazy^=1;

        return;
    }

    down(id, row, l, r);
    int mid = (l + r) / 2;
    update(2 * id, l, mid, u, v, val, row);
    update(2 * id + 1, mid + 1, r, u, v, val, row);
    Tree[row][id].val = Tree[row][id * 2].val + Tree[row][id * 2 + 1].val;
}

int get(int id, int l, int r, int u, int v, int row)
{
    if (r < u || l > v)
        return 0;
    if (r <= v && l >= u)
        return Tree[row][id].val;
    down(id, row, l, r);
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v, row) + get(id * 2 + 1, mid + 1, r, u, v, row);
}

void lds_go_goooo()
{
    FOR(i, 0, 20)
    build(i, 1, 1, n);
    // cout<<get(1,1,n,2,4)<<endl;
    while (m--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            ll ans = 0;
            FOR(i, 0, 20)
            ans += get(1, 1, n, l, r, i) * pow(2, i);
            cout << ans << endl;
        }
        else
        {
            int x;
            cin >> x;
            ll ans = 0;
            FOR(i, 0, 20)
                if(BIT(x,i))
                    update(1, 1, n, l, r, x, i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#define task "SUMXOR"
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