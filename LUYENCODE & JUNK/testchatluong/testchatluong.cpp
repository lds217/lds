#include <iostream>
#include <string>
using namespace std;
string st;

void bai1(){
    cin>>st;
     long long sum =0;
    for(int x=0;x<st.size();x++)
    {
        if(st[x]=='i'||st[x]=='I')
         sum++;
        if(st[x]=='D'||st[x]=='d')
            sum--;
        if(st[x]=='s'||st[x]=='S')
            sum=sum*sum;
        if(st[x]=='o'||st[x]=='O')
            break;
    }
    cout<<sum;
}

int main()
{
    bai1();
    
}