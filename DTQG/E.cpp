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
#define lc rc md

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
const ll maxn = 3e5 + 100;
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
#define int ll
struct CHT
{
    typedef pair < ll , ll > Line;
    vector < pair < ll , pair < Line , ll > > > A;
    ll INF = (ll)2e18;
    inline void Add(Line X, ll id)
    {
        while (A.size() && Intersection(A.back().second.first, X) <= A.back().first)
            A.pop_back();
        if (A.size())
            A.push_back({Intersection(A.back().second.first, X), {X, id}});
        else
            A.push_back({-INF, {X, id}});
    }
    inline pair < ll , ll > GetMax(ll X)
    {
        int lb = upper_bound(A.begin(), A.end(), pair < ll , pair < Line , ll > > {X, {{INF, INF}, -1}}) - A.begin() - 1;
        return make_pair(A[lb].second.first.first * X + A[lb].second.first.second, A[lb].second.second);
    }
    inline ll Intersection(Line X, Line Y)
    {
        if (X.first == Y.first && X.second <= Y.second)
            return (-INF);
        if (X.first == Y.first)
            return (INF);
        return ((X.second - Y.second) / (Y.first - X.first)) + ((X.second - Y.second) % (Y.first - X.first) > 0);
    }
};

CHT C[4*maxn];
int n,q;
ii a[maxn];
vector <int> V[4*maxn];
void build(int id=1,int l=1, int r=n)
{
    if (r -l<2 )
        V[id].push_back(l);
    else
    {
        int mid=(l+r)/2;
        build(2*id, l, mid);
        build(2*id+1, mid, r);
        V[id] = V[2*id];
        for (int i : V[2*id+1])
            V[id].push_back(i);
        V[2*id].clear();
        V[2*id+1].clear();
        sort(V[id].begin(), V[id].end(), [](int i,int j){
            return make_pair(a[i].se,a[i].fi)<make_pair(a[j].se,a[j].fi);
        });
    }
    for (int i : V[id])
        C[id].Add({a[i].se, a[i].fi}, i);
}


pair < ll , int > Get(int le, int ri, int t, int id = 1, int l = 1, int r = n )
{
    if (ri <= l || r <= le)
        return (make_pair(-1, 0));
    if (le <= l && r <= ri)
        return (C[id].GetMax(t));
    int mid=(l+r)/2;
    return (max(Get(le, ri, t, 2*id, l, mid), Get(le, ri, t, 2*id+1, mid, r)));
}

void input()
{
    cin >> n >> q;
    FOR(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        a[i]={u,v};
    }
}

void lds_go_goooo()
{
    build();
    while(q--)
    {
        int u,v,t;
        cin>>u>>v>>t;
        cout<<Get(u,v,t+1).second<<endl;
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

/*

// ItnoE
#include<bits/stdc++.h>
#define lc (id << 1)
#define rc (lc ^ 1)
#define md (l + r >> 1)
using namespace std;
typedef long long ll;
struct CHT
{
    typedef pair < ll , ll > Line;
    vector < pair < ll , pair < Line , ll > > > A;
    ll INF = (ll)2e18;
    inline void Add(Line X, ll id)
    {
        while (A.size() && Intersection(A.back().second.first, X) <= A.back().first)
            A.pop_back();
        if (A.size())
            A.push_back({Intersection(A.back().second.first, X), {X, id}});
        else
            A.push_back({-INF, {X, id}});
    }
    inline pair < ll , ll > GetMax(ll X)
    {
        int lb = upper_bound(A.begin(), A.end(), pair < ll , pair < Line , ll > > {X, {{INF, INF}, -1}}) - A.begin() - 1;
        return make_pair(A[lb].second.first.first * X + A[lb].second.first.second, A[lb].second.second);
    }
    inline ll Intersection(Line X, Line Y)
    {
        if (X.first == Y.first && X.second <= Y.second)
            return (-INF);
        if (X.first == Y.first)
            return (INF);
        return ((X.second - Y.second) / (Y.first - X.first)) + ((X.second - Y.second) % (Y.first - X.first) > 0);
    }
};
const int N = 100005;
int n, q, A[N], B[N];
vector < int > V[N * 4];
CHT C[N * 4];
inline bool CMP(int i, int j)
{
    return (make_pair(B[i], A[i]) < make_pair(B[j], A[j]));
}
void Build(int id = 1, int l = 1, int r = n + 1)
{
    if (r - l < 2)
        V[id].push_back(l);
    else
    {
        Build(lc, l, md);
        Build(rc, md, r);
        V[id] = V[lc];
        for (int i : V[rc])
            V[id].push_back(i);
        V[lc].clear();
        V[rc].clear();
        sort(V[id].begin(), V[id].end(), CMP);
    }
    for (int i : V[id])
        C[id].Add({B[i], A[i]}, i);
}
pair < ll , int > Get(int le, int ri, int t, int id = 1, int l = 1, int r = n + 1)
{
    if (ri <= l || r <= le)
        return (make_pair(-1, 0));
    if (le <= l && r <= ri)
        return (C[id].GetMax(t));
    return (max(Get(le, ri, t, lc, l, md), Get(le, ri, t, rc, md, r)));
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i ++)
        scanf("%d%d", &A[i], &B[i]);
    Build();
    for (; q; q --)
    {
        int l, r, t;
        scanf("%d%d%d", &l, &r, &t);
        printf("%d\n", Get(l, r + 1, t).second);
    }
    return 0;
}



*/