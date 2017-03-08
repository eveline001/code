#include<bits/stdc++.h>

using namespace std;

char g[10][10];
long long a[10][10], b[10][10];

long long Gauss(int n){/* 高斯消元求行列式的值  用到了逆元把除法变乘法 避免精度问题 */
    if(n == 0){
        return 1;
    }
    long long ret = 1;
    int flag = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            while(a[j][i]){
                long long tmp = a[i][i] / a[j][i];
                for(int k = i; k <= n; k++){
                    a[i][k] -= a[j][k] * tmp;
                }
                swap(a[i], a[j]), flag *= -1;
            }
        }
        if(!a[i][i]){
            return 0;
        }
        ret *= a[i][i];
    }
    return flag == -1 ? -ret : ret;
}

void change(int x, int n){ /* 去掉第x行x列 */
    memset(a, 0, sizeof(a));
    int row = 1;
    for(int i = 1; i <= n; i++){
        int col = 1;
        if(i == x){
            continue;
        }
        for(int j = 1;j <= n;j++){
            if(j != x){
                a[row][col++] = b[i][j];
            }
        }
        row++;
    }
    return;
}

int main()
{
    int n;

    while(scanf("%d", &n) != EOF && n){
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++){
            scanf("%s", g[i] + 1);
            for(int j = 1; j <= n; j++){
                if(i != j && g[i][j] == '1'){
                    a[i][j]--, a[j][j]++;
                }
            }
        }
        memcpy(b, a, sizeof(b));
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            change(i, n);
            ans += Gauss(n - 1);
            memcpy(a, b, sizeof(b));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
