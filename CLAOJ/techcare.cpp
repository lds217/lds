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
#include <windows.h>
#include <conio.h>
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

//Remember to change things when switch to Macos

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};
const char dir[]={'L','R','D','U'};

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}

template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}


// End of template//

struct PatInfo{
    ii cord;
    string id;
    string name;
}   Patients[maxn];


map <ii,string> Beds;
map <string,ii> cordBeds;
map <string,bool> hasBed;

int n=12,m=15;
ii start={0,8};

int roomid[2000][2000];

 string floor_map[]={
    {"|000000|S|00000|"},
    {"|000000|1|00000|"}, // Phòng 1 và 2
    {"/1-----+1+---/1+"},
    {"|11111111111111|"},
    {"|1/----+1+----1/"},
    {"|111111|1|11111|"},
    {"|X0X0X0|1|X0X0X|"},  //Phòng 3 và 4
    {"+------+1+-----+"},
    {"|11111111111111|"},
    {"+-----1/-------+"},
    {"|11111111111111|"},
    {"|X0X0X0X0X0X0X0|"}, //Phòng 5
    {"+--------------+"},
};

int curr=0;

void assign_roomid(int sx,int sy, string dir,int id)
{
    roomid[sx][sy]=id;
    if(dir=="DOWN")
        sx++;
    if(dir=="UP")
    	sx--;
    if(dir=="LEFT")
    	sy++;
    if(dir=="RIGHT")
    	sy--;
    	
    roomid[sx][sy]=id;
    queue<ii> q;
    q.push({sx,sy});
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        FOR(i,0,3)
        {
            int nx = x+moveX[i];
            int ny = y+moveY[i];
            if(nx <0 || nx >n || ny >m||ny<0 
            || floor_map[nx][ny]=='/'|| floor_map[nx][ny]=='|' || floor_map[nx][ny]=='+'
            || floor_map[nx][ny]=='-') continue;
            if(roomid[nx][ny]==-1)
            {
                roomid[nx][ny]=id;
                q.push({nx,ny});
            }
        }
    }
}


int cur=0;
void prepare_roomid()
{
    mset(roomid,-1);
    int id=0;
    FOR(i,0,n)
        FOR(j,0,m)
        {
            if(roomid[i][j]==-1)
            {
                if(j+1<=m&&floor_map[i][j]=='1'&&floor_map[i][j+1]=='/')
                    assign_roomid(i,j,"DOWN",++id);
                if(j-1>=0&&floor_map[i][j]=='1'&&floor_map[i][j-1]=='/')
                    assign_roomid(i,j,"UP",++id);
//				need to process the doors more carefully
//                if(i+1<=n&&floor_map[i][j]=='1'&&floor_map[i+1][j]=='/')
//                	 assign_roomid(i,j,"RIGHT",++id);
//            	if(i-1<=n&&floor_map[i][j]=='1'&&floor_map[i+1][j]=='/')
//                	 assign_roomid(i,j,"LEFT",++id);
            }
        }   
}

void debug_roomid()
{
    int s=2;
    cout<<setw(s);
    FOR(i,0,n)
    {
        FOR(j,0,m)
        	if(~roomid[i][j])
            	cout<<roomid[i][j]<< setw(s);
            else
            	cout<<floor_map[i][j]<<setw(s);
        cout<<endl;
    }
}

void prepare_beds()
{
	int cur=1;
	int cnt[maxn];
	mset(cnt,0);
	FOR(i,0,n)
        FOR(j,0,m)
        	if(floor_map[i][j]=='X')
        	{
        		string BedId=to_string(roomid[i][j])+"."+to_string(++cnt[roomid[i][j]]);
        		Beds[{i,j}]=BedId;
        		cordBeds[BedId]={i,j};
        	}
				
}

//void clearscr()
//{
//	cout << "\x1B[2J\x1B[H";
//}

void debug_beds()
{
	for(auto [u,id]: Beds)
		cout<<u.fi<<' '<<u.se<<' '<<id<<endl;
}

