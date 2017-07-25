#include <iostream>
#include <cstdio>

using namespace std;

const long long MOD = 1e9 + 7;

long long dp[10007];

inline long long ExGCD(long long A, long long B, long long& x, long long& y){
    if(A == 0 && B == 0) return -1;
    if(B == 0){x = 1, y = 0; return A;}
    long long d = ExGCD(B, A % B, y, x);
    y -= A / B * x;
    return d;
}

long long ModReverse(long long a, long long f){
    long long x, y, d = ExGCD(a, f, x , y);
    if(d == 1){
        if(x % f <= 0) return x % f + f;
        else return x % f;
    }
    return -1;
}

int main()
{
    int T, n, k;
    long long p, q, inv, ans;

    scanf("%d", &T);
    dp[1] = 0, dp[2] = 1;
    for(int i = 3; i <= 10000; i++) dp[i] = (((dp[i - 1] + dp[i - 2]) % MOD) * (n - i)) % MOD;
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &n, &k);
        ans = 0;
        for(int i = k; i <= n; i++){

        }
    }
}
