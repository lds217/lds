#include <bits/stdc++.h>
using namespace std;
 
// Function to check if XOR of all numbers
// in range [L, R] is Even or Odd
 
string isEvenOrOdd(int L, int R)
{
    // Count odd Numbers in range [L, R]
    int oddCount = (R - L) / 2;
 
    if (R % 2 == 1 || L % 2 == 1)
        oddCount++;
 
    // Check if count of odd Numbers
    // is even or odd
 
    if (oddCount % 2 == 0)
        return "Even";
    else
        return "Odd";
}
 
// Driver Code
int main()
{
 
    int L = 5, R = 15;
 
    cout << isEvenOrOdd(L, R);
 
    return 0;
}