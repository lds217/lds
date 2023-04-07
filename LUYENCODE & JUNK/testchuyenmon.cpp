#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;

void bai1()
{
    string name;
    getline(cin,name);
    cout<<"Chao "<<name<<"!";
}

void bai2()
{
    long long a,b;
    cin>>a>>b;
    cout<<a+b<<" ";
    cout<<a-b<<" ";
    cout<<a*b<<" ";
    if(b!=0)
    {
        cout<<a/b<<" ";
        cout<<a%b;
    }
    else
    {
        cout<<"INF"<<" ";
        cout<<"INF";
    }
}

void bai3()
{
    long long a;
    cin>>a;
    long long start=a*a;
    int xuonghang=0;
    while(start!=0)
    {
        cout<<start<<" ";
        start=start-1;
        xuonghang++;
        if(xuonghang==a)
        {
            cout<<endl;
            xuonghang=0;
        }
    }
}

void bai4()
{
    long long a,b,m,n;
    cin>>a>>b;
    cin>>m>>n;
    long long congsai=(b-a)/(n-m);
    cout<<(a-(congsai*(m-1)))<<" ";
    cout<<congsai;
    
}

void bai5()
{
    double a,b;
    cin>>a>>b;
    if(a==0)
    {
        if(b==0)
            cout<<"Vo so nghiem";
        else
            cout<<"Vo nghiem";
    }
    else
    {
        if(a<0)
            cout<<"X"<<" >= "<<-b/a;
        else
            cout<<"X"<<" <= "<<-b/a;
    }
}

void bai6()
{
    long long n;
    cin>>n;
    long long k=sqrt(n);
    for(int x=2;x<sqrt(n)+1;x++)
    {
        int temp=n;
        while(temp%x==0)
            temp=temp/x;
        if(temp==1)
        {
            cout<<"YES";
            break;
        }
        if(x==k)
            cout<<"NO";
    }

}

void bai7()
{
    long long m;
    long long a[10000];
    long long n;
    cin>>m;
    for(int x=0;x<m;x++)
        cin>>a[x];
    cin>>n;
    for(int x=m;x<n;x++)
    {
        long long sum=0;
        for(int i=x-m;i<x;i++)
            sum=sum+a[i];
        a[x]=sum;
        cout<<a[x]<<" ";
    }
  //  cout<<a[n];
}

int main()
{
    // bai1();
    // bai2();
    // bai3();
    // bai4();
    // bai5();
    // bai6();
    // bai7();
}