#include <iostream>
using namespace std;

int main()
{
    unsigned long long n;
    cin>>n;
    if(n==0)
    {
        cout<<"1";
        return 0;
    }
    cout<<n*n-n+2;
}