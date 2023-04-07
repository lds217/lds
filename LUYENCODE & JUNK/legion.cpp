#include <bits/stdc++.h>
using namespace std;
long long ans;

int n1,n2,k1,k2;

int sol(int f,int h,int kf, int kh)
{
    if(f+h==0) return 1;
    else
    {
        if(f>0&&kf>0) ans=(ans+ sol(f-1,h,kf-1,k2));
        if(h>0&&kh>0) ans=(ans+ sol(f,h-1,k1,kh-1));
        return ans;
    }

}

int main(int argc, char **argv)
{

    cin>>n1>>n2>>k1>>k2;
    cout<<sol(n1,n2,k1,k2);
}