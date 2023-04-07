// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "porder"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e6+5;
const ll mod=1e9+7;
const ll LOG=log2(maxn)+2;
const ll inf=1e18;


bool maximize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A>B ? A=B, true : false;
}

ll POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2) % mod;
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}
        // Main Function //
ll n, a[maxn], bit[maxn];

void input()
{
    mset(bit, 0);
    cin>>n;
    FOR(i, 1, n) cin>>a[i];
}

void update(ll idx, ll val)
{
    while (idx<=n)
    {
        bit[idx]+=val;
        idx+=idx&(-idx);
    }
}

ll _get(ll val)
{
    ll tmp=0, j=0;
    FORD(i, 9, 0)
    {
        if (MASK(i)+j<n && tmp + bit[MASK(i)+j] <= val)
            {
                tmp += bit[MASK(i)+j];
                j+=MASK(i);
                //cout<<j<<'\n';
            }
    }
    return j+1;
}

void solve()
{
    //cout<<1;
    FOR(i, 1, n) update(i, 1);

    ll res[maxn];
    FORD(i, n, 1)
    {
        ll j=_get(a[i]);
        res[i]=n-j+1;
        update(j, -1);
    }
    FOR(i, 1, n) cout<<res[i]<<' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  //  freopen(task".INP", "r", stdin);
   // freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
