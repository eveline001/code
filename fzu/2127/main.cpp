#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, al, ah, bl, bh, cl, ch, h, l;
    long long ans;

    while(scanf("%d", &n) != EOF){
        ans = 0;
        scanf("%d%d%d%d%d%d", &al, &ah, &bl, &bh, &cl, &ch);
        for(int a1 = max(1, al); a1 <= ah && a1 <= n / 3; a1++){
            h = min(min(min(bh, (n - a1) >> 1), (n - a1) >> 1), n - a1 - cl);
            l = max(max(max(bl, a1), (n + 2 - 2 * a1) >> 1), n - a1 - ch);
            if(h - l >= 0){
                ans += h - l + 1;
            }
        }
        printf("%I64d\n", ans);
    }
}

/*
                    a2 >= max(bl, a1)
                    a2 >= (n + 2 - 2 * a1) >> 1
                    a2 >= n - a1 - ch
min(bh, (n - a1) >> 1) >= a2
         (n - a1) >> 1 >= a2
           n - a1 - cl >= a2

*/
