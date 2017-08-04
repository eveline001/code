#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const long long MOD = 998244353;

const int PrimeRange = 1000000;

bool IsPrime[PrimeRange + 1];
int Pri[PrimeRange + 1];
int Pnum = 0;

void PrimeInit(){
    IsPrime[1] = false;
    for(int i = 2; i <= PrimeRange; i++) IsPrime[i] = true;
    for(long long i = 2; i <= PrimeRange; i++){
        if(IsPrime[i]){
            for(long long j = i * i; j <= PrimeRange; j += i) IsPrime[j] = false;
            Pri[Pnum++] = i;
        }
    }
}

long long num[1000007], cnt[1000007];

int main()
{
    int T;
    long long l, r, k, st, temp, ans;

    PrimeInit();
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%I64d%I64d%I64d", &l, &r, &k);
        for(int i = 0; i <= r - l; i++) num[i] = l + i, cnt[i] = 1;
        for(int i = 0; i < Pnum; i++){
            st = l - (l % Pri[i]);
            if(st < l) st += Pri[i];
            for(long long j = st; j <= r; j += Pri[i]){
                temp = 0;
                while(num[j - l] % Pri[i] == 0) num[j - l] /= Pri[i], temp++;
                cnt[j - l] = cnt[j - l] * ((temp * k % MOD + 1) % MOD) % MOD;
            }
        }
        ans = 0;
        for(int i = 0; i <= r - l; i++){
            if(num[i] > 1) cnt[i] = cnt[i] * (k + 1) % MOD;
            ans = (ans + cnt[i]) % MOD;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
