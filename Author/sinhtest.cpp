#include<bits/stdc++.h>
using namespace std;
#define el inp<<'\n'
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
const int ttest = 7;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}
#define maxn 2003
//#define A 1000000000
#define A 10000000000000000
#define H 100000
#define M 100000
#define N 1000
#define Q 100000
#define X 2000000000
#define K 1000000000
#define W 100000

vector <long long> tmp;
int i;
void sinh(int x)
{

    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
	int t=2*1e6;
	inp<<t<<endl;
	deque <int> a;
	vector <int> b;
	for(int i=0;i<t;i++)
	{
		if(Rand(1,100000)%2==0||Rand(1,100000)%5==0)
			a.push_front(i);
		else
			a.push_back(i);
	}
	while(!a.empty())
	{
	
		b.push_back(a.front());
		a.pop_front();		
	}
	int l=Rand(1,10000),r=Rand(1,10000);
	while(l>=r||r>=t)
		l=Rand(1,10000),r=Rand(1,10000);
 	shuffle(b.begin()+l, b.begin()+r, default_random_engine(0));
	for(int i: b)
		inp<<i<<' ';

}			

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(NULL));
    for (i=29; i<=30; i++)
    {
        sinh(i);
    }
    return 0;
}
