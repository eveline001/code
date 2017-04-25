#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;

int dp[MAX], last[MAX];

int main()
{
    int n, x;

    while(scanf("%d", &n) != EOF){
        dp[0] = 0;
        memset(last, 0, sizeof(last));
        for(int i = 1; i <= n; i++){
            scanf("%d", &x);
            dp[i] = ((long long)dp[i - 1] << 1) % MOD;
            if(!last[x]) last[x] = i, dp[i] = (dp[i] + 1) % MOD;
            else dp[i] = (dp[i] - dp[last[x] - 1] + MOD) % MOD, last[x] = i;
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
