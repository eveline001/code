#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int A[51], B[10001], dp[10001], tol;

int main()
{
    int T, n, m, cnt;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= m; i++){
            scanf("%d", &B[i]);
            if(i != 0) B[i] /= B[0];
        }
        tol = log(B[0]);
        for(int i = 0; i < tol; i++) A[i] = 0;
        memset(dp, 0, sizeof(dp));
        B[0] = dp[0] = 1;
        for(int i = 1; i <= m; i++){
            cnt = B[i] - dp[i];
            for(int num = 0; num < cnt; num++){
                A[tol++] = i;
                for(int v = m; v >= i; v--) dp[v] += dp[v - i];
            }
        }
        printf("%d", A[0]);
        for(int i = 1; i < tol; i++) printf(" %d", A[i]);
        printf("\n");
    }
    return 0;
}
