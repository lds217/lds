#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n;
    
    ifstream f;
    f.open("LIS.INP");
    f>>n;
    unsigned long long a[n],ss[n];
    for(int x=0; x<n; x++)
    {
        f>>a[x];
        ss[x]=1;
    }
    

    for(int x=0; x<n-1; x++)
    {
        for(int i=x+1; i<n; i++)
            if(a[i]>a[x]&&ss[i]==ss[x])
                ss[i]++;
    }
    // for(int x=0; x<n; x++)
    //     cout<<ss[x]<<" ";
    int maxx=0;
     for(int x=0; x<n; x++)
        if(maxx<ss[x])
            maxx=ss[x];
    cout<<maxx;
}