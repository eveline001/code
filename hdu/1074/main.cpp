#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF= 0x7fffffff;

struct Status{
    int toltime, presta, lost;
};

Status dp[1 << 16];
int n;

char s[20][110];
int d[20], c[20];

int main()
{
    int T, endsta, presta, temp;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%s%d%d", s[i], &d[i], &c[i]);
        endsta = (1 << (n + 1)) - 1, dp[1 << i].toltime = 0, dp[1 << i].presta = -1, dp[1 << i].lost = 0;
        for(int sta = 1; sta < endsta; sta++){
            dp[sta].lost = INF;
            for(int i = 0; i < n; i++){
                if(sta & (1 << i) == 1){
                    presta = sta - (1 << i);
                    temp = max(0, dp[presta].toltime + c[i] - d[i]);
                    if(dp[sta].lost > temp){
                        dp[sta].toltime = dp[presta].toltime + c[i];
                        dp[sta].presta = i;
                        dp[sta].lost = temp;
                    }
                }
            }
        }
        printf("%d\n", dp[endsta].lost);
        for(int i = dp[endsta].presta; ~i; i = )
    }
}
