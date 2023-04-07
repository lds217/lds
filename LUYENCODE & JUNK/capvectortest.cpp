#include<cstdio>
#include<map>
#include <iostream>
using namespace std;

typedef pair<int, int> ii;
#define TR(v,i) for(typeof((v).begin()) i=(v).begin();i!=(v).end();++i)
int x[33], y[33], n, a, b, u, v;
map<ii, int> m1, m2;

void backtrack(map<ii, int> &m, int begin, int end) {
    if(begin == end) ++m[ii(a, b)];
    else {
        for(int mul = 0; mul < 2; ++mul) {
            a += mul * x[begin]; b += mul * y[begin];
            backtrack(m, begin + 1, end);
            a -= mul * x[begin]; b -= mul * y[begin];
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d%d", x+i, y+i);
    scanf("%d%d", &u, &v);
    backtrack(m1, 0, n/2);
    backtrack(m2, n/2, n);
    long long res = 0;
    TR(m1, it) {
       cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
    }
    TR(m2, it) {
       cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
    }
    printf("%lld\n", res);
    return 0;
}