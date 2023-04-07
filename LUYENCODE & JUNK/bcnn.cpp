#include <iostream>
#include <string>
using namespace std;
string st;
string temp;

string revst()
    {
        for(int x=st.length()-1;x>=0;x--)
            temp[x+1]=temp[x];
        temp[0]=st[st.length()-1];
        
        return temp;
    }

int main()
{
    unsigned long long k;
    cin>>k;
    
    
    cin>>st;
    int dem=1;
    int o=st.length();

    while(st.length()<k)
    {
        temp=st;
        st=st+revst();
    }
    // for(int x=0;x<st.length();x++)
    // {
    // if(x%4==0)
    // cout<<" ";
    //     cout<<st[x];}
    cout<<st[k-1];
    return 0;
}