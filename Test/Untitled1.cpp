#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[10];
	int *p;
	p=a+4;
	*p = 100;
	cout<<a[4];
	for(int i=0;i<10;i++)
		cin>>*(a+i);
		
		for(int i=0;i<10;i++)
		cout<<*(a+i)<<' ';
}