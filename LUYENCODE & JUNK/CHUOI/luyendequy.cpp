#include <iostream>
using namespace std;

int sum(int n)
{
    if(n==1)
        return 1;
    else 
        return sum(n-1)+n;
}

int fibo(int n)
{
    if(n==1||n==2)
        return 1;
    else 
        return fibo(n-2)+fibo(n-1);
}

int s_fibo(int n)

int main()
{
    int n;
    cin>>n;
    cout<<sum(n)<<endl;
    cout<<fibo(n);

    return 0;
}