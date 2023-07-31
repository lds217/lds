#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long x;
	cin>>x;
	bool prime=1;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{			
			prime=0;
			break;
		}
	}
	
	if(prime==1)
		cout<<"No la snt";
	else
		cout<<"Khong phai la snt";
}