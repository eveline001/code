#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 250000 + 7;

long long A[MAXN], B[MAXN];

int main()
{
    int n;
    long long an, ans;

    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++){scanf("%I64d", &A[i]); A[i] -= i;}
        for(int i = 1; i <= n; i++) scanf("%I64d", &B[i]);
        for(int i = n - 1; i > 0; i--) A[i] = max(A[i], A[i + 1]);
        sort(B + 1, B + n + 1);
        ans = A[B[1]];
        an = A[B[1]] - n - 1;
        for(int i = 2; i <= n; i++) ans = (ans + max(A[B[i]], an)) % MOD;
        printf("%I64d\n", ans);
    }
    return 0;
}
