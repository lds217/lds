#include <iostream>
using namespace std;

bool eratos[1000000]={0};

void gen_eratos()
{
    eratos[0]=eratos[1]=1;
    for(int x=2;x*x<=1000000;x++)
    {
        if(eratos[x]==0)
        {
            for(int y=x*x;y<=1000000;y=y+x)
                if(eratos[y]==0)
                    eratos[y]=1;
        }
    }
}

int main() {
    int n;
    cin>>n;
    gen_eratos();
    if(eratos[n]==0)
        cout<<"SO NGUYEN TO MUAHHA";
}