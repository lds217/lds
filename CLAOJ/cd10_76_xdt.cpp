#include <iostream>
using namespace std;

int main()
{
	long long a,b;
	cin>>a>>b;	
	if(a+b>0)
		cout<<"Positive";
	if(a+b<0)
		cout<<"Negative";
	if(a+b==0)
		cout<<"Zero";
}
