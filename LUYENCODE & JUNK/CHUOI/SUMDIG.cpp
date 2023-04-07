#include <iostream>
#include <string>
using namespace std;

void Input_arr(int N,string st[]){   
    for(int x=0;x<N;x++)
        cin>>st[x];}

void sum_num(int N,string st[]){
    int tong,num;
    for(int x=0;x<N;x++)
    {   
        num=0;
        tong=0;
        for(int j=0;j<st[x].length();j++)
        {   num=(st[x][j]-48);
            tong+=num;
        }
        cout<<tong<<endl;
    }
}

int main(){
    string st[2000];
    int N;
    cin>>N;
    Input_arr(N,st);
    sum_num(N,st);
    return 0;
}
