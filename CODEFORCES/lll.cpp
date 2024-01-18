#include <bits/stdc++.h>
using namespace std;

int a[100][100],b[100][100];
int n, m, p;

int main()
{
	cout<<"Nhap m va n"<<endl;
	cin>>m>>n;
	cout<<"Nhap ma tran a"<<endl;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	
	cout<<"Nhap n va p"<<endl;
	cin>>n>>p;
	cout<<"Nhap ma tran b"<<endl;
	for(int i=0; i<n; i++)
		for(int j=0; j<p; j++)
			cin>>b[i][j];
	// m x n  * n x p => m x p
	cout<<"Ma tran ket qua"<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<p; j++){
			int tmp=0;
			for(int k=0; k < n; k++)
				tmp+=a[i][k]*b[k][j];
				
			cout<<tmp<<' ';
		}
		cout<<endl;
	}
}