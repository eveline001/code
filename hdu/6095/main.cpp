#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 7;

int a[MAXN];

int main()
{
    int T, n, K, ed, ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &n, &K);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        ed = a[n - 1], ans = 0;
        for(int i = n - 1; i >= 0; i--){
            if(a[i] < ed - K) break;
            ed = a[i], ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
