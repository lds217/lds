#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;string arr[20000];
    cin>>N;
    int temp;
    cin.ignore();
    char a=32;
    int count=0;
    for(int x=0;x<N;x++)
        getline(cin,arr[x]);
    
    for(int x=0;x<N;x++)
    {   
        count=0;
        if(arr[x][0]==' ')
             count++; 
        for(int j=0;j<arr[x].length();j++)
        {
            if(arr[x][j]!=a&&arr[x][j+1]==a)
                count++; 
        }
        temp=arr[x].length();
        if(arr[x][temp-1]==a)
            count--;
    cout<<count<<endl;
    }
    return(0);
}