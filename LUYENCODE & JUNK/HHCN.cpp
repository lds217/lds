#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long S1,S2,S3;int count;
    cout<<"nhap S1 ";
    cin>>S1;
    cout<<"nhap S2 ";
    cin>>S2;
    cout<<"nhap S3 ";
    cin>>S3;
    if(S1>0 && S2>0 && S3>0){
    long long a,b,c,Sum;
    b=sqrt((S3*S1)/S2);
    a=S1/b;
    c=S3/b;
    long long x=(pow(10,9)+7);
    Sum=4*(a+b+c);
    if (Sum>=x){
        while (Sum>=0)
        {
            Sum=Sum-x;
            count++;
        }
    cout<<count;}
    else
        cout<<Sum;}

system("pause");
	return(0);
}