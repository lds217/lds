#include <iostream>
#include <string>
using namespace std;
int N;int M;

int dem(string st[100])
{   
    int count=0;
    for(int x=0;x<N;x++)
    {
        for(int i=0;i<M-1;i++)
        {
            if(st[x][i]=='.'&&st[x][i+1]=='.')
                count++;
            if(x<N-1)
                if(st[x+1][i]=='.'&&st[x][i]=='.')
                    count++;
        }
    }
    return count;
}

void inputvadem()
{   
    string st[100];
    cin>>N;
    cin>>M;
    for(int x=0;x<N;x++)
        for(int i=0;i<M;i++)
            cin>>st[x][i];
    cout<<dem(st);
}

int main()
{   
    inputvadem();
    return 0;
}
