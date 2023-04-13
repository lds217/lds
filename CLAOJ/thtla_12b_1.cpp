#include <bits/stdc++.h>

using namespace std;

bool upperPrime(long long x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}

int main()
{
	
    string str;
    
    cin>>str;
    long long num=stoll(str);
    int n=str.size();

    while(n!=0)
    {
       if(upperPrime(stoll(str.substr(0,n)))==0)
       {
           cout<<"khong";
           return 0;
       }
       n--;
    }
   cout<<"sieu nguyen to";
   return 0;
}