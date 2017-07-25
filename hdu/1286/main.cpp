#include <iostream>
#include <cstdio>

using namespace std;

int Euler[10000001];
void Init(int n){
    Euler[1] = 1;
    for(int i = 2; i <= n; i++) Euler[i] = i;
    for(int i = 2; i <= n; i++) if(Euler[i] == i) for(int j = i; j <= n; j += i) Euler[j] = Euler[j] / i * (i - 1);
}

int main()
{
    int CN, n;

    scanf("%d", &CN);
    Init(32768);
    for(int i = 0; i < CN; i++){scanf("%d", &n); printf("%d\n", Euler[n]);}
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int divisor[32768];

void reset()
{
    for(int i=1;i<32767;i++)
    {
        divisor[i]=1;
    }
}

void work(int n)
{
    for(int i=2;i<=32767;i++)
    {
        if(divisor[i]==0)
        {
            continue;
        }
        if(n%i==0)
        {
            for(int j=i;j<=32767;j+=i)
            {
                divisor[j]=0;
            }
        }
    }
}

int countn(int N)
{
    int n=0;
    for(int i=2;i<=N;i++)
    {
        if(divisor[i]==1)
        {
            n++;
        }
    }
    return n+1;
}

int main()
{
    int i,CN,N;

    scanf("%d",&CN);
    for(i=0;i<CN;i++)
    {
        scanf("%d",&N);
        reset();
        work(N);
        printf("%d\n",countn(N));
    }
}
*/
