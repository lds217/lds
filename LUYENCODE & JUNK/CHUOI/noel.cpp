#include <iostream>
using namespace std;

int main()
{
    int c=0;
    //nhap
    int n;
    cout<<"cay thong co 3 tang hay nhap chieu cao cua tang cao nhat";
    cin>>n;
    //chieu rong cua hop
    int r=(n+2)*2-1;
    //dinh
    int dinh=r/2+1;
    int countdinh;
    cout<<"  ***  ***  "<<endl;
        cout<<" *    *   * "<<endl;
        cout<<"  * Ngoc * "<<endl;
        cout<<"   *   * "<<endl;
        cout<<"     *"<<endl;
    for(int k=0;k<3;k++)
    {
        countdinh=0;
        for(int x=1;x<=n+c;x++)
        {
            for(int i=1;i<=r;i++)
            {
                if(i==dinh-countdinh)
                {
                    cout<<"#";
                    for(int x=dinh-countdinh+1;x<=r;x++)
                    {
                        if(x<=dinh+countdinh)
                        {
                            if(x==dinh+countdinh)
                                cout<<"#";
                            else
                                cout<<"x";
                        }
                        else
                            cout<<" ";
                        
                    }
                    break;
                }
                else
                    cout<<" ";
            }
            cout<<endl;
            countdinh++;
        }
        c++;
    }
    for(int i=0;i<2;i++)
       { for(int x=0;x<=r/2;x++)
         if(x==r/2)
            cout<<"I";
        else
            cout<<" ";
        cout<<endl;}
        
    return 0;
}