#include <iostream>
#include <cmath>
using namespace std;

int arr[1000][1000];

int main()
{
    int N;
    cin >> N;
    for (int x = 0; x < N; x++)
        for (int i = 0; i < 2; i++)
            cin >> arr[x][i];

    for (int x = 1; x < N; x++)
        if (arr[x - 1][1] + abs(arr[x][0] - arr[x - 1][0]) + arr[x][2] > arr[x - 1][1] + abs(arr[x][1] - arr[x - 1][0]) + arr[x][0])
            swap(arr[x][1], arr[x][0]);
    for (int x = 0; x < N; x++)
    {
        for (int i = 0; i < 2; i++)
            cout << arr[x][i] << " ";
        cout << endl;
    }
    unsigned long long sum = 0, sum1 = 0;
    for (int x = 0; x < N; x++)
    {
        if (x == 0)
        {
            sum = sum + arr[x][1];
            sum1 = sum1 + arr[x][1];
        }
        else
        {
            //  sum = sum + abs(arr[x][1] - arr[x - 1][0]) + arr[x][0];
            sum1 = sum1 + abs(arr[x][0] - arr[x - 1][1]) + arr[x][1];
        }
        cout << sum << " " << sum1 << endl;
    }
    cout << sum;
}