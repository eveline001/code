#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[10][4600], Dig[10], tol;

int f(int x){
    if(x == 0) return 0;
    int res = f(x / 10);
    return res * 2 + x % 10;
}

int DigtialDFS(int pos, int sum, bool limit){
    if(pos == -1) return sum <= tol;
    if(sum > tol) return 0;
    if(!limit && dp[pos][tol - sum] != -1) return dp[pos][tol - sum];
    int top = limit ? Dig[pos] : 9, res = 0;
    for(int i = 0; i <= top; i++) res += DigtialDFS(pos - 1, sum + i * (1 << pos), limit && i == Dig[pos]);
    if(!limit) dp[pos][tol - sum] = res;
    return res;
}

int DigtialDP(int x, int A){
    int pos = 0;
    while(x) Dig[pos++] = x % 10, x /= 10;
    return DigtialDFS(pos - 1, 0, true);
}

int main()
{
    int T, A, B;

    memset(dp, -1, sizeof(dp));
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &A, &B);
        tol = f(A);
        printf("Case #%d: %d\n", cas, DigtialDP(B, A));
    }
    return 0;
}
