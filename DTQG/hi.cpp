#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
#include <climits>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define RESET(a, v) memset((a), (v), sizeof((a)))
#define SZ(a) (int((a).size()))
#define ALL(a) (a).begin(), (a).end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>

const int oo = 1e9;
const int N = 100005;
using namespace std;

int MAX[N], MIN[N], val[N], a[N];
int n, k, d;

void maxi(int &a, int b) {a = a > b ? a : b;}
void mini(int &a, int b) {a = a > b ? b : a;}

void upd(bool t, int i, int v) {
    for(i++; i; i -= i & -i)
    if (t) maxi(MAX[i], v); else mini(MIN[i], v);
}

int get(bool t, int i) {
    int ret;
    if (t) {
        ret = -oo;
        for(i++; i <= d + 1; i += i & -i)
            maxi(ret, MAX[i]);
    }
    else {
        ret = oo;
        for(i++; i <= d + 1; i += i & -i)
            mini(ret, MIN[i]);
    }
    return ret;
}

bool ok(int lim) {
    REP(i, 1, d + 1) MIN[i] = oo, MAX[i] = -oo;
    int f0, f1;
    upd(0, a[0], 0); upd(1, a[0], 0);
    REP(i, 1, n) {
        int tmp = lower_bound(val + 1, val + 1 + d, val[a[i]] - lim) - val;
        f0 = get(0, tmp) + 1; f1 = get(1, tmp) + 1;
        upd(0, a[i], f0); upd(1, a[i], f1);
    }
    return f0 <= k && k <= f1;
}

II b[N];
int main() {
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int mi = oo;
    REP(i, 1, n) {
        cin >> a[i];
        a[i] += a[i - 1];
        b[i] = MP(a[i], i);
    }
    sort(b, b + 1 + n);
    
    d = 0;
    REP(i, 0, n) {
        if (i == 0 || b[i].X != b[i - 1].X) d++;
        val[d] = a[b[i].Y]; a[b[i].Y] = d;
    }
    REP(i,1,d)
        cout<<val[i]<<" \n"[i==d];
     REP(i,1,n+1)
        cout<<val[i]<<" \n"[i==n];
    int l = -oo, r = oo, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            ans = mid; r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}
