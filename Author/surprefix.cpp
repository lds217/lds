#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b,temp;
    cin>>a>>b;
    int leng= a.size()-b.size();
    int dem=0;
    for(int x=leng;x<a.size();x++)
        if(a[x]==b[dem])
            dem++; 
        else
            dem=0;
    b.erase(0,dem);
    cout<<a<<b;
}