#include <iostream>
using namespace std;

int main()
{
    int n,m;
    int d;
    cin>>n>>m;
    cin>>d;
    int ans1=1;
    int ans2=1;
    int tempn=n;
    while(n%d!=0)
    {
     n=n+tempn;
     ans1++;   
    }
    int tempm=m;
    while(m%d!=0)
    {
        m=m+tempm;
        ans2++;
    } 
    if( ans1<ans2)
        cout<<"1";
    if(ans1>ans2)
        cout<<"-1";
   	if(ans1==ans2)
        cout<<"0";
}