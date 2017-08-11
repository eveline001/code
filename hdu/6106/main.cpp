#include <iostream>
#include <cstdio>

using namespace std;

int Count(int A, int B, int C, int AB, int BC, int AC, int ABC){
    if(A < AB + AC - ABC
       || B < AB + BC - ABC
       || C < AC + BC - ABC
       || AB < ABC || AC < ABC || BC < ABC) return 0;
    return A + B + C - AB - AC - BC + ABC;
}

int main()
{
    int T, n, a, b, c, d, e, f, g, ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
            ans = max(ans, Count(a, b, c, d, e, f, g));
        }
        printf("%d\n", ans);
    }
    return 0;
}
