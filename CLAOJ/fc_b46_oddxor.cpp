// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to calculate Bitwise
// XOR of odd numbers in the range [1, N]
int findXOR(int n)
{
    // N & 3 is equivalent to n % 4
    switch (n & 3) {
 
    // If n is multiple of 4
    case 0:
        return n;
 
    // If n % 4 gives remainder 1
    case 1:
        return 1;
 
    // If n % 4 gives remainder 2
    case 2:
        return n + 1;
 
    // If n % 4 gives remainder 3
    case 3:
        return 0;
    }
}
 
// Function to find the XOR of odd
// numbers less than or equal to N
long long findOddXOR(int n)
{
 
    // If number is even
    if (n % 2 == 0)
 
        // Print the answer
        return((findXOR(n))
                 ^ (2 * findXOR(n / 2)));
 
    // If number is odd
    else
 
        // Print the answer
       return ((findXOR(n))
                 ^ (2 * findXOR((n - 1) / 2)));
}
 
// Driver Code
int main()
{
    int l,r;
    cin>>l>>r;
    cout<<(findOddXOR(r) ^ findOddXOR(l-1));

    return 0;
}