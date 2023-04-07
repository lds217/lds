#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#define ull unsigned long long
#define ll long long
using namespace std;
int main(int argc, char** argv)
{
ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll> > a;
    a.push_back({0,0});
    ll ans = -1;
    for (int i = 0; i<n; i++){
        ll v,w;
        cin >> w >> v;
        vector<pair<ll,ll>> b;
        for (int j = 0; j<a.size(); j++){
            pair<ll,ll> x = a[j];
            if (x.first + w <= m){
                b.push_back({x.first + w, x.second + v});
                ans = max(ans,x.second+v);
            }
            //cout << j << " ";
        }
        for (int j = 0; j<b.size(); j++)
            a.push_back(b[j]);
        b.clear();
    }
    cout << ans << endl;
    cout << a.size();
}