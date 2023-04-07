#include <iostream>
#include <string>
#include <set>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    cin>>N;
    string st;
    set<string> temp;
    cin.ignore();
    getline(cin, st);
    for(int x=st.length()-1;x>=0;x--)
        if(st[x]<'0')
            st.erase(x,1);
    	else
            if(st[x]>'9')
                st.erase(x,1);
    for(int x=0;x<=st.size()-N;x++)
    {
        temp.insert(st.substr(x,N));
    }

    set<string>::reverse_iterator rit;
  
  
    // prints all elements in reverse order
    // using rbegin() and rend() methods
    string rev;
    for (rit = temp.rbegin(); rit != temp.rend(); rit++)
    {
        cout << *rit << " ";
        rev=*rit;
        break;
    }
    cout<<endl;
    cout<<rev;
}
