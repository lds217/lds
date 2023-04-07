#include <iostream>
#include <string>
using namespace std;

int count_space(string st){
    int count=0;
    char space=' ';
    if(st[0]==space)
        count++;
    for(int x=0;x<st.length();x++){
        if(st[x]!=space&&st[x+1]==space)
            count++;
    }
    if(st[st.length()-1]==space)
        count--;
    return count;}

int main(){
    int N;string arr[20000];
    cin>>N;
    cin.ignore();
    for(int x=0;x<N;x++)
        getline(cin,arr[x]);
    for(int x=0;x<N;x++)
        cout<<count_space(arr[x])<<endl;
     return(0);}
