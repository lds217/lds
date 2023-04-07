#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin>>n;
    for(int mask=0;mask<=(1<<n)-1;mask++)
    {
        for(int x=n-1;x>=0;x--)
            cout<<((mask>>x)&1);
        cout<<endl;
    }
}