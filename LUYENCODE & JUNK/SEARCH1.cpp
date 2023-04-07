#include <iostream>
#include <set>
using namespace std;

int main()
{
    set <int> s1;
    int A,B[100000],a,b;
    cin>>A>>b;
    for(int x=0;x<A;x++)
    {
        cin>>a;
        s1.insert(a);
    }
    int size=s1.size();

    for(int x=0;x<b;x++)
    {
        cin>>B[x];
        s1.insert(B[x]);
        if(s1.size()==size)
            cout<<"1";
        else
        {
            cout<<"0";
        s1.erase(B[x]);
        }
    }
}