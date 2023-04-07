#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int check[100],N,m;
    ifstream f;
    f.open("BAI3.INP");
    f>>N;
    f>>m;
    int a;
    for(int x=0;x<N;x++)
        f>>a,check[a]=1;
    bool stop
    ofstream f1;
    f1.open("BAI3.OUT");
    f1<<"vo nghiem";
}