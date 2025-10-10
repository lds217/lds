#include<bits/stdc++.h>
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
void sol(){
  int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        reverse(a.begin(), a.end());
        a.insert(a.end(), a.begin(), a.end());

        vector<int> p(1, 0), q(1, 0);
        for (int i = 0; i < 2 * n - 1; i++) {
            if (a[i] >= a[i + 1])
                p.push_back(p.back() + 1);
            else
                p.push_back(0);

            if (a[i] <= a[i + 1])
                q.push_back(q.back() + 1);
            else
                q.push_back(0);
        }

        int minn = 1000000;
        for (int i = n - 1; i < (int)p.size(); i++) {
            if (p[i] == n - 1) {
                minn = min({minn, i - n + 1, (int)p.size() - i + 1});
            }
            if (q[i] == n - 1) {
                minn = min({minn, (int)p.size() - i, i - n + 2});
            }
        }

        if (minn == 1000000) cout << -1 << "\n";
        else cout << minn << "\n";
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;  cin >> t;
    while(t -- ) sol();
    return 0;
}