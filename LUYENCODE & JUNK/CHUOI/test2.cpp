#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int arr[100];
int n;
int arrtemp;


void input_arr()
{
    for(int x=0;x<n;x++)
        cin>>arr[x];
}
void xuly()
{
    int brk=1;
    int count=0;
    int count_bang=0;
    while(brk>0)
    {   
        count_bang=0;
        for(int x=0;x<n-1;x++)
            if(arr[x]!=arr[x+1])
               count_bang++;

            if(count_bang==0)
            {
                brk=brk-1;
                cout<<count;
            }

        arrtemp=arr[0];
        
        for(int i=0;i<n-1;i++)    
            arr[i]=abs(arr[i]-arr[i+1]);
        arr[n-1]=abs(arr[n-1]-arrtemp);   
        count++;
         if(count>1000)
         {
             brk=brk-1;
             cout<<"-1";
         }
    }
    
}
int main()
{
    cin>>n;
    input_arr();
    xuly();
    return 0;
}