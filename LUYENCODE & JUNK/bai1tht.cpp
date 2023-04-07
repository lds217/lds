#include <bits/stdc++.h>
#include <string>
using namespace std;

string thapsangnhi(int x)
{
    string binary="";
    while(x>0)
    {
        binary+=x%2+'0';
        x/=2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int main()
{
    int a,b;
    string bit_a,bit_b;
    cin>>a>>b;
    bit_a= thapsangnhi(a);
    bit_b= thapsangnhi(b);
    if(a==0)
        bit_a="0";
    if(b==0)
        bit_b="0";

    if(bit_b.find(bit_a)!= string::npos)
    {
        cout<<a<<" nam trong "<<b<<endl; 
        long long res=stoi(bit_a,0,2);
        cout<<"So lon nhat nam trong "<<a<<" va "<<b<<" la: "<<res;
    }
    else
    {
        cout<<a<<" khong nam trong "<<b<<endl;
        int maxx=-1;
        for(int i=0;i<bit_a.size();i++)
        {
            string temp="";
            for(int j=i;j<bit_a.size();j++)
            {   
                temp=temp+bit_a[j];
                if(bit_b.find(temp)!= string ::npos)
                    maxx=max(maxx,stoi(temp,0,2));
            }
        }
        if(maxx!=-1)
            cout<<"So lon nhat nam trong "<<a<<" va "<<b<<" la: "<<maxx;
        else
            cout<<"Vo nghiem"; 
    }
}