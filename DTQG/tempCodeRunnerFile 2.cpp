// Template //
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <array>
#include <cassert>
#include <random>
using namespace std;
 
// Function to count subarray having average
// exactly equal to K
int countKAverageSubarrays(int arr[], int n, int k)
{
    int result = 0, curSum = 0;
 
    // Store the frequency of prefix

    // sum of the array arr[]

    unordered_map<int, int> mp;
 
    for (int i = 0; i < n; i++) {

        // Subtract k from each element,

        // then add it to curSum

        curSum += (arr[i] - k);
 
        // If curSum is 0 that means

        // sum[0...i] is 0 so increment

        // res

        if (curSum == 0)

            result++;
 
        // Check if curSum has occurred

        // before and if it has occurred

        // before, add it's frequency to

        // res

        if (mp.find(curSum) != mp.end())

            result += mp[curSum];
 
        // Increment the frequency

        // of curSum

        mp[curSum]++;

    }
 
    // Return result

    return result;
}
 
// Driver code
int main()
{
    // Given Input

    int K = 4;

    int arr[] = {5 ,7 ,2 ,4 ,3, 1, 6};

    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function Call

    cout << countKAverageSubarrays(arr, N, K);
}