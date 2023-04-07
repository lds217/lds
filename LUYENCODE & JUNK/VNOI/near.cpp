#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <utility>
using namespace std;

const int N = 1e5 + 5;
const long double eps = 1e-9;
int n;
pair<long double, int> v[N];

bool cmp(pair<long double, int> x, pair<long double, int> y) {
    return x.first < y.first;
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y; cin >> x >> y;
        v[i] = pair<long double, int>(atan2(y, x), i);
        cout<<atan2(y, x)<<endl;
    }
    cout<<endl;
    sort(v + 1, v + n + 1, cmp);

    for(int x=1;x<= n; x++)
        cout<<v[x].first<<endl;


    return 0;
}