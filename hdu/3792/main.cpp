#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int TwinPrime[1000001];
bool prime[1000001];

int main()
{
    int i,j,n;

    for(i=2;i<=1000000;i++)
    {
        prime[i]=true;
    }
    for(i=2;i<=1000000;i++)
    {
        if(prime[i]==true){
            for(j=i+i;j<=1000000;j+=i)
            {
                prime[j]=false;
            };
        }
    }
    for(i=5;i<=1000000;i++)
    {
        if(prime[i]==true&&prime[i-2]==true){
            TwinPrime[i]=TwinPrime[i-1]+1;
        }else{
            TwinPrime[i]=TwinPrime[i-1];
        }
    }
    while(scanf("%d",&n)!=EOF&&n>=0)
    {
        printf("%d\n",TwinPrime[n]);
    }
    return 0;
}
