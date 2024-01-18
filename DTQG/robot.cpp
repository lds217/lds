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
#define task "SUADUONG"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2 * 1e4 + 2;
const ll mod = 26051968;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

bool maximize(ll &A, ll B)
{
    return A < B ? A = B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A > B ? A = B, true : false;
}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : (tmp * tmp * a) % mod;
}

// main
#define int ll
int n, m;
char a[20][20];

vector<ii> points;
int flag[20][20];
void input()
{
    points.clear();
    mset(flag, -1);
    points.pb({0, 0});
    FOR(i, 1, n)
    FOR(j, 1, m)
    {
        cin >> a[i][j];
        if (a[i][j] == '*')
            points.pb({i, j}), flag[i][j] = points.size() - 1;
        if (a[i][j] == 'o')
            points[0] = {i, j}, flag[i][j] = 0;
    }
}

int dist[20][20];
void bfs(ii st, int id)
{
    int d[20][20];
    mset(d, 0x3f);
    queue<ii> q;
    q.push(st);
    d[st.fi][st.se] = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (flag[x][y] != -1)
            dist[id][flag[x][y]] = dist[flag[x][y]][id] = d[x][y];
        FOR(i, 0, 3)
        {
            int nx = x + moveX[i];
            int ny = y + moveY[i];
            if (a[nx][ny] == 'x' || nx > n || ny > m || nx <= 0 || ny <= 0)
                continue;
            if (minimize(d[nx][ny], d[x][y] + 1))
                q.push({nx, ny});
        }
    }
}
ll ans = inf;

ll dp[MASK(16) + 5][21];

void lds_go_goooo()
{
    // for(auto[u,v]:points)
    //     cout<<u<<' '<<v<<endl;
    mset(dp, 0x3f);

    mset(dist, 0x3f);
    FOR(i, 0, points.size() - 1)
    bfs(points[i], i);
    // cout<<dist[0][1];
    // FOR(i,1,points.size()-1)
    //  dp[MASK(i)][i]=dist[0][i];
    dp[0][0] = 0;
    ans = inf;
    FOR(mask, 0, MASK(points.size()) - 1)
    {
        FOR(i, __builtin_ctz(mask), points.size() - 1)
        if (BIT(mask, i))
        {
            if (__builtin_popcount(mask) == 1)
            {
                dp[mask][i]=dist[0][i];
                break;
            }
            FOR(j, __builtin_ctz(mask), points.size() - 1)
            if (BIT(mask, j))
            {
                minimize(dp[mask][i], dp[mask - MASK(i)][j] + dist[j][i]);
                if (mask == MASK(points.size()) - 1)
                    ans = min(ans, dp[mask][j]);
            }
        }
    }

    cout << (ans>=inf?-1:ans);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen(task".INP", "r", stdin);
    // freopen(task".OUT", "w", stdout);
    ll test_case = 1; // cin>>test_case;
    while (cin >> n)
    {
        cin >> m;
        swap(m, n);
        if (n == 0 && m == 0)
            break;
        input(), lds_go_goooo();
        cout << '\n';
    }
    return 0;
}
