#include <iostream>
#include <cmath>
#include <algorithm>
typedef long long ll;
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)

long long dp[101][100005];
long long a[100005];
long long pre[100005];
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    FOR(i,1,n)  cin>>a[i];
    long long cnt=0;
    
    FOR(i,1,min(k,a[1]))
    	if(k-i<=a[2])
    		cnt++;
    		
    cout<<cnt;
}
