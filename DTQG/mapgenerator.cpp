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
#include <unistd.h>
// #include <unistd.h>
// #include <windows.h>
// #include <conio.h>
#define FOR(i, a, b) for (ll i = a, _b = b; i <= _b; i++)
#define FORD(i, a, b) for (ll i = a, _b = b; i >= _b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

// Remember to change things when switch to Macos

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

const int moveX[] = {0, -1, 0, 1};
const int moveY[] = {-1, 0, 1, 0};

template <class T>
bool minimize(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}

template <class T>
bool maximize(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

/*ll POW(ll a, ll b)
{
	if (b == 0)
		return 1;
	ll tmp = POW(a, b / 2);
	return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

long long tree[100000];
long long get(long long a)
{
	long long sum=0;
	while(a<100000)
	{
		sum+=tree[a];
		a= a+ (a&(-a));
	}
	return sum;
}

void update(long long a)
{
	while(a>0)
	{
		tree[a]+=1;
		a=a-(a&(-a));
	}
}

struct Hopcroftkarp{
	vi dist, matchX, matchY;
	vector<vi> a;
	int n, m;

	Hopcroftkarp() {}
	Hopcroftkarp(int _n, int _m){
		n = _n; m = _m;
		a = vector<vi> (n+1);
		dist = matchX = vi(n+1, -1);
		matchY = vi(m+1, -1);
	}

	void addEdge(int u, int v){a[u].pb(v);}

	int findPath(){
		int found = 0;
		queue<int> q;
		FOR (i, 1, n){
			if (matchX[i] < 0) dist[i] = 0, q.push(i);
			else dist[i] = -1;
		}

		while (!q.empty()){
			int x = q.front(); q.pop();
			for (int y : a[x]){
				if (matchY[y] < 0) found = 1;
				else if (dist[matchY[y]] < 0){
					dist[matchY[y]] = dist[x] + 1;
					q.push(matchY[y]);
				}
			}
		}

		return found;
	}

	int DFS(int x){
		for (int y : a[x]){
			if (matchY[y] < 0 || (dist[matchY[y]] == dist[x] + 1 && DFS(matchY[y]))){
				matchY[y] = x; matchX[x] = y;
				return 1;
			}
		}
		return 0;
	}

	int maxMatching(){
		int match = 0;
		while (findPath()){
			FOR (i, 1, n)
				if (matchX[i] < 0) match += DFS(i);
		}
		return match;
	}

	void show(){
		FOR (i, 1, n){
			Tryvet(i, arr[matchX[i]-1]);
		}
	}
};*/
// End of template//

struct PatInfo
{
	ii cord;
	string id;
	string name;
} Patients[maxn];

map<ii, string> Beds;
map<string, ii> cordBeds;
map<string, bool> hasBed;

int n = 12, m = 14;
ii start = {3, 15};

int roomid[2000][2000];

string floor_map[] = {
	{"0000000000000000"},
	{"0000000000000000"}, 
	{"0000000000000000"},
	{"00X11111111111X0"},
	{"0010000000001000"}, 
	{"0010000000001000"},
	{"0011111111111000"},
	{"0000010000100000"}, 	
	{"0000010000X00000"},
	{"0000010000000000"},
	{"0000010000000000"}, 
	{"00000X0000000000"},
	{"0000000000000000"},
};


int curr = 0;

void assign_roomid(int sx, int sy, string dir, int id)
{
	roomid[sx][sy] = id;
	if (dir == "DOWN")
		sx++;
	if (dir == "UP")
		sx--;
	if (dir == "LEFT")
		sy++;
	if (dir == "RIGHT")
		sy--;

	roomid[sx][sy] = id;
	queue<ii> q;
	q.push({sx, sy});
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		FOR(i, 0, 3)
		{
			int nx = x + moveX[i];
			int ny = y + moveY[i];
			if (nx < 0 || nx > n || ny > m || ny < 0 || floor_map[nx][ny] == '/' || floor_map[nx][ny] == '|' || floor_map[nx][ny] == '+' || floor_map[nx][ny] == '-')
				continue;
			if (roomid[nx][ny] == -1)
			{
				roomid[nx][ny] = id;
				q.push({nx, ny});
			}
		}
	}
}

int cur = 0;
void prepare_roomid()
{
	mset(roomid, -1);
	int id = 0;
	FOR(i, 0, n)
	FOR(j, 0, m)
	{
		if (roomid[i][j] == -1)
		{
			if (j + 1 <= m && floor_map[i][j] == '1' && floor_map[i][j + 1] == '/')
				assign_roomid(i, j, "DOWN", ++id);
			if (j - 1 >= 0 && floor_map[i][j] == '1' && floor_map[i][j - 1] == '/')
				assign_roomid(i, j, "UP", ++id);
		}
	}
}

void debug_roomid()
{
	int s = 2;
	cout << setw(s);
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		if (~roomid[i][j])
			cout << roomid[i][j] << setw(s);
		else
			cout << floor_map[i][j] << setw(s);
		cout << endl;
	}
}

void prepare_beds()
{
	int cur = 1;
	int cnt[maxn];
	mset(cnt, 0);
	FOR(i, 0, n)
	FOR(j, 0, m)
	if (floor_map[i][j] == 'X')
	{
		string BedId = to_string(roomid[i][j]) + "." + to_string(++cnt[roomid[i][j]]);
		Beds[{i, j}] = BedId;
		cordBeds[BedId] = {i, j};
	}
}

