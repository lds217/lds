#include <bits/stdc++.h>
using namespace std;


int main()
{
	int a = 12;
	int a1 = 9;
	int * const pa = &a;
	//pa = &a1;
	const int * pb = &a;
	//*pb = a1;
	const int * const pc = &a;
	//(*pc) = a1;
}