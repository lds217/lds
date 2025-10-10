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
#include <bit>
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


void sol() {
    int n, m;
    cin>>n>>m;
    vector<int> a(n + 1, 0), prelog(n + 1, 0), preB(n + 1, 0), preC(n + 1, 0); 
    FOR(i, 1, n)    
    {
        cin>>a[i];
        prelog[i] += prelog[i - 1];
        preB[i] += preB[i-1];
        preC[i] += preC[i-1];
        if (__builtin_popcount(a[i]) == 1) a[i]+=0;
        else
            if (__builtin_popcount(a[i] - 1) == 1) preB[i]++;
            else preC[i]++;

        prelog[i]+=log2(a[i]);
    }

    while(m--) {
        int l, r;
        cin>> l >> r;
        cout<<prelog[r]-prelog[l-1] +(preB[r] - preB[l-1]) / 2+ preC[r]-preC[l-1]<<endl;
    }
    
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;  cin >> t;
    while(t -- ) sol();
    return 0;
}
