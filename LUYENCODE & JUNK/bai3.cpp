#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int a[30000][1000]={0};

int main()
{
    
    int M,N,K,x,y,R,B;
    cin>>M>>N>>K;
    while(K--)
    {
        cin>>x>>y>>R>>B;
        for(int i=x;i<=x+R;i++)
        {
            for(int j=y;j<=y+R;j++)
                if(sqrt(pow(i-x,2)+pow(j-y,2))<=R)
                    a[i][j]+=B;
        }
    }

}