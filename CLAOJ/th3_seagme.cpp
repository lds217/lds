// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a; i<=b; i++)
#define FORD(i, a, b) for(ll i=a; i>=b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define BIT(i) (1LL<<(i))
#define task "SEAGAME"
#define MASK(i) (1LL<<(i))
#define all(a, n) a+1, a+1+n

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=200+5;
const ll mod=1e9+7;
const ll inf=1e9;
const ll base = 37;
const ld eps = 1e-10;

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
    if (b==1) return a;
    ll tmp=POW(a, b/2) % mod;
    return b%2==0 ? (tmp * tmp)%mod : (((tmp*tmp)%mod)*a)%mod;
}
        // Main Function //
ll n, c[maxn][maxn], fx[maxn], fy[maxn], matchX[maxn];
ll trace[maxn], mindist[maxn], Link[maxn], matchY[maxn];
ll fin[maxn];
queue<ll>q;
int k;
void input()
{
	
    cin>>n>>k;
    FOR(i,1,k)
    	cin>>fin[i];
    FOR(i, 1, n) FOR(j, 1, n){ int u;cin>>u;
    if(u<=5)	c[i][j]=u;
    else	c[i][j]=inf;
	} 

}

ll _get(ll i, ll j)
{
    return c[i][j] - fx[i] - fy[j];
}

ll xoay(ll s)
{
    ll del = inf;
    FOR(j, 1, n) if(trace[j]==0) minimize(del, mindist[j]);
    fx[s]+=del;
    FOR(j, 1, n)
    {
        if (trace[j])
        {
            ll i =matchY[j];
            fx[i] += del;
            fy[j] -= del;
        }
        else mindist[j] -= del;
    }

    FOR(j, 1, n)
    {
        if (trace[j]==0 && mindist[j]==0){
            trace[j] = Link[j];
            if (matchY[j]==0) return j;
            q.push(matchY[j]);
        }
    }
    return -1;
}

ll findpath()
{
    while(!q.empty())
    {
        ll i=q.front();
        q.pop();
        FOR(j, 1, n)
        {
            if (trace[j]) continue;
            ll w = _get(i, j);
            if (w==0){
                trace[j] = i;
                if (matchY[j]==0) return j;
                q.push(matchY[j]);
            }
            if (minimize(mindist[j], w)) Link[j] = i;
        }
    }
    return -1;
}

void prog(ll s)
{
    FOR(j, 1, n)
    {
        trace[j]=0;
        mindist[j]=_get(s, j);
        Link[j]=s;
    }
    q=queue<ll>();
    q.push(s);
    ll t = -1, k;
    while(t==-1)
    {
        t=findpath();
        if (t==-1) t=xoay(s);
    }
    while(t!=0)
    {
        s = trace[t];
        k = matchX[s];
        matchX[s] = t;
        matchY[t] = s;
        t = k;
    }
}

void solve()
{
    FOR(i, 1, n)
    {
        fx[i]=inf;
        FOR(j, 1, n) minimize(fx[i], c[i][j]);
    }
    FOR(j, 1, n)
    {
        fy[j]=inf;
        FOR(i, 1, n) minimize(fy[j], c[i][j]-fx[i]);
    }
    FOR(i, 1, n) prog(i);

    FOR(i, 1, k) cout<<matchX[fin[i]]<<' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
