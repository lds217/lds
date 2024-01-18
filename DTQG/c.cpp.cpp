#include <iostream>
#include <cmath>
using namespace std;
int t;
int main()
{
    cin>>t;
    while(t--){
    long long n;
    cin>>n;
    int tmp=sqrt(1.0+8.0*n);
    if(tmp*tmp==1+8*n&&(int)sqrt(1+8*n)%2)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
    }
}