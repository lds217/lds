#include <iostream>
#include <string>
using namespace std;

string cong(string so1,string so2)
{
    int numso1;
    int tempso;
    string final;
    string sum="";
    int numso2;
    int du=0;
    if(so2.length()>so1.length())
        swap(so2,so1);
    while(so2.length()!=so1.length())
        so2="0"+so2;
    for(int x=so1.length()-1;x>=0;x--)
    {   
        numso1=(int)so1[x]-48;
        numso2=(int)so2[x]-48;
        tempso=numso1+numso2+du;
        if(tempso>=10)
        {
            du=1;
            tempso=tempso%10;
        }
        else
            du=0;
        sum=sum+to_string(tempso);
        if(x==0&&du==1)
            sum=sum+"1";
    }
    for(int x=sum.length()-1;x>=0;x--)
        final=final+sum[x];
    return final;
}

int main()
{
    string county="1",countx="1",x,y;
    cin>>x>>y;
    string ans=x,sum=ans;
     while (county!=y)
     {
         sum=ans;
         while(countx!=x)
         {
             ans=cong(sum,ans);
             countx=cong(countx,"1");
         }
         countx="1";
         county=cong(county,"1");
     }
     cout<<ans;
    return 0;
}