void beds_call_out()
{
	for(auto [u,id]: Beds)
		if(hasBed.find(id)==hasBed.end())
			cout<<id<<endl;
}

int NumPat;
void prepare_patients()
{
	cout<<"Enter the number Patients: ";
	cin>>NumPat;
	FOR(i,1,NumPat)
	{
		system("cls");
		cout<<"This is the "<<i<<" patient!"<<endl;
		Sleep(1000);
		cout<<"Bro quat do name (e.g:Le_Thanh_Dat cuz im lazy af to process input)"<<endl;
		string name;
		cin>>name;
		cout<<"Please select the bed for "<<name<<endl;
		Sleep(1000);
		beds_call_out();
		cout<<"Enter the EXACT id ";
		string choose;
		cin>>choose;
		Patients[i].name=name;
		Patients[i].id=choose;
		Patients[i].cord=cordBeds[choose];
		hasBed[choose]=1;
	}
}

void debug_patients()
{
	FOR(i,1,NumPat)
	{
		auto[cord,name,id]=Patients[i];
		cout<<cord.fi<<' '<<cord.se<<' '<<name<<' '<<id<<endl;
	}
}

void patients_call_out()
{
	FOR(i,1,NumPat)
	{
		auto[cord,id,name]=Patients[i];
		cout<<i<<' '<<name<<' '<<id<<endl;
	}
}


int dis[200][200];
vector <char> trace;
vector <char> ans;

void prepare_dfs()
{
	mset(dis,0x3f);
	trace.clear();
}

void dfs(int x, int y,int u, int v)
{
	if(x==u&&y==v)
	{
		ans=trace;
		cout<<endl;
		return;
	}
	FOR(i,0,3)
	{
		int nx=x+moveX[i];
		int ny=y+moveY[i];
		if(nx <0 || nx >n || ny >m||ny<0 
        || floor_map[nx][ny]=='/'|| floor_map[nx][ny]=='|' || floor_map[nx][ny]=='+'
        || floor_map[nx][ny]=='-'||floor_map[nx][ny]=='0') continue;
		if(minimize(dis[nx][ny],dis[x][y]+1))
		{
			trace.pb(dir[i]);
			dfs(nx,ny,u,v);
			trace.pop_back();
		}
	}
}

void visual(int x,int y,int ind)
{
	
	for(char i: ans)
	{
		system("cls");
		cout<<"Going to bed "<<Patients[ind].id<<endl;
		if(i=='L')	y--;
		if(i=='R')	y++;
		if(i=='U')	x--;
		if(i=='D')	x++;
		char tmp=floor_map[x][y];
		floor_map[x][y]='A';
		FOR(j,0,n)
			cout<<floor_map[j]<<endl;
		floor_map[x][y]=tmp;
		Sleep(300);
	}
}

void control_input(ii curr)
{
	system("cls");
	cout<<"Which patient do you want to visit ?"<<endl;
	cout<<"id"<<"   "<<"name"<<"  "<<"BedId:"<<endl;
	patients_call_out();
	cout<<"Enter the EXACT id (the first col) -1 to stop";
	int choose;
	while(cin>>choose,choose!=-1)
	{
		if(choose==-1)	return;
		ii dest=Patients[choose].cord;
		prepare_dfs();
		dis[curr.fi][curr.se]=0;
		dfs(curr.first,curr.se, dest.fi, dest.se);
		visual(curr.first,curr.se,choose);
		curr=dest;
		system("cls");
		cout<<"Which patient do you want to visit ?"<<endl;
		cout<<"id"<<"   "<<"name"<<"  "<<"BedId: "<<endl;
		patients_call_out();
		cout<<"Enter the EXACT id (the first col) -1 to stop";
	}

}

int main()
{
    prepare_roomid();
    debug_roomid();
    prepare_beds();
    //debug_beds();
    prepare_patients();
    //debug_patients();
    control_input(start);
   	return 0;
}

// 				Created by LDS
// 	With the support of HSGS Long An Province
	 
/*
 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      	Ét <3 Su
  `Y8P'
   `Y'  
*/
