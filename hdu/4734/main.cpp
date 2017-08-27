#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[10][4600];
int Dig[10];

int DigtialDP(int x, int A){
    int pos = 0;
    while(x) Dig[pos++] = x % 10, x /= 10;

    return DigtialDFS(pos - 1, );
}

int main()
{
    int T, A, B;

    memset(dp, -1, sizeof(dp));
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &A, &B);
        printf("Case #%d: %d\n", cas, DigtialDP(B, A));
    }
}
