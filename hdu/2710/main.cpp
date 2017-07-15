#include <iostream>
#include <cstdio>

using namespace std;

bool isPrime[20001];
int Prime[10000], Pnum;

int main()
{
    int n, x, ans, lastMaxFactor, curMaxFactor;

    Pnum = 0, isPrime[1] = false;
    for(int i = 2; i <= 20000; i++) isPrime[i] = true;
    for(int i = 2; i <= 20000; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= 20000; j += i) isPrime[j] = false;
            Prime[Pnum++] = i;
        }
    }
    while(scanf("%d", &n) != EOF){
        ans = 1, lastMaxFactor = 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            curMaxFactor = 1;
            for(int j = 0; j < Pnum && Prime[j] <= x; j++) if(x % Prime[j] == 0) curMaxFactor = Prime[j];
            if(curMaxFactor > lastMaxFactor) lastMaxFactor = curMaxFactor, ans = x;
        }
        printf("%d\n", ans);
    }
    return 0;
}
