#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(b==c)
        cout<<"YES";
    else{
        if(b>c) swap(b,c);
        c-=b;
        a+=2*b;
        if(c%3==0&&a>0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
    return 0;
}