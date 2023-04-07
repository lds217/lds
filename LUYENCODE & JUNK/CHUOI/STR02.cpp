#include <iostream>
#include <string>
using namespace std;

char viet_hoa(char x)
{
    return x+'A'-'a';
}
char viet_thuong(char x)
{
    return x+'a'-'A';
}
bool chu_thuong(char x)
{
    if(x>='a'&&x<='z')
        return 1;
    else 
        return 0;
}

bool la_chu(char x)
{
   if((x>='A'&&x<='Z')||(x>='a'&&x<='z'))
        return 1;
    else 
        return 0; 
}

string xulixau(string st)
{
    for(int x=st.length()-1;x>=0;x--)
    {
        if(!la_chu(st[x])&&st[x]!=' ')
            st.erase(x,1);
    }
    return st;
}
void chuanhoa(int n)
{
    string st[1000];
    for(int x=1;x<=n;x++)
    {
        if(x==1)
            getline(cin,st[x]);
        getline(cin,st[x]);
        st[x]=xulixau(st[x]);
    }
    cout<<endl;
    for(int x=1;x<=n;x++)
    {
        string stx=st[x];
        if(chu_thuong(stx[0]))
            stx[0]=viet_hoa(stx[0]);
        for(int i=1;i<stx.length();i++)
        {   if(stx[i]==' ')
                {if(chu_thuong(stx[i+1]))
                    stx[i+1]=viet_hoa(stx[i+1]);}
            else
                {if(!chu_thuong(stx[i+1])&&stx[i+1]!=' ')
                    stx[i+1]=viet_thuong(stx[i+1]);}
        }
        cout<<stx<<endl;  
    }
}
int main()
{
    int n;
    cin>>n;
    chuanhoa(n);
    return 0;
}