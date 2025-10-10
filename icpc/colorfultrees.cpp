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
vector<int> adj[10005];
vector<int> cnt(100005, 0), node_color(100005, 0);
vector<pair<int,int>> edge(100005, {0,0});
vector<int> sz(100005, 0);
vector<int> fans(100005, 0);
int ans = 0;

void prep(int u, int par) {
  sz[u] = 1;
  for (int v : adj[u]) {
    if (v != par) {
      prep(v, u);
      sz[u] += sz[v];
    }
  }
}


// h (cnt - 2h - l);

void traverse(int u, int par, map<int,int> &heavy_colors, int &ans) {
  int heavy = 0;
  int maxx = 0;
  for(int v : adj[u])
    if (v != par) {
      if (sz[v] > maxx) {
        heavy = v;
        maxx = sz[v];
      }
    }

    
  if (heavy != 0)
    traverse(heavy, u, heavy_colors, ans);
  
  int current_color = node_color[u];
  int cnt_cur_color = heavy_colors[current_color];
  ans += (cnt[current_color] - 2 * cnt_cur_color - 1); 
  heavy_colors[current_color]++;
  
  for (int v : adj[u])
    if (v != par && v != heavy) {
      map<int,int> tmp_map;
      int tmp_ans = 0;
      traverse(v, u, tmp_map, tmp_ans);
      for (auto const& [color, light_count] : tmp_map) {
        long long heavy_count = heavy_colors[color];
        ans += light_count * (cnt[color] - 2 * heavy_count - light_count);
        heavy_colors[color] += light_count;
      }
    }

  fans[u] = ans;
}


void sol(){
  int n;
  cin >> n;
  
  FOR(i, 1, n) {
    cin>>node_color[i];
    cnt[node_color[i]]++;
  }
  
  FOR(i, 1, n-1) {
    int u, v;
    cin >> u >> v;
    edge[i] = {u, v};
    adj[u].pb(v);
    adj[v].pb(u);
  }
  prep(1, 0);
  map<int,int> colors;
  int ans = 0;
  traverse(1, 0, colors, ans);
  FOR(i,1 ,n -1) {
    int u = edge[i].fi;
    int v = edge[i].se;
    if (sz[u]>sz[v])
      cout<<fans[v];
    else 
      cout<<fans[u];
    cout<<endl;
  }
}

// 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;  // cin >> t;
    while(t -- ) sol();
    return 0;
}