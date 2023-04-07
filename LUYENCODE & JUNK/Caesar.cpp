#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;
  int k;
  cin>>k;

  for(int x=0;x<st.length();x++)
        if(st[x]>='a'&&st[x]<='z')
            cout<<(char)((((st[x]-'a')+k)%26)+'a');
        else
            if(st[x]>='A'&&st[x]<='Z')
                cout<<(char)((((st[x]-'A')+k)%26)+'A');
            else
                cout<<st[x];
}