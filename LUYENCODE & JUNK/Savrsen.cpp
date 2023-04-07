#include <iostream>
#include <cmath>
using namespace std;

long long cnt[10000007];

int main(int argc, char** argv)
{
    cnt[1]=1;
    for(int x=2;x*x<=10000007;x++) {
            for(int y=x*x;y<=10000007;y+=x) {
                cnt[y]+=x;if(x*x!=y)cnt[y]+=y/x;
        }
    }
    int L,R;
    cin>>L>>R;
    long long sum=0;
  //  cout<<cnt[8];
    for(int x=L;x<=R;x++)
        sum+=abs(cnt[x]+1-x);//,cout<<abs(cnt[x]+1-x)<<" ";
        cout<<sum;
}