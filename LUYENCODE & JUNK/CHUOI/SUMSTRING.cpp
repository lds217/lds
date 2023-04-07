#include <iostream>
#include <string>
using namespace std;

int main(){
    string num1,num2;
    cin>>num1;
    cin>>num2;
    string sum,st_sum_con;
    int sum_con;
    if(num1.length()<num2.length())
        swap(num1,num2);
    //num1 luon lon hon num2
    int du=0;
    for(int x=1;x<=num1.length();x++)
    {   
        if(x<=num2.length())
         {    
            sum_con=(num1[num1.length()-x]-48)+(num2[num2.length()-x]-48)+du;
            du=0;
            st_sum_con= to_string(sum_con);
            if(sum_con>=10)
            {   
                if(x!=num1.length())
                {
                    du++;
                    sum_con=sum_con%10;
                    st_sum_con= to_string(sum_con);
                }
                else
                {
                    sum_con=sum_con%10;
                    st_sum_con= to_string(sum_con)+"1";
                }
            }
            
            sum=sum+st_sum_con;
        }
        else
        {    
            sum_con=(num1[num1.length()-x]-48)+du;
            du=0;
            st_sum_con= to_string(sum_con);
            if(sum_con>=10)
            {   
                if(x!=num1.length())
                {
                    du++;
                    sum_con=sum_con%10;
                    st_sum_con= to_string(sum_con);
                }
                else
                {
                    sum_con=sum_con%10;
                    st_sum_con= to_string(sum_con)+"1";
                }
            }
            sum=sum+st_sum_con;
        }
    }
    //reverse so lai
    string rev_sum;
    int i=0;
    for(int x=sum.length()-1;x>=0;x--)
    {   
        rev_sum[i]=sum[x];
        cout<<rev_sum[i];
        i++;
    }
    return 0;
}

