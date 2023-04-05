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
#define task "chiahet"
 
using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e2+2;
const ll mod=26051968;
const ll inf=1e18;
const int primes[46] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
 
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
        // Main Function //
string a,b;
ll arr[2000];
ll dp[21][3][2000];
 
bool isPrime(int x) {
    for (int i = 0; i < 46; i++)
        if (primes[i] == x)
            return true;
    return false;
}
 
ll dpdigit(string str)
{
    ll n=str.size();
    dp[n][1][0]=1;
    dp[n][0][0]=1;
    FORD(i,n-1,0)
        FOR(limit,0,1)
            FOR(sum,0,200)
                if(limit)
                {
                    FOR(d,0,str[i]-'0')
                        if(d==str[i]-'0')
                            dp[i][1][sum]+=dp[i+1][1][sum-d];
                        else
                            dp[i][1][sum]+=dp[i+1][0][sum-d];
                }
                else
                    FOR(d,0,9)
                        dp[i][0][sum]+=dp[i+1][0][sum-d];
 ll cnt=0;
 FOR(i,0,200)
    if(isPrime(i))
        cnt+=dp[0][1][i];
 
    return cnt;
}
 
ll solve(string str)
{
    mset(dp,0);
    return dpdigit(str);
 
}
 
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<solve(b)-solve(to_string(stoi(a)-1))<<endl;
    }
}