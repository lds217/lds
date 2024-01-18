#include <bits/stdc++.h>
using namespace std;

#define NAME "LINE"
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair

const int N = 100;
const int inf = 1e9 + 7;
int m,n,k = 0;
int moveX[] = {-1,-2,-2,-1,1,2,2,1};
int moveY[] = {-2,-1,1,2,2,1,-1,-2};
int matchX[N + 10],matchY[N + 10];
vector<vector<bool>>vis;
int dist[60][N + 10][N + 10],trace[N + 10],a[N + 10][N + 10],c[N + 10][N + 10];
pii x[N + 10],y[N + 10];

void bfs(int id,int x,int y) {
	vis.assign(m + 10,vector<bool>(n + 10,false));
	queue<pii>q;
	q.push(mp(x,y));
	vis[x][y] = true;
	dist[id][x][y] = 0;
	while (!q.empty()) {
		int ux = q.front().fi,uy = q.front().se;
		q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int vx = ux + moveX[dir],vy = uy + moveY[dir];
			if (vx < 1 || vx > m || vy < 1 || vy > n || a[vx][vy] == -1 || vis[vx][vy])
				continue;
			q.push(mp(vx,vy));
			dist[id][vx][vy] = dist[id][ux][uy] + 1;
			vis[vx][vy] = true;
		}
	}
}

int findPath() {
	queue<int>q;
	for (int i = 1; i <= k; i++) {
		if (!matchX[i]) q.push(i);
		trace[i] = 0;
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 1; v <= k; v++)
			if (c[u][v] && !trace[v]) {
				trace[v] = u;
				if (!matchY[v]) return v;
				q.push(matchY[v]);
			}
	}
	return 0;
}

void enlarge(int j) {
	int i,nxt;
	for (; j > 0; j = nxt) {
		i = trace[j];
		nxt = matchX[i];
		matchX[i] = j;
		matchY[j] = i;
	}
}

bool check(int val) {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			bool found = true;
			for (int z = 1; z <= k; z++) {
				matchX[z] = matchY[z] = 0;
				y[z] = mp(i,j + z - 1);
				if (j + z - 1 > n || a[i][j + z - 1] == -1) {
					found = false;
					break;
				}
			}
			if (!found) continue;
			for (int ii = 1; ii <= k; ii++)
				for (int jj = 1; jj <= k; jj++) {
					pii v = y[jj];
					if (dist[ii][v.fi][v.se] <= val) c[ii][jj] = 1, cout<<ii<<' '<<jj<<endl;
					else c[ii][jj] = 0;
				}
			int t;
			while (t = findPath()) enlarge(t);
			for (int ii = 1; ii <= k; ii++)
				if (!matchX[ii] || !matchY[ii]) {
					found = false;
					break;
				}
			if (found) return true;
		}
	return false;
}

int tknp(int l,int r) {
	int ans = r + 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) 
			ans = min(ans,mid),r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen(NAME".INP","r",stdin);
//	freopen(NAME".OUT","w",stdout);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			char ch;
			cin >> ch;
			if (ch == '#') a[i][j] = -1;
			else {
				a[i][j] = 0;
				if (ch == 'M') {
					k++;
					x[k] = mp(i,j);
				}
			}
		}
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= m; j++)
			for (int z = 1; z <= n; z++)
				dist[i][j][z] = inf;
	for (int i = 1; i <= k; i++) 
		bfs(i,x[i].fi,x[i].se);
	cout << check(0);
}
