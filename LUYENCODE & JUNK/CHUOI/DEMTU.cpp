#include <iostream>
#include <cstring>
using namespace std;


int XET(string st){
    int c=1;
    char space=' ';
    if(st[0]==space||space==st[st.length()-1])//truong hop space o dau va o cuoi
        c--;
    for(int x=0;x<st.length();x++)
    {   
        if(st[x]==space&&st[x+1]!=space)
        c++;
    }
    return c;
 }

int main(){
    string arr;
    getline(cin,arr);
    cout<<XET(arr);
    return 0;
 }