#include <iostream>

using namespace std;

const unsigned long long MOD = 1e9 + 7;

unsigned long long FastPowMod(unsigned long long x, unsigned long long p){
    unsigned long long res = 1;
    while(p){
        if(p & 1) res = res * (x % MOD) % MOD;
        x = (x % MOD) * (x % MOD) % MOD;
        p >>= 1;
    }
    return res;
}

int main()
{
    int cas = 1;
    unsigned long long  n, k;

    while(cin >> n >> k) cout << "Case #" << cas++ << ": " << FastPowMod(n, k) << endl;
    return 0;
}
