#include <iostream>
#include <cstdio>

using namespace std;

long long PowMod(long long x, long long n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return x % 10;
    }
    if(n == 2){
        return (x * x) % 10;
    }
    if(n % 2 == 0){
        int t = PowMod(x, n >> 1);
        return (t * t) % 10;
    }else{
        int t = PowMod(x, n >> 1);
        return ((x % 10) * ((t * t) % 10)) % 10;
    }
}

int main()
{
    int T;
    long long n;

    while(scanf("%d", &T) != EOF && T){
        for(int t = 1; t <= T; t++){
            scanf("%lld", &n);
            printf("%lld\n", PowMod(n, n));
        }
    }
}
