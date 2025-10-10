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
using namespace std;

#define           task      "a"
#define           ll        long long
#define           FORE(i, v)  for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define           ed        << "\n";
#define           el        cout<<'\n';
#define           ALL(s)      s.begin(),s.end()
#define           fi        first
#define           se        second
#define           SQ(a)       (a)*(a)
#define           A(a)        abs(a)
#define           SZ(a)       ((int)(a.size()))
#define           REP(i,a,b)    for (int i = (a), _b = (b); i < _b; i++)
#define           FOR(i,a,b)    for (int i = (a), _b = (b); i <= _b; i++)
#define           FOD(i,r,l)    for(int i=r; i>=l; i--)
#define           MASK(x)     (1LL << (x))
#define           BIT(x, i)   ((x) & (1ULL << (i)))
#define           pii         pair<int,int>
#define           pll         pair<ll,ll>
#define           db          double
#define           II(a, b)    make_pair((a),(b))
#define           pb(x)       push_back(x)
#define           ull unsigned long long

#define int long long

// 4 4 4 4 
// 2 2 2 2 alice
// 1 1 1 1 bob
//  alice lose

// 1 1 1
// alice canot do anytihng -> bob win 0

// 1 1 2
// 1 1 1 alice
// bob lose -> alice win 1


// 2 2 2 2-2 %2
// 1 1 2 alice
// 1 1 1 bob
// alice cannot do anythin, bob wins 0

// 4 4 4 4 8 - 8 % 2
// 2 2 4 4 alice
// 2 2 2 2 bob
// 1 1 1 1 alice
// bob cannot do anythinh -> alice wins 1

// 1 1 3
// 1 1 2 alice
// 1 1 1 bob
// 
// 3 3
// 1 2
//

// y 1 2 + x
// x 1 2
// 1 1 1 will lose


// 1 1 1 3 4
// x x

// try to make it 1, each operation we can remove anything but 1
// 4 4 4 4 
// 1 1 3 3 alice
// 1 1 1 3 bob
// 1 1 1 1 alice
// bob lose

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    int cnt = 0, odd = 0;
    int m = 0;
    FOR(i, 1, n) {
        cin >> a[i];
        m += a[i] - 1;
        if (a[i] == 1) cnt++;
        if (a[i] % 2) odd++;
    }
    if (cnt > 0) {
        if (m % 2)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    } else {
        if (m % 2) {
            if (odd > 0) cout << 1 << endl;
            else    cout << 0 << endl;
        } else {
        
            if (odd != n) {
                cout << 1 << endl;
            } else {
                if (n >= 4) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
            }
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;  cin >> t;
    while(t -- ) sol();
    return 0;
}
