#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[1000]={0};
int main()
{
    int dem=0,res=0;
    string st;cin>>st;
    if(st=="")
    {
        cout<<"0";
        return 0;
    }
    for(int x=0;x<st.length();x++)
    {
        int i=x;
        dem=0;
        while(arr[st[i]]==0&&i<st.length())
        {
      //      cout<<st[i];
            dem++;
            arr[st[i]]++;
            ++i;
            
        }
      //  cout<<endl;
        fill(arr,arr+1000,0);
        res=max(dem,res);
    }
    cout<<res;
}