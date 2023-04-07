#include <iostream>
#include <math.h>   
using namespace std;

int arr_m[1000000];
int c_arr_m=0;
int m;

int n;
int temp;
int arr_n[1000000];
int c_arr_n=0;

int k=1;
int arr_k[1000000];
int c_arr_k=0;
//em lạy c++ đừng có bug
void pt_m()
{
    for(int x=2;x<=m;x++)
        while(m%x==0)
        {
            arr_m[c_arr_m]=x;
            c_arr_m++;
            m=m/x;
        }
   // for(int x=0;x<c_arr_m;x++)
   //     cout<<arr_m[x];
   //     cout<<endl;
}
//em lạy c++ đừng có bug
void xuly_n()
{
    for(int x=2;x<=n;x++)
    {
        temp=x;
            while(temp%arr_m[c_arr_m-1]==0)
            {
                arr_n[c_arr_n]=arr_m[c_arr_m-1];
                c_arr_n++;
                temp=temp/arr_m[c_arr_m-1];
            }
    }
    //for(int x=0;x<c_arr_n;x++)
     //   cout<<arr_n[x];
     //   cout<<endl;

}
void xuly_arr_k()
{
    for(int x=0;x<c_arr_m;x++)
        if(arr_m[x]==arr_m[c_arr_m-1])
        {
            arr_k[c_arr_k]=arr_m[x];
            c_arr_k++;
        }
}
//em lạy c++ đừng có bug
int xuly_k()
{
    return k=(c_arr_n)/(c_arr_k);
}

int main()
{
    cin>>n>>m;
    pt_m();
    xuly_n();
    xuly_arr_k();
    cout<<xuly_k();
    return 0;
}