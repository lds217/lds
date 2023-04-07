#include <iostream>
using namespace std;

int main()
{
    for(int x=1;x<=200;x=x+1)
    {
        cout<<x<<" ";
        if(x%10==0)
            cout<<endl;
    }
}