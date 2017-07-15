#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int dp[2001][2001];

int main()
{
    int n, m, h, k, pre, cur, tol;

    while(scanf("%d%d%d%d", &n, &m, &h, &k) != EOF){
        tol = pre = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &cur);
            if(pre != cur) tol += k - 1, pre = cur;
            else tol--;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][tol] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = m - i; j >= 0; j--){
                if(j - k + 1 >= 0) dp[i][j] = (dp[i][j] + (long long)dp[i - 1][j - k + 1] * (j - k + 1 ? h - 1 : h) % MOD) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
        printf("%d\n", dp[m][0]);
    }
    return 0;
}
