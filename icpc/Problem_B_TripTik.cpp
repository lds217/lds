#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-tree-vectorize")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O")
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
#define           mp(a, b)  make_pair(a, b)
#define           int long long

struct Node {
  //{value, position}
  vector<pair<int, int>> top; 
};

int n, k;

const int inf = 1e18;
vector<int> a(100005, 0);


vector<Node> tree(100005 * 4 + 2);
vector<pair<int, int>> mergeTop(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b, int k) {
    vector<pair<int, int>> merged;
    merged.reserve(a.size() + b.size());
    auto comparator = [](const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second < p2.second;
};
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(merged), comparator);
    if (merged.size() > k) merged.resize(k);
    return merged;
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        tree[id].top = {{val, pos}}; 
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id * 2, l, mid, pos, val);
    else update(id * 2 + 1, mid + 1, r, pos, val);
    tree[id].top = mergeTop(tree[id * 2].top, tree[id * 2 + 1].top, k);
}

// return the positions of kth largest elemnt
vector<pair<int, int>> query(int id, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return {};
    if (ql <= l && r <= qr) return tree[id].top;
    int mid = (l + r) / 2;
    auto left = query(id*2, l, mid, ql, qr);
    auto right = query(id*2+1, mid+1, r, ql, qr);
    return mergeTop(left, right, k);
}


void sol(){
  vector<pair<int,int>> cord;
  cin>>n>>k;
  FOR(i, 1, n) {
    cin>>a[i];
    cord.push_back({a[i], i});
  }
  cord.push_back({-inf, 0});
  cord.push_back({inf, 0});
  cord.push_back({0, 0});
  //compress cordinates
  sort(ALL(cord), [&](pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
  });
 //cout<<"compressed"<<endl;
  // add compressed cordinate to the segment tree
  vector<int> ans(n + 1, inf);
  FOR(i, 1, n) {
   
    int n_cord = lower_bound(ALL(cord), mp(a[i], 0LL)) - cord.begin();
  //  cout<<a[i]<<' '<<n_cord<<endl;
    update(1, 1, 100010, n_cord, i);
  }
  
  //cout<<endl;
  queue<pair<int,int>> pq;
  vector<vector<int>> states(100010, vector<int>(32, inf));
  int start = lower_bound(ALL(cord), mp(0LL, 0LL))- cord.begin();
  
  states[start][1] = 0;
  pq.push({start, 1});
  while(!pq.empty()) {
    auto [u, p] = pq.front();
    pq.pop();
    
    // the range we can traverse
    // decompress first
    ll center_coord = cord[u].fi;
    ll radius = (p == 0 ? 0 :(1LL << p - 1));
    
    ll left_bound = center_coord - radius;
    ll right_bound = center_coord + radius;

    int n_left = lower_bound(ALL(cord), mp(left_bound, -inf)) - cord.begin();
    int n_right = upper_bound(ALL(cord), mp(right_bound, inf)) - cord.begin() - 1;
    if (n_left <= n_right) {
      vector<pair<int,int>> tmp = query(1, 1, 100010, n_left, n_right);
      vector<int> next_jump;
      for(auto x : tmp) {
        if(u!=x.se)
          next_jump.pb(x.se);
        else {
          ans[x.first] = min(ans[x.first], states[u][p]);
        }
      }

    //cout<<n_left<<" "<<u<<" "<<n_right<<endl;
    // cout<<left_bound<<" "<<center_coord<<" "<<right_bound<<":"<<" ";
      for(int &v : next_jump) {
        //cout<<v<<' ';
        if (states[u][p] + 1 < states[v][p]) {
          states[v][p] = states[u][p] + 1;
          pq.emplace(mp(v, p));
        }
      }
  //  cout<<endl;
  //  cout<<endl;
    }
    if (p + 1 <= 30 && states[u][p] + 1 < states[u][p + 1]) {
      states[u][p + 1] = states[u][p] + 1;
      pq.emplace(mp(u, p + 1));
    }

    if (p - 1 >= 0 && states[u][p] + 1 < states[u][p - 1]) {
      states[u][p - 1] = states[u][p] + 1;
      pq.emplace(mp(u, p - 1));
    }
  }


  FOR(i, 1, n) {
    cout << (ans[i] == inf ? -1 : ans[i]) << "\n";
  }
}

// What are you doing here, Jimmy?
signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;  // cin >> t;
    while(t -- ) sol();
    return 0;
}