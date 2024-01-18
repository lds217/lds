#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;


int main(){
	int l, r;
	cin >>l>>r;
	int cnt=0;
	for(int i=l+1,i<r;i++)
		for(int j=i+1;j<r;j++)
		{
			int temp =i*j;
			bool thoa=1;
			
			for(int z=2; z<=i*j;z++)
				if(temp % (z*z)==0)
				{
					thoa=0;
					break;
				}
			if(temp%3==0)
				thoa=0;
			if(thoa==1)
				cnt++;		
		}
	cout<<cnt;		
}