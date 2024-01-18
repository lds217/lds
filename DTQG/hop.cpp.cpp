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

const int INF = 1e9+7, N = 5e5+1;
int n, k, ans, r, h[N], a[N];

bool check(int t){
    FOR(i,1,n) a[i] = a[i-1] + (t > h[i] ? -1 : 1);
    int cnt = 0;
    FOR(i,1,n-r+1) cnt += (a[i+r-1] >= a[i-1]);
    return cnt >= k;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cin >> n >> r >> k;
    FOR(i,1,n) cin >> h[i];
    int l = -INF, r = INF;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = mid; else r = mid - 1;
    }
    cout << ans;
}
