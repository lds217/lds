#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a;
    cin>>a;
    if(sqrt(a)==round(sqrt(a)))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}