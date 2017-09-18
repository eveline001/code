#include <iostream>
#include <cstdio>

using namespace std;

const long long MAXN = 1e18;

long long dp[20];

long long fastpow(long long x, long long p){
    long long res = 1;
    while(p){
        if(p & 1) res = res * x;
        x = x * x, p >>= 1;
    }
    return res;
}

int main()
{
    for(int i = 1; i <= 15; i++) dp[i] = fastpow(i, i);

    long long n;
    int ans;

    while(cin >> n){
        for(ans = 0; ans <= 15; ans++) if(dp[ans] > n) break;
        cout << ans - 1 << endl;
    }
    return 0;
}
