#include <bits/stdc++.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <cstdlib>
#include <ctime>
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
#define mset(a, b) memset(a, b, sizeof(a))
typedef int64_t ll;
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

/***End of Template***/
const int T = 40;
const string task = "ts10_ht_23_3"; /*type taskname here*/
const string folderName = "E:\\lds\\lds\\Author\\" + task + "\\";

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

void Gen(int idx) {
	string fileName = folderName + task + "." + to_string(idx)  + ".in";
	cerr << fileName << '\n';
	freopen(fileName.c_str(), "w", stdout);

}

void GenInput() {
	FOR(o,1,T)
	{
		Gen(o);
		if(o<=23)
		{
			ll n=Rand(1,1000);
			ll ans=Rand(1,10000);
			cout<<n<<endl;
			FOR(i,1,n)
			{
				if(Rand(1,1000)%5==0)
					cout<<0<<' ';
				else
					if(ans%2)
						cout<<(Rand(1,10000)%2||Rand(1,54545)%5?1:-1)*Rand(1,1000000000)<<' ';
					else
						cout<<(Rand(1,10000)%2||Rand(1,54545)%5?-1:1)*Rand(1,1000000000)<<' ';
			}
		}
		else
		{	if(o==24)
			{
				ll n=Rand(1,1000);
				cout<<n<<endl;
				FOR(i,1,n)
					cout<<0<<' ';
			}
			else
			{
			
				ll n=Rand(1,1000000);
				ll ans=Rand(1,10000);
				cout<<n<<endl;
				FOR(i,1,n)
				{
					if(Rand(1,1000)%5==0)
						cout<<0<<' ';
					else
						if(ans%2)
							cout<<(Rand(1,10000)%2||Rand(1,54545)%5?1:-1)*Rand(1,1000000000)<<' ';
						else
							cout<<(Rand(1,10000)%2||Rand(1,54545)%5?-1:1)*Rand(1,1000000000)<<' ';
				}
			}
		}
	}
}
fstream fi;
ll n,a[1000050];
void Input()
{
	fi>>n;
	FOR(i,1,n)	fi>>a[i];
	ll pos=1,flag=0;
	ll ans=0;

	FOR(i,1,n)
		if(a[i]*flag<=0)
		{
			ans=max(ans,i-pos+1);
			pos=i;
			flag=a[i]; 
		}
	cout<<ans;
}
// 
// 0 0 0 0 0 0 

void Solve()
{
	
}

void GenOutput() {
	FOR(i, 1, (int)T) {
		//Pre process
		string fileIn = folderName + task + "." + to_string(i) + ".in";
		string fileOut= folderName + task + "." + to_string(i) + ".out";
		cerr << "reading && solving: " << fileIn << "\n";
		double last = clock();
		fi.open(fileIn);
		freopen(fileOut.c_str(), "w", stdout);
		
	
			Input(); Solve();
	

		//Post process
        fi.close();
        double totalTime = clock() - last;
        cerr << "--->answered: " << fileOut << " (" << totalTime << "ms)" << '\n';
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    srand(time(NULL));
    mkdir(folderName.c_str());
    cerr << "Generating Input:\n";
    GenInput();
    cerr << "Generating Output:\n";
    GenOutput();
    return 0;
}
