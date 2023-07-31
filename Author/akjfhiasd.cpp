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
#define task "banhkhuc"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e4+2;
const ll mod=26051968;
const ll inf=1e18;

const int moveX[]={0,0,1,-1};
const int moveY[]={-1,1,0,0};

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
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}

//main
#define INF INT_MAX
	int V;
int shortestPath(int graph[501][501], int u, int v, int k)
{
  
    int sp[V][V][k+1];
 

    for (int e = 0; e <= k; e++)
    {
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {

                sp[i][j][e] = INF;
 
                if (e == 0 && i == j)
                    sp[i][j][e] = 0;
                if (e == 1 && graph[i][j] != INF)
                    sp[i][j][e] = graph[i][j];
 
                if (e > 1)
                {
                    for (int a = 0; a < V; a++)
                    {
                        if (graph[i][a] != INF && i != a &&
                            j!= a && sp[a][j][e-1] != INF)
                          sp[i][j][e] = min(sp[i][j][e], graph[i][a] +
                                                       sp[a][j][e-1]);
                    }
                }
           }
        }
    }
    return sp[u][v][k];
}

void input()
{

}
void lds_go_goooo()
{
	int k;

	cin>>V>>k;
	k++;
	 int graph[501][501];
	 FOR(i,0,V-1)
	 	FOR(j,0,V-1)
	 		cin>>graph[i][j];
    cout << shortestPath(graph, 0, 0, k);
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
