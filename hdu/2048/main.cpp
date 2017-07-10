#include <iostream>
#include <cstdio>

using namespace std;

long long dp[21];

int main()
{
    int T, n;
    long long sum;

    dp[1] = 0, dp[2] = 1;
    for(int i = 3; i <= 20; i++) dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        sum = 1;
        for(int i = 2; i <= n; i++) sum *= i;
        printf("%.2f%%\n", (double)dp[n] / sum * 100.0);
    }
    return 0;
}
