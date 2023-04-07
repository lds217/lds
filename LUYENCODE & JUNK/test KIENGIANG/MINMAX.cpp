#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
long long maxx=0,minn=10000000001,a;



int main()
{
    
    ifstream f;
    f.open("MINMAX.INP");
    while(f>>a)
    {
        maxx=max(a,maxx);
        minn=min(a,minn);
    }
    
    f.close();
    cout<<minn<<" "<<maxx;
    
}