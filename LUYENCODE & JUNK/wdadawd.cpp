#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int n,check[100000],cnt_check=0,a[100001],cnt=0;

bool duplicate(int temp)
{
	int cnt=0;
	for (int i=0;i<cnt_check;i++)
		if(temp==check[i])
		cnt++;
	if(cnt>=3)
		return 1;
	else
	{
		check[cnt_check++]=temp;
		return 0;
	}
}

void input()
{
	ifstream f;
	f.open("XB.INP");
	f>>n;
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(!duplicate(temp))
			a[cnt++]=temp;
	}
	f.close();
}

void output()
{
	for(int i=0;i<cnt;i++)
		cout<<a[i]<<" ";
}

int main()
{
	input();
	output();
}