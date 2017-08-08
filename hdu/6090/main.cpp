#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    long long n, m, ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%I64d%I64d", &n, &m);
        if(m >= n * (n - 1) / 2){
            ans = n * (n - 1);
        }else if(m > n - 1){
            ans = (n - 1) * 2 + (n - 1) * (n - 2) * 2 - (m - n + 1) * 2;
        }else{
            ans = m * 2 + m * (m - 1) * 2 + (m + 1) * (n - m - 1) * n * 2 + (n - m - 1) * (n - m - 2) * n;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
