#include <iostream>
using namespace std;

int gt(int a,int b)
{
    if(b==0)
        return 1;
    else 
        return gt(a,b-1)*a;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gt(a,b);
    return 0;
}