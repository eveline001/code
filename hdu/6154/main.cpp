#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long Slove(long long S, long long L){
    if(S == 0) return 0;
    if(L - 1 >= S) return 1;
    if(L * 2 >= S) return 2;
    if(L * 2 + L >= S) return 3;
    return 4;
}

int main()
{
    int T;
    long long N, L, E, S;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%I64d", &N);
        L = sqrt(N / 2);
        E = (long long)4 * L;
        S = L * L * 2;
        printf("%I64d\n", E + Slove(N - S, L));
    }
    return 0;
}
