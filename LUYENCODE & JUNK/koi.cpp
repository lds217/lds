#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pair1 make_pair
#define fi first
#define id second
#define in freopen
#define task "MAIN"
using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define vt(a,n) vector<ll> a(n)
#define srt(a) sort(a.begin(),a.end())
#define ed "\n"
#define pb push_back


using namespace std;
const ll maxn = 1e6;
const ll mod = 1e9 + 7;
vector<vector<ll>> a(2000, vector<ll>(2000,1e9)),id(2000, vector<ll>(2000,0));
vector<vector<bool>> vst(2000, vector<bool>(2000,0));
ll n,m,xa,ya,xb,yb,mx = 1e18;
string ans;
ll dx[4] = {0,1,0,-1};
ll dy[4] = {1,0,-1,0};
string c = "RDLU";
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({xa,ya});
    a[xa][ya] = 0;
    while(!q.empty()){
        pair<ll,ll> x = q.front();
        q.pop();
        for (int i = 0; i<4; i++){
            ll xx = x.first + dx[i];
            ll yy = x.second + dy[i];
            //if (xx>0 && yy>0)cout << xx << " " << yy << " " << vst[xx][yy]<< ed;
            if (xx>=0 && yy>=0 && vst[xx][yy] && a[x.first][x.second]+1<a[xx][yy]){
                //cout << xx << " " << yy << ed;
                a[xx][yy] = a[x.first][x.second] + 1;
                q.push({xx,yy});
                id[xx][yy] = i;
            }
            if (xx==xb && yy==yb)break;
        }
    }
    if(a[xb][yb]==1e9)return;
    //cout << xb << " " << yb << " " << id[xb][yb]<< ed;
    while(xb!=xa || yb!=ya){
        ans+=c[id[xb][yb]];
        ll tx = xb, ty = yb;
        xb-=dx[id[tx][ty]];
        yb-=dy[id[tx][ty]];

        //cout <<  xb << " " << yb << " " << id[xb][yb] << ed;
    }
    //cout << xb << " " << yb << " " << xa << " " << ya << ed;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("TEST.INP","r",stdin);
    //freopen("TEST.OUT","w",stdout);
    cin >> n >> m;
    char x;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++){
            cin >> x;
            if (x=='A'){
                xa = i;
                ya = j;
                a[xa][ya] = 1;
                vst[xa][ya] = 1;
            }
            else if (x=='B'){
                xb = i;
                yb = j;
                vst[xb][yb] = 1;
            }
            else if (x=='.')vst[i][j] = 1;
        }
    //cout << xa << " " << ya << ed;
    bfs();
    /*
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++)
            cout << a[i][j] << " ";
        cout << ed;
    }
    */
    if(a[xb][yb]!=1e9){
        cout << "YES" << ed;
        cout << ans.size() << ed;
        //cout << ans;
        for (int i = ans.size()-1; i>=0; i--)
            cout << ans[i];
    }
    else cout << "NO";
    return 0;
}
