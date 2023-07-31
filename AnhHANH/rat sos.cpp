// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number
// of adjacent swaps to make the string
// alternating
int minSwaps(string s)
{
	// Count the no of zeros and ones
	int ones = 0, zeros = 0;
	int N = s.length();

	for (int i = 0; i < N; i++) {
		if (s[i] == '1')
			ones++;
		else
			zeros++;
	}


	if ((N % 2 == 0 && ones != zeros)	|| (N % 2 == 1		&& abs(ones - zeros) != 1)) {
		return -1;
	}


	int ans_1 = 0;
	int j = 0;

	// Checking for when the string
	// starts with "1"
	for (int i = 0; i < N; i++) {
		if (s[i] == '1') {

			// Adding the no of swaps to
			// fix "1" at odd positions
			ans_1 += abs(j - i);
			j += 2;
		}
	}

	// Store no of min swaps when string
	// starts with "0"
	int ans_0 = 0;

	// Keep track of the odd positions
	int k = 0;

	// Checking for when the string
	// starts with "0"
	for (int i = 0; i < N; i++) {
		if (s[i] == '0') {

			// Adding the no of swaps to
			// fix "1" at odd positions
			ans_0 += abs(k - i);
			k += 2;
		}
	}

	// Returning the answer based on
	// the conditions when string
	// length is even
	cout<<ans_1<<' '<<ans_0;
	if (N % 2 == 0)
		return min(ans_1, ans_0);

	// When string length is odd
	else {

		// When no of ones is greater
		// than no of zeros
		if (ones > zeros)
			return ans_1;

		// When no of ones is greater
		// than no of zeros
		else
			return ans_0;
	}
}

// Driver Code 
int main()
{
	string S = "100011";
	cout << minSwaps(S);

	return 0;
}
