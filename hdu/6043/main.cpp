//wa
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int cas = 1, ans;
    long long n, k, round, times;

    while(scanf("%I64d%I64d", &n, &k) != EOF){
        if(k <= n) ans = k;
        else{
            k = k - n;
            times = k % (n - 1);
            round = k / (n - 1) + (times ? 1 : 0);
            if(round % 2) ans = times ? times : n - 1;
            else ans = times ? times : n;
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
