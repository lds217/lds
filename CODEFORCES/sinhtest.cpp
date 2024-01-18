#include <bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
#define rand rd
#define NAME "PER"
#define NTEST 100

int Rand(int l, int r){
	assert(l<r);
	return l+(rand()*rand()%(r-l+1)+(r-l+1))%(r-l+1);
}

void make_test()
{
	ofstream inp(NAME".inp");
	inp<<1000<<' '<<1000<<endl;
	vector <int> a;
	for(int i=1;i<=1000;i++)
		a.push_back(i);
	random_shuffle ( a.begin(), a.end(), Rand(1,10));
	for(int i:a)
		inp<<i<<' ';
		inp<<endl;
		random_shuffle ( a.begin(), a.end(), Rand(1,10));
		for(int i:a)
		inp<<i<<' ';
		inp<<endl;
	for(int i=1;i<=1000;i++)
	{
		int x=Rand(1,1000);
		int y=Rand(x,1000);
		inp<<x<<' '<<y<<' '<<x<<' '<<y<<endl;
	}
}

int main()
{
	for(int i=1;i<10;i++)
	{
		make_test();
		system(NAME".exe");
		system(NAME"trau.exe");
		if(system("fc " NAME".out " NAME".ans")){
			cout<<"NO \n";
			return 0;
		}
		cout<<"YES\n";
	}
}