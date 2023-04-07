#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,k,a,b,A[100001]={0},B[100001]={0};
   
    cin>>n>>m>>k;
     if(n>m)
        int maxx=n;
   	else
        int maxx=m;
    for(int x=1;x<=k;x++)
    {  cin>>a>>b;
        A[a]=1;B[b]=1;
    }
    int s1=0,s2=0;
    for(int x=1;x<=maxx;x++)
    {
        if(A[x]==0&&x<=n)
            s1++;
        if(B[x]==0&&x<=m)
            s2++;
    }
    cout<<m*n-s1*m-s2*(n-s1);
}