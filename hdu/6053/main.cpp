#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 7;

const int MobiusRange = 100000;
int Mobius[MobiusRange + 1];

void GetMobius(){
    for(int i = 1; i <= MobiusRange; i++){
        int target = i == 1 ? 1 : 0;
        int delta = target - Mobius[i];
        Mobius[i] = delta;
        for(int j = i + i; j <= MobiusRange; j+= i) Mobius[j] += delta;
    }
}

int A[MAXN];

long long FastPowMod(long long x, long long p){
    long long res = 1;
    while(p){
        if(p & 1) res = res * (x % MOD) % MOD;
        x = (x % MOD) * (x % MOD) % MOD;
        p >>= 1;
    }
    return res;
}

int main()
{
    int T, n, st, ed;
    long long ans, cnt;

    GetMobius();
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        st = MAXN, ed = 0;
        memset(A, 0, sizeof(A));
        for(int i = 0, x; i < n; i++){
            scanf("%d", &x);
            st = min(st, x), ed = max(ed, x), A[x]++;
        }
        for(int i = 2; i <= ed; i++) A[i] += A[i - 1];
        ans = 0;
        for(int d = 2; d <= st; d++){
            if(Mobius[d]){
                cnt = -Mobius[d];
                for(int i = 1; i <= ed / d; i++){
                    cnt = cnt * FastPowMod(i, A[min(ed, i * d + d - 1)] - A[i * d - 1]) % MOD;
                }
                ans = (ans + cnt + MOD) % MOD;
            }
        }
        printf("Case #%d: %I64d\n", cas, ans);
    }
    return 0;
}
