#include <iostream>
#include <string>
using namespace std;

int main()
{
    unsigned long long n;
    long long t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        cin >> n;
        string ans = "";
        while (n != 0)
        {
            ans = ans + char(n % 2 + '0');
            n = n / 2;
        }
        for (int x = ans.length() - 1; x >= 0; x--)
        {
            cout << ans[x];
        }
        cout << endl;
    }
}