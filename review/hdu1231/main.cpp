#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 1e4 + 7;

int dp[MAX], st[MAX], arr[MAX];

int main()
{
    int K, ans, pos;

    while(scanf("%d", &K) != EOF && K){
        for(int i = 0; i < K; i++){
            scanf("%d", &arr[i]);
            dp[i] = arr[i], st[i] = i;
        }
        ans = arr[0], pos = 0;
        for(int i = 1; i < K; i++){
            if(dp[i] + dp[i - 1] > dp[i]) dp[i] = dp[i] + dp[i - 1], st[i] = st[i - 1];
            if(dp[i] > ans) ans = dp[i], pos = i;
        }
        if(ans >= 0) printf("%d %d %d\n", ans, arr[st[pos]], arr[pos]);
        else printf("%d %d %d\n", 0, arr[0], arr[K - 1]);
    }
    return 0;
}
