#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;

int main()
{
	float x; float a;float b;
	cin >> x;
    if(round(x)<=x)
        {
        a=round(x);
        b=a+1;
        }
    else
        {
        b=round(x);
        a=b-1;
        }
cout<<a<<" "<<b<<endl;	
system("pause");
return(0);
}
