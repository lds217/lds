#include <iostream>
using namespace std;

int countWays(string str) {
    int n = str.length();
    int count = 0;
    
    for (int i = 0; i < n - 3; i++) {
        if (str[i] == 'I' && str[i + 1] != 'C' && str[i + 2] == 'P' && str[i + 3] == 'C') {
            count++;
        }
    }
    
    return count;
}

int main() {
    string input;
    cout << "Input: ";
    getline(cin, input);
    
    int ways = countWays(input);
    
    cout << "Output: " << ways << endl;
    
    return 0;
}
