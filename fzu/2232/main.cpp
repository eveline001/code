//用 vector 存邻接表怎么 RE 了...
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int a[101][2], b[101][2];
bool e[101][101];

bool vis[101];
int result[101];

bool match(int x, int n){
    for(int i = 0; i < n; i++){
        if(e[x][i] && !vis[i]){
            vis[i] = true;
            if(result[i] == -1 || match(result[i], n)){
                result[i] = x;
                return true;
            }
        }
    }
    return false;
}

int hungary(int n){
    int res = 0;
    memset(result, -1, sizeof(result));
    for(int i = 0; i < n; i++){
        memset(vis, false, sizeof(vis));
        if(match(i, n)) res++;
    }
    return res;
}

int main()
{
    int T, n, ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d%d", &a[i][0], &a[i][1]);
        for(int i = 0; i < n; i++) scanf("%d%d", &b[i][0], &b[i][1]);
        memset(e, false, sizeof(e));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][1] >= b[j][0] && a[i][0] > b[j][1]) e[i][j] = true;
            }
        }
        ans = hungary(n);
        printf("%s\n", ans == n ? "Yes" :"No");
    }
    return 0;
}
