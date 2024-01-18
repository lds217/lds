#include <bits/stdc++.h>
using namespace std;
int n,a[60],b[60],t,dem;
char c[60][60];
bool check[60];
bool last() {
    bool thu=false;
    for (int i=1;i<=n;++i) {
        if (a[i]>2 || a[i]<1) return false;
        if (a[i]==1 && thu) return false;
        if (a[i]==1) thu=true;
    }
    thu=false;
    for (int i=1;i<=n;++i) {
        if (b[i]>2 || b[i]<1) return false;
        if (b[i]==1 && thu) return false;
        if (b[i]==1) thu=true;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (c[i][j]=='X' && a[i]!=b[j]) return false;
        }
    }
    for (int i=1;i<=n;++i) {
        if (a[i]==1 || check[i]) continue;
        vector <int> vec,kq;
        for (int j=1;j<=n;++j) if (c[i][j]=='X') vec.push_back(j);
        
        for (int j=1;j<=n;++j) {
            if (i==j) continue;
            for (int k=1;k<=n;++k) if (c[j][k]=='X') kq.push_back(k);
            if (kq[0]==vec[0] && kq[1]==vec[1]) {
                check[i]=check[j]=true;
                break;
            }
            kq.clear();
        }
        if (check[i]==false) return false;
    }
    return true;
}
int main() {
    // freopen("square.inp","r",stdin);
    // freopen("square.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--) {
        ++dem;
        cout << "Case #"<< dem << ": ";
        cin >> n;
        for (int i=1;i<=n;++i) a[i]=b[i]=0;
        memset(check,false,sizeof(check));
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                cin >> c[i][j];
                if (c[i][j]=='X') ++a[i],++b[j];
            }
        }
        if (last()) cout << "POSSIBLE" << '\n';
        else cout << "IMPOSSIBLE" << '\n';
    }
}