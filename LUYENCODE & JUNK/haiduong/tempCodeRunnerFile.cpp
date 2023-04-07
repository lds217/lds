#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#define ull unsigned long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull N;
    cin>>N;
    cout<<N<<" ";
    while (N!=1)
    {
        if(N%2==0)
            N=N/2;
        else
            N=N*3+1;
        cout<<N<<" ";
    }
    return 0;
}