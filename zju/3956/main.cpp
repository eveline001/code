#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 5e2 + 1;

int H[MAXN], C[MAXN];
long long dp[MAXN * 100];

int main()
{
    int T, n, tol;
    long long ans, temp;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        ans = 0;
        tol = 0;
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &H[i], &C[i]);
            tol += C[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = tol; j >= C[i]; j--){
                if(~dp[j - C[i]]) temp = dp[j - C[i]] + H[i], dp[j] = ~dp[j] ? temp * temp - temp * j > dp[j] * dp[j] - dp[j] * j ? temp : dp[j] : temp;
            }
        }
        for(int i = 0; i <= tol; i++) if(~dp[i]) ans = max(ans, dp[i] * dp[i] - dp[i] * i - i * i);
        printf("%lld\n", ans);
    }
    return 0;
}
