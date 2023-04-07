#include <iostream>
using namespace std;
int m,n;
int arr[1000][1000];
int bool_arr[1000][1000];
int dem;
int arrss[100000];
int carrss=0;

void input()
{
    for(int x=0;x<=m+1;x++)
        for(int i=0;i<=n+1;i++)
        {
            if(x==0||i==0||x==m+1||i==n+1)
                arr[x][i]=0;
            else
                cin>>arr[x][i];
        }
    for(int x=0;x<=m+1;x++)
    {
        for(int i=0;i<=n+1;i++)
            cout<<arr[x][i];
        cout<<endl;
    }
}
void gan_bool_arr()
{
    for(int x=0;x<=m+1;x++)
        for(int i=0;i<=n+1;i++)
            bool_arr[x][i]=arr[x][i];
}
bool phai(int x,int i)
{
    if(bool_arr[x][i+1]==1)
        return 1;
    else
        return 0;
}

bool trai(int x,int i)
{
    if(bool_arr[x][i-1]==1)
        return 1;
    else
        return 0;
}

bool duoi(int x,int i)
{
    if(bool_arr[x+1][i]==1)
        return 1;
    else
        return 0;
}

bool tren(int x,int i) //hang cot
{
    if(bool_arr[x-1][i]==1)
        return 1;
    else
        return 0;
}

void loang(int x,int i)//hang , cot
{
    bool_arr[x][i]=0;
    if(tren(x,i))//hang cot
    {
        dem++;
        loang(x-1,i);
    }
    if(phai(x,i))//hang cot
    {
        dem++;
        loang(x,i+1);
    }
    if(duoi(x,i))//hang cot
    {
        dem++;
        loang(x+1,i);
    }
    if(trai(x,i))//hang cot
    {
        dem++;
        loang(x,i-1);
    }
}

void chon()
{
    for(int i=0;i<=n+1;i++) //i la hang
        for(int x=0;x<=m+1;x++) //x là cot
            if(bool_arr[i][x]==1)
            {   
                dem=1;
                loang(i,x);//hang , cot
                cout<<dem<<" ";
                arrss[carrss]=dem;
                carrss++;
            }
}

int max()
{
    int max=arrss[0];
    for(int x=1;x<carrss;x++)
        if(arrss[x]>max)
            max=arrss[x];
    return max;
}

int main()
{
    cin>>m;
    cin>>n;
    input();
    gan_bool_arr();
    chon();
    cout<<endl;
    cout<<max();
    return 0;
}