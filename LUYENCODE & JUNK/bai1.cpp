#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(float x=1;x<n;x++)
    {
        if(sqrt(x)==round(sqrt(x)))
            cout<<x<<" ";
    }
system("pause");
return(0);
}
