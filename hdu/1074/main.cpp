#include <iostream>
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
    int T;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%s%d%d", s[i], &d[i], &c[i]);
        for(int sta = 1; sta < (1 << (n + 1)) - 1; sta++){
            dp[sta].lost = INF;
            for(int i = n - 1; i >= 0; i--){

            }
        }
    }
}
