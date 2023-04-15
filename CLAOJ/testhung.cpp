#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
const int LOG = log2(N) + 2;

int n, k;
vector<int> adj[N], group[N];
int P[LOG][N], h[N];

void Input() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        if (y) {
            adj[i].push_back(y);
            adj[y].push_back(i);
        }
        group[x].push_back(i);
    }
}

void dfs(int u) {
    for(int &v : adj[u]) if (h[v] == 0) {
        h[v] = h[u] + 1;
        P[0][v] = u;
        dfs(v);
    }
}

void prepareLCA() {
    memset(h, 0, sizeof h);
    h[1] = 1; P[0][1] = 1;
    dfs(1);
    for(int i = 1; i < LOG; ++i) {
        for(int j = 1; j <= n; ++j) {
            P[i][j] = P[i - 1][P[i - 1][j]];
        }
    }
}

int LCA(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for(int i = LOG - 1; i >= 0; --i)
        if (h[P[i][u]] >= h[v])
            u = P[i][u];
    for(int i = LOG - 1; i >= 0; --i)
        if (P[i][u] != P[i][v])
            u = P[i][u],
            v = P[i][v];
    if (u != v) return P[0][u];
    return u;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    Input();
    prepareLCA();
   // cout<<"hii"<<h[1]<<" "<<h[2]<<h[4]<<h[5]<<" "<<LCA(5,2)<<endl;
    for(int i = 2; i <= k; ++i) {
        int deepest = group[i][0];
        for(int &u : group[i])
            if (h[deepest] < h[u])
                deepest = u;
        int res = 0;
        for(int &u : group[i]) if (deepest != u) {
            int p = LCA(deepest, u);
            cout<<deepest<<' '<<u<<endl;
            cout<<"h: "<<h[deepest]<<' '<<h[u]<<endl;
            res = max(res, h[deepest] + h[u] - 2 * h[p]);
        }
        cout << res << '\n';
    }

    return 0;
}
