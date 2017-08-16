#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int Ori[1001][1001], Sum[1001];

int main()
{
    int T, m, n, x, y, cur, ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d%d", &m, &n, &x, &y);
        memset(Sum, 0, sizeof(Sum));
        ans = 0;
        for(int i = 1; i <= m; i++){
            cur = 0;
            for(int j = 1; j <= n; j++){
                scanf("%d", &Ori[i][j]);
                Sum[j] += Ori[i][j];
                if(i > x) Sum[j] -= Ori[i - x][j];
                cur += Sum[j];
                if(j > y) cur -= Sum[j - y];
                if(cur > ans) ans = cur;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
