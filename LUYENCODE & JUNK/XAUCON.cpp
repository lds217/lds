#include <iostream>
#include <string>
using namespace std;

int main()
{
	int K;
	cin>>K;
	string st;
	cin>>st;
	int prefix[st.size()+1]={0};
	int cnt[100000]={0},res=0;
	//cnt[0]=1;
	for(int x=0;x<st.size();x++)
	{
		if(st[x]=='1')
			prefix[x+1]=prefix[x]++;
		else
			prefix[x+1]=prefix[x];
		
		
	}
	for(int x=1;x<=st.size();x++)
	{
		if(prefix[x]-K>=0)
			res+=cnt[prefix[x]-K];
		cnt[prefix[x]]++;
	}
	cout<<res;
	
		
			
}