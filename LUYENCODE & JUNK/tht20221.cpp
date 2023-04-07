#include <iostream>
using namespace std;

bool eratos[30000000];

void eratosgen()
{
    eratos[1]=eratos[0]=1;
    for(int x=2;x*x<=30000000;x++)
        if(eratos[x]==0)
            for(int y=x*x;y<=30000000;y+=x)
                if(eratos[y]==0)
                    eratos[y]=1;
}

bool upperPrime(long long x){
	if (x%2==0 && x>2)
		return 0;
	else if (x%3==0 && x>3)
		return 0;
	else{
		long long k = (sqrt(x)+1)/6;
		for (int i=1;i<=k;i++)
			if ((x%(6*i+1) == 0) && (6*i+1 < x))
				return 0;
			else if((x%(6*i-1) == 0) && (6*i-1 < x))
				return 0;
	}
	return 1;
}

int main()
{
    eratosgen();
    int P,Q;
    cin>>P>>Q;
    int dem=0;
 //   cout<<eratos[13];
    if(Q<=30000000)
    for(int x=P;x<=Q;x++)
        if(eratos[x]==0&&eratos[x+6]==0&&x+6<=Q)
            dem++;
    cout<<dem;
    else
        {
        for(int x=P;x<=30000000-6;x++)
            if(eratos[x]==0&&eratos[x+6]==0&&x+6<=Q)
                dem++;
        for(int x=30000000-6;x<=Q-6;x++)
            if(Upperprime(x)==1&&Upperprime(x+6)==1)
                dem++;
        }
        
}