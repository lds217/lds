#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;int t500;int c500=0; int t200; int c200=0;int t100;int c100=0;int t50; int c50=0;
    int t10; int c10=0;int t20; int c20=0;
    cout<<"nhap so tien : ";
    cin>>t;
        t500=t%500;
        c500=t/500;
        if(t500!=0)
            {
            t200  = t500%200 ;
            c200  = t500/200 ;
                 if(t200!=0)
                    {   
                      t100=t200%100;
                      c100=t200/100 ;
                        if(t100!=0)
                        {
                            t50=t100%50;
                            c50=t100/50;
                                if(t50!=0)
                                {
                                    t20=t50%20;
                                    c20=t50/20;
                                        if(t20!=0)
                                        {
                                            t10=t20%10;
                                            c10=t20/10;
                                        }
                                }
                        }
                    }
            }     
    cout<<"so to tien 500 : "<<c500<<endl;  
    cout<<"so to tien 200 : "<<c200<<endl;  
    cout<<"so to tien 100 : "<<c100<<endl; 
    cout<<"so to tien 50 : "<<c50<<endl; 
    cout<<"so to tien 20 : "<<c20<<endl; 
    cout<<"so to tien 10 : "<<c10<<endl;  
system("pause");
return(0);
}
