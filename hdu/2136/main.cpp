#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int prime[1000001];
bool book[1000001];

int main()
{
    int i,j,n;

    for(i=2;i<=1000000;i++)
    {
        book[i]=true;
    }
    int NUM=1;
    for(i=2;i<=1000000;i++)
    {
        if(book[i]==true){
            prime[i]=NUM;
            for(j=i+i;j<=1000000;j+=i)
            {
                book[j]=false;
                prime[j]=NUM;
            }
            NUM++;
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",prime[n]);
    }
    return 0;
}
