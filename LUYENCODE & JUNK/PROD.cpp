#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
    float a; float b;
    cin>>a;
    cin>>b;
    float mul=a*b;
    if(mul>=0)
    {
        if(mul>0)
            cout<<"1";
        else 
            cout<<"0";
    }
    else
        cout<<"-1";
        
system("pause");
	return(0);

}