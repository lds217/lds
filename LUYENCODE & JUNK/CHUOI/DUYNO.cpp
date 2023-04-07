#include <iostream>
#include <cstring>
using namespace std;


int XET(string st){
    int c=0;
    char space=' ';
    for(int x=0;x<st.length();x++)
    {   
        if(st[x]==space&&st[x+1]!=space)
        c++;
    }
    return c;
 }

int main(){
    string arr;
    cin>>arr;
    cout<<XET(arr);
    return 0;
 }