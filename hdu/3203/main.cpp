#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 1e5 + 7;

double dp[MAX][2];

int main()
{
    int n, a, b, temp;
    double p;
    while(scanf("%d%d%d%d", &n, &temp, &a, &b) != EOF && (n || temp || a || b)){
        p = temp / 100.0;
        dp[n][0] = 0;
        dp[n][1] = min(a, b);
        for(int i = n - 1; i >= 1; i--){
            dp[i][1] = min(dp[i + 1][1] + b, p * dp[i + 1][1] + a + (1.0 - p) * dp[i + 1][0]);
            dp[i][0] = p * dp[i + 1][1] + (1.0 - p) * dp[i + 1][0];
        }
        printf("%.4f\n", min(dp[1][0], dp[1][1]));
    }
    return 0;
}
