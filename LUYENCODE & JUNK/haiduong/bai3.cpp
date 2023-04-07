#include <iostream>
using namespace std;

long long m,n,Kmax,Lmax,leK,leL,nphai,ntrai;

long long xuli()
{
    Kmax=n/5;
    leK=n-Kmax*5;
    Lmax=m/5;
    leL=m-Lmax*5;
    long long count=Lmax*Kmax;
    for(int x=1;x<5;x++)
    {
        ntrai=Kmax;//1
        nphai=Lmax;//2 
        if(5-x<=leL)
            nphai++;
        if(x<=leK)
            ntrai++;
        count=count+nphai*ntrai;  
    }
    return count;
}

int main()
{
    cin>>n;
    cin>>m;
    cout<<xuli();
    return 0;
}