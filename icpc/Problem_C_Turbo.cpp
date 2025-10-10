#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-tree-vectorize")
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

vector<int> st;

void update(int id, int l, int r, int u, int val) {
    if (u < l || r < u) {
        return ;
    }
    if (l == r) {
        st[id] = val;
        return ;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid, u, val);
    update(id*2 + 1, mid+1, r, u, val);

    st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        return st[id];
    }
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v)
        + get(id*2+1, mid+1, r, u, v);
}

void sol(){
  int n;
  cin>>n;
  st.resize(4 * n + 5, 0);
  vector<int> a(n + 1, 0), pos(n + 1, 0);
  FOR(i, 1, n) {
    int x;
    cin >> x;
    pos[x] = i;
    update(1, 1, n, i, 1);
  }
  int left = 1, right = n;
  while(left < right) {
    cout<<get(1, 1, n, 1, pos[left] - 1)<<"\n";
    update(1, 1, n, pos[left], 0);
    left++;
    cout<<get(1, 1, n, pos[right] + 1, n)<<"\n";
    update(1, 1, n, pos[right], 0);
    right--;
  }
  if (left == right)
    cout<<get(1, 1, n, 1, pos[left] - 1)<<"\n";
}

// What are you doing here, Jimmy?
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;  // cin >> t;
    while(t -- ) sol();
    return 0;
}