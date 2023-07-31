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
#define W 100000

vector <long long> tmp;
int i;
void sinh(int x)
{

    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
	int q=Rand(10000,100000);
	if(x==30)
		q=100000;
	inp<<q<<endl;
	while(q--)
	{
		int R=Rand(1000000,1000000000),L=Rand(1,10000),D=Rand(1,min(R-L+1,10000)),K;
		if(Rand(1,100000)%2)
			K=Rand(L,R);
		else
		{
			if(Rand(1,100000)%2)
				K=Rand(R,100000);
			else
				K=Rand(1,L);	
		}
		inp<<L<<' '<<R<<' '<<D<<' '<<K<<endl;
	}
	

}			

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(NULL));
    for (i=16; i<=30; i++)
    {
        sinh(i);
    }
    return 0;
}
