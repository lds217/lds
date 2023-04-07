#include <bits/stdc++.h>
#include <string>
using namespace std;


int main()
{
    string str[10000];
    int N;
    cin>>N;
    int maxlength=0;
    for(int x=0;x<N;x++)
    {
        cin>>str[x];
        if(str[x].length()>maxlength)
            maxlength=str[x].length();
    }
    int savedlength[10000],cnt=0;
    for(int x=0;x<N;x++)
    {
        savedlength[cnt++]=maxlength-str[x].length();
        while(str[x].length()<maxlength)
            str[x]=str[x]+"0";
    }
    int a[10000];
    for(int x=0;x<N;x++)
        a[x]=stoi(str[x]);
    sort(a,a+N);
    string res="";
    for(int x=N-1;x>=0;x--)
    {
        string temp=to_string(a[x]);
        for(int i=0;i<N;i++)
            if(temp==str[i])
                temp.erase(temp.length()-savedlength[i],temp.length());
        res=res+temp;
    }
    cout<<res;
}