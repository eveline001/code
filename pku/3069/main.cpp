#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int p[1007];

int main()
{
    int R, n, ans, r;

    while(scanf("%d%d", &R, &n) != EOF && (~R || ~n)){
        memset(p, 0, sizeof(p));
        for(int i = 0; i < n; i++) scanf("%d", &p[i]);
        sort(p, p + n);
        ans = 0;
        for(int i = 0; i < n;){
            r = p[i] + R;
            for(; i < n && p[i] <= r; i++);
            r = p[i - 1] + R;
            for(; i < n && p[i] <= r; i++);
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
