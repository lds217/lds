#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool dup[11];
vector<long long> ans;

bool check(long long x)
{
	memset(dup,0,sizeof(dup));
	while(x>0)
	{
		if(dup[x%10])
			return 0;
		dup[x%10]=1;
		x/=10;
	}
	return 1;
}


int main()
{
    freopen("squares.inp","r",stdin);
    freopen("squares.out","w",stdout);
  for(long long i=1;i*i<=100000000000;i++)
  		if(check(i*i))
		  ans.push_back(i*i);
	long long k;
	cin>>k;
	if(k>(int)ans.size())
		cout<<-1;
	else
		cout<<ans[k-1];
}