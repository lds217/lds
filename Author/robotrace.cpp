#include <iostream>
#include <fstream>
using namespace std;
#define task "30"
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);

	for(int i=1;i<=30;i++)
	{
		
		ifstream inp((to_string(i) + ".inp").c_str());
		ofstream ou((to_string(i) + ".out").c_str());
	    double S1, S2, v1, v2, t;
	    inp >> S1 >> v1 >> S2 >> v2;
	    if(v1 == v2)
		{
	        ou << "-1";
			 return 0;
		}
	    t = (S2 - S1)/(v1 - v2);
	    if(t>=0)
	        ou << (long long)t;
	    else ou << "-1";
	}
}