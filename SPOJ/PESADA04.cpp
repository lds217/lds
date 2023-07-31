#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i = k; i <= n; i++)
#define FORR(i,k,n) for(int i = n; i >= k; i--)
#define pb push_back
#define all(x) begin(x),end(x)
#define fi first
#define se second
#define BIT(S, i) (((S)>>(i))&1)
#define MASK(i) ((1ll)<<(i))
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

template<class T> 
    bool maximize(T &a, T b) {
    if (a < b) {a = b; return true;}
    return false;
}

template<class T>
    bool minimize(T &a, T b) {
    if (a > b) {a = b; return true;}
    return false;
}

const int N = 20; const ll INF = 1e18;
ll dp[MASK(N)+1][N+1], n, m, x, y, a[N+1][N+1], ans = INF; 

void solve(){
    FOR(i,0,MASK(20)-1) FOR(j,1,20) dp[i][j] = INF;
    
    FOR(i,2,n) 
		if (a[1][i])
	 		dp[MASK(i-1)][i] = a[1][i];
	 		
    FOR(S,0,MASK(n)-1)
        FOR(i,1,n) if (BIT(S,i-1))
            FOR(j,1,n) if (!BIT(S,j-1) && a[i][j])
                minimize(dp[S | MASK(j-1)][j], dp[S][i] + a[i][j]);
    FOR(i,2,n) if (a[i][1]) minimize(ans, dp[MASK(n) - MASK(0) - 1][i] + a[i][1]);
    cout << (ans == INF ? -1 : ans)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin>>n>>m;
    while(m--)
    {
    	cin>>x>>y>>a[x][y];
    
	}
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    		cout<<a[i][j]<<' ';
    	cout<<endl;
	}
    	solve();
}