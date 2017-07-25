#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long fs(long long x, int m){
    long long res = 0;
    while(x >= m){
        res += x % m;
        x /= m;
    }
    return res + x;
}

int main()
{
    int T, m;
    long long n, M, ans;

    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%I64d%d", &n, &m);
        M = sqrt(n) + 0.5;
        ans = -1;
        for(long long x = M; x >= 1; x--){
            if(n % x == 0){
                if(fs(x, m) == n / x - x){
                    ans = x;
                }
            }
            if(n / x - x > 107){
                break;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
