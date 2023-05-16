#include <bits/stdc++.h>
using namespace std;
#define nmax 10001
#define taskname "LOVESONG"


        // Main Function //
int n, m, a[nmax], b[nmax], match[nmax];
bool avail[nmax], found;
void enter() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int j = 1; j <= n; j++) cin >> b[j];
}
void DFSVisit(int x) {
    for (int y = 1; y <= n; y++)
        if (b[y] != a[x] && avail[y]) {
            avail[y] = 0;
            if (!match[y])
                found = true;
            else
                DFSVisit(match[y]);
            if (found) {
                match[y] = x;
                return;
            }
        }
}
void solve() {
    vector<int> X;
    for (int x = 1; x <= m; x++) X.push_back(x);
    while (1) {
        int cnt = X.size();
        int real_size=cnt;
        memset(avail,1,sizeof(avail));
        for (int i = 0; i < X.size();i++) {
            found = 0;
            DFSVisit(X[i]);
            if (found) 
               real_size--;
        }
            if (!real_size || real_size == cnt)
                break;
        }
    int cnt = 0;
    for (int y = 1; y <= n; y++) cnt += (match[y] != 0);

    cout << cnt << '\n';
   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen(taskname".INP", "r", stdin);
    // freopen(taskname".OUT", "w", stdout);
    enter();
    solve();
}