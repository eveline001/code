#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool isprime[1000001];
int pri[1000001];
int p = 0;
void Init()
{
    isprime[1] = false;

    for(int i = 2; i <= 1000000; i++) isprime[i] = true;
    for(long long i = 2; i <= 1000000; i++){
        if(isprime[i]){
            for(long long j = i * i; j <= 1000000; j += i) isprime[j] = false;
            pri[p++] = i;
        }
    }
    p--;
}

bool Judge(long long x){
    for(int i = 0; i <= p; i++){
        if(x % pri[i] == 0){
            x /= pri[i];
            if(x % pri[i] == 0) return false;
        }
    }
    if(x == 1) return true;
    double tmp = sqrt(x * 1.0);
    if((int)(tmp + 0.5) == tmp) return false;
    return true;
}

int main()
{
    int T;
    long long n;

    Init();

    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        printf("Case %d: ", t);
        scanf("%I64d", &n);
        if(Judge(n) == true) printf("Yes\n"); else printf("No\n");
    }
}
