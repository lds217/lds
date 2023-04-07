#include <iostream>
#include <string>
using namespace std;

unsigned long long arrN[1000000];
unsigned long long N;
unsigned long long L;
unsigned long long R;
unsigned long long T;
string st[1000000];
string temp;
unsigned long long so;
unsigned long long c;
unsigned long long ans[100000];
unsigned long long cans=-1;

void inputNLR()
{
    cin>>N>>L>>R;
}

void inputarrN()
{
    for(int x=0;x<N;x++)
        cin>>arrN[x];
}

void sumst()
{
    for(int x=0;x<N;x++)
        st[x]=to_string(arrN[x]);
}

void xuli()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            temp=st[j]+st[i];
            so=stoi(temp);
            if(so>=L&&so<=R)
                c++;
        }
}

void luu()
{
    cans++;
    ans[cans]=c;
}

int main()
{
    cin>>T;
    for(int x=0;x<T;x++)
    {
        c=0;
        inputNLR();
        inputarrN();
        sumst();
        xuli();
        luu();
    }
    for(int x=0;x<=cans;x++)
        cout<<ans[x]<<endl;
    return 0;
}