// void clearscr()
//{
//	cout << "\x1B[2J\x1B[H";
// }

void debug_beds()
{
	for (auto [u, id] : Beds)
		cout << u.fi << ' ' << u.se << ' ' << id << endl;
}

void beds_call_out()
{
	for (auto [u, id] : Beds)
		if (hasBed.find(id) == hasBed.end())
			cout << id << endl;
}

int NumPat;
void prepare_patients()
{
	cout << "Enter the number Patients: ";
	cin >> NumPat;
	FOR(i, 1, NumPat)
	{
		// system("cls");
		system("clear");
		cout << "This is the " << i << " patient!" << endl;
		sleep(1);
		cout << "Bro quat do name (e.g:Le_Thanh_Dat cuz im lazy af to process input)" << endl;
		string name;
		cin >> name;
		cout << "Please select the bed for " << name << endl;
		sleep(1);
		beds_call_out();
		cout << "Enter the EXACT id ";
		string choose;
		cin >> choose;
		Patients[i].name = name;
		Patients[i].id = choose;
		Patients[i].cord = cordBeds[choose];
		hasBed[choose] = 1;
	}
}

void debug_patients()
{
	FOR(i, 1, NumPat)
	{
		auto [cord, name, id] = Patients[i];
		cout << cord.fi << ' ' << cord.se << ' ' << name << ' ' << id << endl;
	}
}

void patients_call_out()
{
	FOR(i, 1, NumPat)
	{
		auto [cord, id, name] = Patients[i];
		cout << i << ' ' << name << ' ' << id << endl;
	}
}

int dis[200][200];
vector<char> trace;
vector<char> rotated_trace;
vector<char> ans;

void prepare_dfs()
{
	mset(dis, 0x3f);
	trace.clear();
}

const char dir[] = {'L', 'F', 'R', 'F', 'T'};
// F Go Fuckin Straight!!!!
// L Left
// R Right
// T TurnAround
string finall="";



void dfs(int x, int y, int u, int v, int prev)
{
	if (x == u && y == v)
	{
		ans = rotated_trace;
		ans.pb('T');
		
		FOR(i,0,ans.size()-1)
			if(i==0)
				cout<<ans[i];
			else
				if(ans[i]!=ans[i-1])
					cout<<ans[i];
		cout<<endl;
		return;
	}
	int cnt = -1;
	FOR(i, -1, 2)
	{
		int nx = x + moveX[(prev + i + 4) % 4];
		int ny = y + moveY[(prev + i + 4) % 4];
		cnt++;
		if (nx < 0 || nx > n || ny > m || ny < 0 || floor_map[nx][ny] == '/' || floor_map[nx][ny] == '|' || floor_map[nx][ny] == '+' || floor_map[nx][ny] == '-' || floor_map[nx][ny] == '0')
			continue;
		if (minimize(dis[nx][ny], dis[x][y] + 1))
		{
			 trace.pb(dir[i]);
			rotated_trace.pb(dir[cnt]);
			dfs(nx, ny, u, v, (prev + i + 4) % 4);
			rotated_trace.pop_back();
			trace.pop_back();
		}
	}
} // de vai l	

void visual(int x, int y, int ind)
{
	for (char i : ans)
	{
		system("cls");
		system("clear");
		cout << "Going to bed " << Patients[ind].id << endl;
		if (i == 'L')
			y--;
		if (i == 'R')	
			y++;
		if (i == 'U')
			x--;
		if (i == 'D')
			x++;
		char tmp = floor_map[x][y];
		floor_map[x][y] = 'A';
		FOR(j, 0, n)
		cout << floor_map[j] << endl;
		floor_map[x][y] = tmp;
		sleep(1);
	}
}

void control_input(ii curr)
{
	// system("cls");
	system("clear");
	cout << "Which patient do you want to visit ?" << endl;
	cout << "id"
		 << "   "
		 << "name"
		 << "  "
		 << "BedId:" << endl;
	patients_call_out();
	cout << "Enter the EXACT id (the first col) -1 to stop ";
	int choose;
	while (cin >> choose, choose != -1)
	{
		ii dest = Patients[choose].cord;
		prepare_dfs();
		dis[curr.fi][curr.se] = 0;
		int initial;
		if (curr.fi - 1 >= 0 && floor_map[curr.fi - 1][curr.se] == '1')
			initial = 1;
		if (curr.fi + 1 <= n && floor_map[curr.fi + 1][curr.se] == '1')
			initial = 3;
		if (curr.se - 1 >= 0 && floor_map[curr.fi][curr.se - 1] == '1')
			initial = 0;
		if (curr.se + 1 <= m && floor_map[curr.fi][curr.se + 1] == '1')
			initial = 2;
		ans.clear();
		dfs(curr.first, curr.se, dest.fi, dest.se, initial);
		//visual(curr.first, curr.se, choose);
		curr = dest;
		// system("cls");
		// return;
		// system("clear");
		cout << "Which patient do you want to visit ?" << endl;
		cout << "id"
			 << "   "
			 << "name"
			 << "  "
			 << "BedId: " << endl;
		patients_call_out();
		cout << "Enter the EXACT id (the first col) -1 to stop ";
	}
}

int main()
{
	//prepare_roomid();
	//debug_roomid();
	prepare_beds();
	// debug_beds();
	prepare_patients();
	// debug_patients();
	control_input(start);
	cout<<finall;
	return 0;
}


