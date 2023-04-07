#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int N,K,a[100000];
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>>a[i];
    int l=0,r=1;
    int res=0;
    set <int> s1;
    s1.insert(a[0]);
    s1.insert(a[1]);
    while(l<N-1&&r<N)
    {
        auto itr = s1.end();
        itr--;
        auto itl = s1.begin();
      //  cout<< *itr<<" "<<*itl<<endl;
        if(abs(*itl - *itr)<=K)
        {
          //  cout<<a[l]<<" "<<a[r]<<endl;
            r++;
            s1.insert(a[r]);
            res++;
        }
        else
            if(l==r-1)
            {
                s1.erase(a[l]);
                l++;
                r++;
                s1.insert(a[r]);
            }
            else
            {
                s1.erase(a[l]);
                l++;
            }
    }
    cout<<res+N;
}
