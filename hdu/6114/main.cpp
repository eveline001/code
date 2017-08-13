#include <iostream>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

long long FastPowMod(long long x, long long p){
    long long res = 1;
    while(p){
        if(p & 1) res = res * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return res;
}

int main()
{
    int T;
    long long k, n, ans;

    cin >> T;
    for(int cas = 1; cas <= T; cas++){
        cin >> k >> n;
        if(n < k) swap(k, n);
        ans = 1;
        for(int i = 1; i <= n; i++) ans = ans * i % MOD;
        for(int i = 1; i <= k; i++) ans = ans * FastPowMod(i, MOD - 2) % MOD;
        for(int i = 1; i <= n - k; i++) ans = ans * FastPowMod(i, MOD - 2) % MOD;
        cout << ans << endl;
    }
    return 0;
}
