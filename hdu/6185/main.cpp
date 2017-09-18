#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const long long MOD = 1000000007;

void Multi(long long A[4][4], long long B[4][4], long long ans[4][4]){
    long long res[4][4];
    memset(res, 0, sizeof(res));
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++){
        for(int k = 0; k < 4; k++) res[i][j] = (res[i][j] + ((A[i][k] + MOD) % MOD) * ((B[k][j] + MOD) % MOD) % MOD + MOD) % MOD;
    }
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) ans[i][j] = res[i][j];
}

void fastMulti(long long X[4][4], long long p, long long ans[4][4]){
    for(int i = 0; i < 4; i++) ans[i][i] = 1;
    while(p){
        if(p & 1) Multi(X, ans, ans);
        Multi(X, X, X);
        p >>= 1;
    }
}

const long long Ori[4][4]{1, 1, 0, 0, 5, 0, 1, 0, 1, 0, 0, 1, -1, 0, 0, 0};
const long long f[4]{36, 11, 5, 1};
long long X[4][4], tmp[4][4];

int main()
{
    long long n;

    while(scanf("%I64d", &n) != EOF){
        if(n <= 4) printf("%I64d\n", f[4 - n]);
        else{
            memcpy(X, Ori, sizeof(Ori));
            memset(tmp, 0, sizeof(tmp));
            fastMulti(X, n - 4, tmp);
            long long ans = 0;
            for(int i = 0; i < 4; i++) ans = (ans + f[i] * ((tmp[i][0] + MOD) % MOD) % MOD) % MOD;
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
