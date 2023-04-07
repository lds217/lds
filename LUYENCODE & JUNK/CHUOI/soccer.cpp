#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    string str;
    int v=0,i=0;
    while(T--)
    {
        cin>>str;
        if(str=="Vietnam")
            v++;
        else
            i++;
    }
    cout<<v<<" "<<i;
}