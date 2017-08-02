#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, a, b, h[16], d[16], ans0 = 0, ans1 = 0x7fffffff;
bool dead[16];

void dfs(int pos, int curtimes){
    if(pos == n){ans1 = min(ans1, curtimes); return;}
    int mintimes, maxtimes;
    if(h[pos - 1] < 0) dfs(pos + 1, curtimes);
    mintimes = 0;
    if(h[pos - 1] >= 0){
        mintimes = h[pos - 1] / b + 1;
        h[pos - 1] -= mintimes * b;
        h[pos] -= mintimes * a;
        h[pos + 1] -= mintimes * b;
        dfs(pos + 1, curtimes + mintimes);
        h[pos - 1] += mintimes * b;
        h[pos] += mintimes * a;
        h[pos + 1] += mintimes * b;
    }
    maxtimes = h[pos] / a + 1;
    if(h[pos] >= 0 && maxtimes > mintimes){
        for(int times = mintimes + 1; times <= maxtimes; times++){
            h[pos - 1] -= times * b;
            h[pos] -= times * a;
            h[pos + 1] -= times * b;
            dfs(pos + 1, curtimes + times);
            h[pos - 1] += times * b;
            h[pos] += times * a;
            h[pos + 1] += times * b;
        }
    }
}

int main()
{
    int times;

    scanf("%d%d%d", &n, &a, &b);
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
    times = h[1] / b + 1;
    h[1] -= times * b;
    h[2] -= times * a;
    h[3] -= times * b;
    ans0 += times;
    if(h[n] >= 0) times = h[n] / b + 1;
    else times = 0;
    h[n] -= times * b;
    h[n - 1] -= times * a;
    h[n - 2] -= times * b;
    ans0 += times;
    dfs(2, 0);
    if(ans1 == 0x7fffffff) ans1 = 0;
    printf("%d\n", ans0 + ans1);
    return 0;
}
