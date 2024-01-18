// Created by BJMinhNhut
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i) 
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MASK(i) (1ll<<(i))
#define BIT(t, i) (((t)>>(i))&1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

/***Common Functions***/
template <class T>
bool minimize(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool maximize(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
void read(T &a) {
    a = 0;
    char c; 
    while (!isdigit(c = getchar())) {}
    do {
        a = a*10 + (c-'0');
    } while (isdigit(c = getchar()));
}

template<class T> 
void write(T a){
    if (a > 9) write(a/10);
    putchar(a%10 + '0');
}

/***End of Template***/
int height, width, numDays, K;
const int N = 2e3+5;
struct Query {
    int type, bot, top, left, right;
    //mild: 0, rain: 1, sun: 2
} queries[N];
vi valX, valY;
int val[2*N][2*N];
bool visited[2*N][2*N];
const int X[4] = {1, -1, 0, 0};
const int Y[4] = {0, 0, -1, 1};

void Input() {
    cin >> height >> width >> numDays >> K;
    FOR(i, 1, numDays) {
        string type; cin >> type;
        if (type == "mild") queries[i].type = 0;
        else {
            int t, b, l, r; cin >> l >> b >> r >> t;
            queries[i] = {(type == "sun")+1, b, t, l, r};
        } 
    }
}

int getXId(int x) {
    return lower_bound(ALL(valX), x) - valX.begin();
}

int getYId(int y) {
    return lower_bound(ALL(valY), y) - valY.begin();
}

bool valid(int i, int j) {
    return i >= 0 && i < (int)valX.size()-1 && j >= 0 && j < (int)valY.size()-1;
}

ll getSize(int i, int j) {
    return 1ll*(valX[i+1]-valX[i])*(valY[j+1] - valY[j]);
}

ll bfs(int sX, int sY) {
    ll ans = getSize(sX, sY);
    queue<ii> q; q.push(mp(sX, sY));
    visited[sX][sY] = 1;
    while (q.size()) {
        int i, j; tie(i, j) = q.front(); q.pop();
        FOR(dir, 0, 3) {
            int x = i + X[dir], y = j + Y[dir];
            if (valid(x, y) && !visited[x][y] && abs(val[x][y]) <= K) {
                visited[x][y] = true;
                ans += getSize(x, y);
                q.push(mp(x, y));
            }
        }
    }
    return ans;
}

void Solve() {
    vi().swap(valX); vi().swap(valY);
    valX.pb(1), valX.pb(width+1);
    valY.pb(1), valY.pb(height+1);  
    FOR(i, 1, numDays) {
        if (queries[i].type == 0) continue;
        valX.pb(queries[i].left);
        valX.pb(queries[i].right+1);
        valY.pb(queries[i].bot);
        valY.pb(queries[i].top+1);
    }
    sort(ALL(valX)); valX.resize(unique(ALL(valX)) - valX.begin());
    sort(ALL(valY)); valY.resize(unique(ALL(valY)) - valY.begin());
	for(int i:valX)	cout<<i<<' ';
	cout<<endl;
	for(int i:valY)	cout<<i<<' ';
	cout<<endl;
    memset(val, 0, sizeof val);
    FOR(i, 1, numDays) if (queries[i].type != 0) {
        int delta = queries[i].type == 1 ? 1 : -1;
        int left = getXId(queries[i].left);
        int right = getXId(queries[i].right+1);
        int bot = getYId(queries[i].bot);
        int top = getYId(queries[i].top+1);

        val[left][bot] += delta;
        val[left][top] -= delta;
        val[right][bot] -= delta;
        val[right][top] += delta;
    }
    FOR(x, 0, (int)valX.size()-1) FOR(y, 0, (int)valY.size()-1) {
        if (x) val[x][y] += val[x-1][y];
        if (y) val[x][y] += val[x][y-1];
        if (x && y) val[x][y] -= val[x-1][y-1];
    }
    FOR(x, 0, (int)valX.size()-2) 
	{
		FOR(y, 0, (int)valY.size()-2)	cout<<val[x][y]<<' ';
		cout<<endl;
	
		}
	cout<<getSize(2,2)<<endl;
    int cnt = 0;
    ll total = 0;
    FOR(i, 0, (int)valX.size()-2) FOR(j, 0, (int)valY.size()-2) if (abs(val[i][j]) <= K && !visited[i][j]) {
        total += bfs(i, j);
        cnt++;
    }
    cout << total << ' ' << cnt;
}   

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    if (fopen("inputf.in", "r")) freopen("inputf.in", "r", stdin);
    Input(), Solve();
    return 0;
}
