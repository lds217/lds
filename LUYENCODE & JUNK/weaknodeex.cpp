#include <bits/stdc++.h>
using namespace std;

int n, m, s, t, comp;
vector<int> ke[10010 * 2], ds;
int vs[10010 * 2], cant[10010 * 2];

bool dfs(int i) {
    if(i==t+n) return true;
    if(vs[i]) return false;
    vs[i] = true;
    for(int k=0;k<ke[i].size();++k) {
        int j = ke[i][k];
        if(dfs(j)) {
            if(i+n==j) cant[i] = j;
            ke[j].push_back(i);
            ds.push_back(i);
            return true;
        }       
    }
    return false;
}

void dfs2(int i) {
    vs[i] = comp;
    for(int k=0;k<ke[i].size();++k)
        if(!vs[ke[i][k]] && ke[i][k]!=cant[i]) dfs2(ke[i][k]);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i=0;i<m;++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u+n].push_back(v);
    }
    for(int i=1;i<=n;++i) ke[i].push_back(i+n);
    dfs(s);
    memset( vs, 0, sizeof(vs));
    for(int k=ds.size()-1;k>=0;--k) if(!vs[ds[k]]) {
        ++comp;
        dfs2(ds[k]);
    }
    int dem = 0;
    for(int i=1;i<=n;++i) if(i!=s && i!=t && vs[i] != vs[i+n]) ++dem;
    printf("%d\n", dem);
    return 0;
}