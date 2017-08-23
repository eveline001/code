#include <iostream>
#include <cstdio>

using namespace std;

long long dp[21];

int main()
{
    int C, N, M;
    long long cnm;

    dp[1] = 0, dp[2] = 1;
    for(int i = 3; i <= 20; i++) dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1);

    scanf("%d", &C);
    for(int cas = 1; cas <= C; cas++){
        scanf("%d%d", &N, &M);
        cnm = 1;
        for(int i = 2; i <= N; i++) cnm *= i;
        for(int i = 2; i <= M; i++) cnm /= i;
        for(int i = 2; i <= N - M; i++) cnm /= i;
        printf("%I64d\n", cnm * dp[M]);
    }
    return 0;
}
