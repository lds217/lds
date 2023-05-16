#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
 int arr[100005];

int spf[MAX];
 

vector<int> v[MAX];
 

void sieve()
{

    for (int i = 1; i < MAX; i++)
        spf[i] = i;

    for (int i = 4; i < MAX; i = i + 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAX; i++)
 
  
        if (spf[i] == i) {
 

            for (int j = i * i; j < MAX;
                 j = j + i) {
 

                if (spf[j] == j)
                    spf[j] = i;
            }
        }
}
 

void DistPrime()
{
    for (int i = 1; i < MAX; i++) {
 
        int idx = 1;
        int x = i;
 

        if (x != 1)
            v[i].push_back(spf[x]);
 
        x = x / spf[x];
 
        while (x != 1) {
 
            if (v[i][idx - 1]
                != spf[x]) {
                 v[i].push_back(spf[x]);
 

                idx += 1;
            }
 

            x = x / sp	2f[x];
        }
    }
}
 

void getFactorCount(int arr[],
                    int N)
{

    sieve();
 

    DistPrime();

    for (int i = 0; i < N; i++) {
        cout << (int)v[arr[i]].size()
             << " ";
    }
}
 
// Driver Code
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
        cin>>arr[i];
    int N = sizeof(arr) / sizeof(arr[0]);
 
    getFactorCount(arr, N);
 
    return 0;
}