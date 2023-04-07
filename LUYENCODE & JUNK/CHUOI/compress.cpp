#include <iostream>
#include <string>
using namespace std;

string st;
string temp;
string temp1;

string sub;
int c;

void dem()
{
    for(int x=1;x<=st.length();x++)
    {  
        temp=st;//abcabc
        sub=st.substr(0,x);//a
        c=0;
        for(int i=st.length()-sub.length();i>=0;i=i-sub.length())
        {
            temp1=st.substr(i,sub.length());//a
            
            if(sub==temp1)
            {
                temp.erase(i,sub.length());//bcbc
                c++;
            }
        }
        if(temp==""|| x>st.length()/2)
            break;
    }
   
    cout<<c<<st;
}

int main()
{
    cin>>st;
    dem();
    return 0;
}