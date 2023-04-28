#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i = k; i <= n; i++)
#define FORR(i,k,n) for(int i = n; i >= k; i--)
#define pb push_back
#define all(x) begin(x),end(x)
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;

ll n;

ll ssdg(string n){
    int sum = 0;
    FOR(i,0,n.size()-1){
        sum += (n[i] - '0')*(n[i] - '0');
    }
    return sum;
}

bool sol(ll n){
    unordered_map<ll,int> f;
    while (ssdg(to_string(n)) != 1){
        n = ssdg(to_string(n)); if (f[n]) return 0; f[n]++;
    }
    return 1;
}

int main(){
	freopen("6.inp", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cin >> n; n++; while (!sol(n)) n++; cout << n;
}