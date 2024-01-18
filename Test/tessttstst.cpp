#include <iostream>
using namespace std;
int n, a[1000];

void nhap()
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
}

bool isPrime(int x)
{
	if(x==1)	return false;
	for(int i=2; i*i <= x; i++)
		if(x%i==0)
			return false;
	
	return true;
}

void solve()
{
	bool hasPrime=0;
	for(int i=0; i<n; i++)
		if(isPrime(a[i])){
			cout<<a[i]<<' ';
			hasPrime=1;
		}
	
	if(hasPrime==0)
		cout<<0;		
}

int main()
{

	nhap();	
	solve();
	return 0;
}