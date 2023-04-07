#include <iostream>
using namespace std;

void xoan(int n)
{
    int arr[1000][1000];
    int num=0;
    int row=0;
    int col=0;
    int limit_col=0;
    int limit_row=1;

    
    do
    {
        //top
        for(col=0+limit_col;col<n-limit_col;col++)
        {
            arr[row][col]=num;
            num++;
        }
        col--;
        //right
        for(row=0+limit_row;row<=n-limit_row;row++)
        {
            arr[row][col]=num;
            num++;
        }
        row--;
        //bottom
        for(col=col-1;col>=0+limit_col;col--)
        {
            arr[row][col]=num;
            num++;
        }
        col++;
        //left 
        for(row=row-1;row>=0+limit_row;row--)
        {
            arr[row][col]=num;
            num++;
        }
        row++;
            
        limit_col++;
        limit_row++;
    }
    while(num<n*n);


    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
            if(arr[row][col]<10)
                cout<<"0"<<arr[row][col]<<" ";
            else 
                cout<<arr[row][col]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    xoan(n);
    return 0;
}