#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char s[101];
int dp[2][2];

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    for(int cas = 1; cas <= T; cas++){
        gets(s);
        memset(dp, 0, sizeof(dp));
        if(s[0] <= 'Z'){
            dp[0][0] = dp[0][1] = 2;
        }else{
            dp[0][0] = 1;
            dp[0][1] = 3;
        }
        for(int i = 1; s[i] != '\0'; i++){
            if(s[i] <= 'Z'){
                dp[1][0] = min(dp[0][0] + 2, dp[0][1] + 2);
                dp[1][1] = min(dp[0][0] + 2, dp[0][1] + 1);
            }else{
                dp[1][0] = min(dp[0][0] + 1, dp[0][1] + 2);
                dp[1][1] = min(dp[0][0] + 2, dp[0][1] + 2);
            }
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        printf("%d\n", min(dp[1][0], dp[1][1] + 1));
    }
    return 0;
}
