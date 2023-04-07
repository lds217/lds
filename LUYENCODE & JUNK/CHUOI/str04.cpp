#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

bool chuhoa(char x)
{
    if(x>='A'&&x<='Z')
        return 1;
    else
        return 0;
}

string vietthuong(string st)
{
    for(int x=0;x<st.length();x++)
        if(chuhoa(st[x]))
            st[x]=st[x]+'a'-'A';
    return st;
}

void dem(string st)
{   
    for(int x='0';x<='9';x++)
    {   
        int count=0;
        for(int i=0;i<st.length();i++)
            if(x==st[i])
                count++;
        if(count>0)
            cout<<(char)x<<" "<<count++<<endl;
    }
    for(int x='a';x<='z';x++)
    {   
        int count=0;
        for(int i=0;i<st.length();i++)
            if(x==st[i])
                count++;
        if(count>0)
            cout<<(char)x<<" "<<count++<<endl;
    }
    
}

int main()
{
    string st;
    getline(cin,st);
    st=vietthuong(st);
    dem(st);
    return 0;
}
