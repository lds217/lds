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

// Function count the operations 
int reduceString(string s, int l) 
{ 

	int count = 1, steps = 0; 

	// traverse in the string 
	for (int i = 1; i < l; i++) { 
		// if adjacent characters are same 
		if (s[i] != s[i - 1]) 
			count += 1; 

		else { 
			// if same adjacent pairs are more than 1 
		
				steps += (count / 2); 

			count = 1; 
		} 
	} 

	
		steps += count / 2; 
	return steps; 
} 

// Driver Code 
int main() 
{ 

	string s = "dbdcfbbdc"; 
	
	int l = s.length(); 
	cout << reduceString(s, l) << endl; 
	return 0; 
} 
