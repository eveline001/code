#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T, x, y, a, b, num, ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d%d", &x, &y, &a, &b);
        if(x == 1 || y == 1 || (x == 2 && y == 2 && (a + b >= 3))){printf("INF\n");continue;}
        ans = 0;
        while(a >= x || b >= y){
            if(a >= x) num = a / x, a %= x, ans += num, a += num, b += num;
            if(b >= y) num = b / y, b %= y, ans += num, a += num, b += num;
        }
        printf("%d\n", ans);
    }
    return 0;
}