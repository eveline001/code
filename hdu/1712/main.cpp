#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int A[101][101], dp[101];

int main()
{
    int N, M;

    while(scanf("%d%d", &N, &M) != EOF && (N || M)){
        for(int i = 0; i < N; i++) for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < N; i++) for(int k = M; k >= 1; k--) for(int j = 1; j <= k; j++)  dp[k] = max(dp[k], dp[k - j] + A[i][j]);
        printf("%d\n", dp[M]);
    }
    return 0;
}
