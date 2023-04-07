#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[100005], b[100005];
    cin >> n;
    for (int x = 0; x < n; x++)
        cin >> a[x];
    for (int x = 0; x < n; x++)
        cin >> b[x];
    if(a[n-1]!=b[0])
    {
        for(int x=0; x < n; x++)
            cout<<'a';
        for(int x=0; x < n; x++)
            cout<<'b';
    }
    else
    {
        int ch=0;
        for(int x=0; x < n; x++)
            if(a[x]!=b[0]&&ch==0)
                cout<<'b',ch++;
            else
                cout<<'a';
            cout<<'a';
        for(int x=1; x < n; x++)
            cout<<'b';
    }
}