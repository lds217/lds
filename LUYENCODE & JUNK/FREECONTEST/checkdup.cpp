#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int a[1000],h[100000]={0};
    for(int x=0;x<1000;x++)
        cin>>a[x],h[a[x]]++;
    for(int x=0;x<100000;x++)
        if(h[x]>1)
            cout<<1;
}