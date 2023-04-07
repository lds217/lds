#include <iostream>
using namespace std;

int phong[4];
int hang1[4];
int hang2[4];
int S2;
int S3;
int h2;
int h3;
int total;
int c;

void nhap(){
    for(int x=0;x<3;x++)
        cin>>phong[x];
    for(int x=0;x<3;x++)
        cin>>hang1[x];
    for(int x=0;x<3;x++)
        cin>>hang2[x];
}

void xuli()
{
    for(int x=0;x<3;x++)
    {
        if(x==2)
           S2=hang1[x]*hang1[0];
        else
            S2=hang1[x]*hang1[x+1];
        if(x==0)
            h2=hang1[2];
        if(x==1)
            h2=hang1[0];
        if(x==2)
            h2=hang1[1];
        for(int i=0;i<3;i++)
        {
            if(i==2)
                S3=hang2[x]*hang2[0];
            else
                S3=hang2[x]*hang2[x+1];
            if(i==0)
                h3=hang2[2];
            if(i==1)
                h3=hang2[0];
            if(i==2)
                h3=hang2[1];
            total=S2+S3;
            if(total>phong[0]*phong[1]||h2>phong[2]||h3>phong[2])
            {
                c++;
                break;
            }
        }
        if(c!=0) 
            break;
    }
    if(c!=0)
        cout<<"NO";
    else
        cout<<"YES";
    
        
}

int main()
{
    nhap();
    xuli();
    return 0;
}
