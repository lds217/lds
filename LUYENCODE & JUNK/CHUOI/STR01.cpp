#include <iostream>
#include <string>
using namespace std;

string thuong(string st)
{
    for(int i=0;i<=st.length()-1;i++)
    {
        if(st[i]>=65&&st[i]<=90)
            st[i]=st[i]+32;
    }
    return st;
}
int main()
{
    string st;
    getline(cin,st);
    cout<<thuong(st);
    return 0;
}