#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 7;
const int INF  = 0x7fffffff;

long long dp[MAXN], premax[MAXN];
int S[MAXN];

int main()
{
    int m, n;
    long long curmax;

    while(scanf("%d%d", &m, &n) != EOF){
        for(int i = 1; i <= n; i++) scanf("%d", &S[i]);
        memset(dp, 0, sizeof(dp));
        memset(premax, 0, sizeof(premax));
        for(int j = 1; j <= m; j++){
            curmax = -INF;
            for(int i = j; i <= n; i++){
                dp[i] = max(dp[i - 1], premax[i - 1]) + S[i];
                premax[i - 1] = curmax;
                curmax = max(curmax, dp[i]);
            }
        }
        printf("%I64d\n", curmax);
    }
    return 0;
}
