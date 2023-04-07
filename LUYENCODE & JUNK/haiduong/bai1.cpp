#include <iostream>
#include <iomanip>
using namespace std;
float a;
int main()
{
    cin>>a;
    cout<<fixed;
    cout.precision(2);
    cout<<a*10.0/11.0<<" "<<a-a*10.00/11.00;
    return 0;
}