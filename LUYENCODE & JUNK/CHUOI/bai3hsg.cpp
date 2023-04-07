#include <iostream> 
#include <string>
using namespace std;
//btc
string st;
string st_ans[100000];
string st_dif[100000];

void input()
{
    getline(cin,st);
}

void xuly()
{
    unsigned long long c=0;
    unsigned long long valuex=0;
    unsigned long long start=0;
    
    while (start!=st.length())
    {
        for(unsigned long long x=0;x<=st.length()-start;x++)
        {
        st_ans[c]=st.substr(start,x);
        c++;
        if(x==st.length())
            start++;
        }
    }
    st_dif[0]=st_ans[0];
    unsigned long long check=0;
    unsigned long long st_dif_c=1;
    for(unsigned long long x=0;x<c;x++)
    {
        check=0;
        for(unsigned long long i=0;i<st_dif_c;i++)
            if(st_ans[x]==st_dif[i])
                check++;
            if(check==0)
            {
                st_dif[st_dif_c-1]=st_ans[x];
                st_dif_c++;
            }
    }

    for(unsigned long long x=0;x<c;x++)
        cout<<st_ans[x]<<" ";//cout con` trung`

    cout<<endl;
    for(unsigned long long x=0;x<st_dif_c;x++)
        cout<<st_dif[x]<<" ";//cout ko trung`
    cout<<endl;
    cout<<st_dif_c-1;//cout cai output
}

int main()
{
    input();
    xuly();
    return 0;
}