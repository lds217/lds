#include<iostream>
#include<cctype>
using namespace std;
string solve(string s){
    int l,i;
    int r;
    string stam="";
    l=0;r=s.length()-1;
    while(s[l]==' ')l++;
    while(s[r]==' ')r--;
    int tam=toupper(s[l]);
    stam=stam+(char)tam;
    for(i=l+1;i<=r;){
        if(s[i]!=' '){
            tam=tolower(s[i]);
            stam=stam+(char)tam;
            i++;
            continue;
        }
        if(s[i]==' '){
            if(s[i+1]!=' '){
                tam=toupper(s[i+1]);
                stam=stam+s[i]+(char)tam;
                i+=2;
            }
        }
    }
    return stam;
}
int main(){
         int n;    
         
         cin>>n;
         int i;
         string a[n];
         cin>>a[0];     
         for(i=0;i<n;i++){
           // cin.ignore();
             getline(cin,a[i]);
             
             cout<<solve(a[i]);
             cout<<endl;
         }
         
    return 0;
}