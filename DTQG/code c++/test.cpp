#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
    int x=7;
    while(x>0)
    {
        x-=x&-x;
        cout<<x<<" ";
    }
}