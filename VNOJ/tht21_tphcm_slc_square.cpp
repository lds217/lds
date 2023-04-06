#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    unsigned long long bcnn = a * b / __gcd(a, b);
    bcnn = bcnn * c / __gcd(bcnn, c);
    unsigned long long res = 1, x = 0, cnt = 0;
   // cout<<bcnn;
    for (unsigned long long i = 2; i * i <= bcnn; ++i)
    {
        cnt=0;
        while (bcnn % i == 0)
        {
            bcnn /= i;
            cnt++;
        }
        if(cnt%2!=0)
            cnt++;
        res*=pow(i,cnt/2);
        
    }
    
    cout << res*bcnn;
    return 0;
}
