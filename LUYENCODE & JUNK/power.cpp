#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    ios::sync_with_stdio;
    cin.tie(0);
    int T;
    cin>>T;
    unsigned long long n;
    while(T--)
    {
        cin>>n;
        long long b=round(pow(n,1.0/3));
        if(n==pow(b,3))
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
}