#include <bits/stdc++.h>
#include <string>
using namespace std;

string str,temp;
string checkdup[1000]={""};
int cnt=0;
char res[11];
int check[11]={0};

bool duplicated(string temp) {
    for(int i=0;i<cnt;i++)
        if(checkdup[i]==temp)   
            return 0;
    return 1;
}

void out(int n)
{
    temp="";
    for(int k=0;k<n;k++)
        temp =  temp +res[k]; 
    if(duplicated(temp))
    {
        cout<<temp;
        checkdup[cnt]=temp;
        cout<<endl;
    }
    cnt++;
}

void Try(int i,int n)
{
    for(int x=0;x<n;x++)
    {
        if(check[x]==0)
        {
            check[x]=1;
            res[i]=str[x];
            if(i==n-1)
                out(n);
            else
                Try(i+1,n);
            check[x]=0;
        }
    }
}

int main()
{
    cin>>str;
    int n=str.length();
    sort(str.begin(),str.end());
    Try(0,n);
}
    