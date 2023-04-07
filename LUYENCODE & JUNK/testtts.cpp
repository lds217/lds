#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n,a,b,c;
    cin>>a>>b>>c;
    n=sqrt(min(a,min(b,c)));
    while((n*n)%a!=0||(n*n)%b!=0||(n*n)%c!=0)
    {
        n++;
    }
    cout<<n;
}