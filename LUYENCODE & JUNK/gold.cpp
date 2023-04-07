#include <iostream>
#include <algorithm>
using namespace std;

long long p[20000]={0};

int main()
{
    long long m, n, a, b;
    cin >> m >> n;
    long long temp;
    for (int x = 0; x < m; x++)
    {
        a = 0, b = 0;
        for (int y = 0; y < n; y++)
        {
            cin >> temp;
            if (temp > 0)
                a += temp;
            else
                b += -temp;
        }
        p[x]=max(a,b);
    }
    sort(p,p+m);
    if(m>1)
    cout<<p[m-1]+p[m-2];
    else
        cout<<p[m-1];
}