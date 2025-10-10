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
// 110010
// 101010
// 110010 at most (r - l + 1) /3
// 101010 worst case 2 + 1 = 6/3 = 2 + 1 (r - l + 1) /3 + 1
// 1 1 0 0 1 0 
// 0 1 0 1 0 0
void sol(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n + 1, -1);
    FOR(i, 1, n)    cin>>a[i];
    vector<int> preone (n + 1, 0), same(n + 1,0 );
    FOR(i, 1, n)
    {
        preone[i] = preone[i-1] + (a[i]==1?1:0);
        same[i] = same[i-1]+ (a[i] == a[i-1]? 1 : 0);
    }
    while (m--) {
        int l, r;
        cin>>l>>r;
        int cntone = preone[r] - preone[l-1];
        int cntzero = r - l + 1 -cntone;
        
        if (cntone % 3 || cntzero % 3) {
            cout<<-1<<endl;
            continue;
        }
        bool flag = same[r] - same[l];
        if (r > l && a[l] == a[l + 1]) flag=1;
        if(flag)     cout<<(r - l +1)/3 <<endl;
        else
        cout<<(r - l +1)/3 + 1<<endl;
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;  cin >> t;
    while(t -- ) sol();
    return 0;
}
