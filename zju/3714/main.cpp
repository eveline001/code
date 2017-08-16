#include <iostream>
#include <cstdio>

using namespace std;

int a[201], sum[201];

int main()
{
    int T, N, M, ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &N, &M);
        sum[0] = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &a[i]);
            sum[i + 1] = sum[i] + a[i];
        }
        for(int i = N; i < N + M; i++) sum[i + 1] = sum[i] + a[i - N];
        ans = 0;
        for(int i = 0; i < N; i++) ans = max(ans, sum[i + M] - sum[i]);
        printf("%d\n", ans);
    }
    return 0;
}