#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main()
{
    string str;
    cin>>str;
    int a[91]={0};
    for(int i=0; i<str.size(); i++)
        a[str[i]]++;
    int le=0;
    for(int i='A';i<='Z';i++)
    {
      //  cout<<a[i]<<" ";
        if(a[i]%2!=0)
            le++;
        if(le==2)
        {
            cout<<"NO SOLUTION";
            return 0;
        }
    }
    string rev="";
    for(int i='A';i<='Z';i++)
    {
        
        if(a[i]>1)
            for(int j=1;j<=a[i]/2;j++)
                rev+=(char)i;
        if(rev.length()==floor(str.length()/2))
            break;
    }
    for(int i='A';i<='Z';i++)
        if(a[i]%2!=0&&a[i]!=0)
            rev+=char(i);
    if(le==1)
        for(int x=rev.length()-2;x>=0;x--)
            rev+=rev[x];
    else
        for(int x=rev.length()-1;x>=0;x--)
            rev+=rev[x];
    cout<<rev;
}