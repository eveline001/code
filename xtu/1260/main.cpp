#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 201;
const int P = 1e9 + 7;

long long Ori[MAXN][MAXN], Ret[MAXN][MAXN], M[MAXN][MAXN];

long long FastPowMod(long long x, long long p, long long MOD){
    long long res = 1;
    while(p){
        if(p & 1) res = res * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return res;
}

void GetInverseMatrix(long long Ori[MAXN][MAXN], long long E[MAXN][MAXN], int n){
    long long M[MAXN][MAXN], det = 1;
    memset(E, 0, n * n * sizeof(long long));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) M[i][j] = ((Ori[i][j] % P) + P) % P, E[i][j] = 0;
        E[i][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        int row = i;
        for(int j = i; j <= n; j++) if(M[j][i]){row = j;break;}
        if(row != i){
            det *= -1;
            swap(M[i], M[row]);
            swap(E[i], E[row]);
        }
        det = M[i][i] * det % P;
        long long inv = FastPowMod(M[i][i], P - 2, P);
        for(int j = 1; j <= n; j++){
            M[i][j] = inv * M[i][j] % P;
            E[i][j] = inv * E[i][j] % P;
        }
        for(int j = 1; j <= n; j++){
            if(j == i) continue;
            long long temp = M[j][i];
            for(int k = 1; k <= n; k++){
                M[j][k] = (M[j][k] - M[i][k] * temp % P + P) % P;
                E[j][k] = (E[j][k] - E[i][k] * temp % P + P) % P;
            }
        }
    }
    det = (det + P) % P;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) E[i][j] = det * E[i][j] % P;
}

int main()
{
    int n;

    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n - 1; i++){
            for(int j = 1; j <= n; j++){
                scanf("%I64d", &Ori[i][j]);
            }
        }
        for(int j = 1; j <= n; j++) Ori[n][j] = 1;
        GetInverseMatrix(Ori, Ret, n);
        for(int i = 1; i <= n; i++) printf("%I64d%c", ((i + n) & 1 ? (P - Ret[i][n]) % P : Ret[i][n]), " \n"[i == n]);
    }
    return 0;
}
