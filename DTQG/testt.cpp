// Template //
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

#define F first
#define S second
using namespace std;
struct SCC { int stamp, scc_num;
  struct Node : vector<int> {
    int dfn, low, scc; bool inS;
    Node() { dfn = low = scc = -1; inS = false; }
  };
  vector<Node> N; vector<int> stk;
  void init(int n) {
    N.clear(); N.resize(n); stk.clear();
  }
  void addEdge(int u, int v) { N[u].push_back(v); }
  void Tarjan(int u) { N[u].low = N[u].dfn = stamp++;
    stk.push_back(u); N[u].inS = true;
    for (auto &v : N[u]) if (!~N[v].dfn) Tarjan(v),
      N[u].low = min(N[u].low, N[v].low);
    else if (N[v].inS)
      N[u].low = min(N[u].low, N[v].dfn);
    if (N[u].dfn == N[u].low) {
      int v; do { v = stk.back(); stk.pop_back();
        N[v].scc = scc_num; N[v].inS = false;
      } while (v != u); scc_num++;
    }
  }
  void run() { stamp = scc_num = 0;
    for (int i = 0 ; i < N.size() ; i++)
      if (!~N[i].dfn) Tarjan(i);
  }
} solver;
typedef pair<int, int> pii;
int find(int x, vector<int> &pa) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x], pa);
}
int dfs(int u, vector<vector<int>> &G, vector<int> &vis) {
    vis[u] = 1;
    if (G[u].size() == 0) return u;
    for (auto &v : G[u]) {
        if (vis[v]) continue;
        int ret = dfs(v, G, vis);
        if (~ret) return ret;
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    solver.init(n);
    vector<pii> edges;
    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        solver.addEdge(u, v);
        edges.push_back({u, v});
    }
    solver.run();
    vector<int> rp(solver.scc_num, -1);
    for (int i = 0 ; i < n ; i++)
        rp[solver.N[i].scc] = i;
    n = solver.scc_num;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<int>> G(n);
    vector<int> iD(n, 0);
    for (auto &e : edges) {
        int u = solver.N[e.F].scc;
        int v = solver.N[e.S].scc;
        if (u == v) continue;
        G[u].push_back(v); iD[v]++;
    }
    vector<int> match(n, -1), vis(n, 0);
    for (int i = 0 ; i < n ; i++) {
        cout<<i<<":"<<iD[i]<<endl;
        if (iD[i]) continue;
        match[i] = dfs(i, G, vis);
        if (match[i] != -1)
            match[match[i]] = i;
    }
    for(int i=0;i<n;i++)
        cout<<match[i]<<endl;

    vector<int> I, O;
    for (int i = 0 ; i < n ; i++) {
        if (iD[i]) continue;
        if (match[i] == -1) continue;
        I.push_back(rp[i]);
        O.push_back(rp[match[i]]);
    }
    
    for (int i = 0 ; i < n ; i++) {
        if (match[i] != -1) continue;
        cout<<"SIUUUU";
        if (iD[i] == 0)
            I.push_back(rp[i]);
        if (G[i].size() == 0)
            O.push_back(rp[i]);
    }
    while (I.size() < O.size())
        I.push_back(I.front());
    while (O.size() < I.size())
        O.push_back(O.front());
    n = I.size();
    // cout << n << '\n';
    // for (int i = 0 ; i < n ; i++)
        // cout << O[(i + 1) % n] + 1 << ' ' << I[i] + 1 << '\n';
}