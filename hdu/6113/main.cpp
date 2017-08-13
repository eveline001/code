#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
char s[101][102];
bool vis[101][101];
int v[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int dfs(int X, int Y){
    int res = 1;
    for(int i = 0; i < 4; i++){
        int x = X + v[i][0], y = Y + v[i][1];
        if(x >= 1 && x <= n && y >= 1 && y <= m){
            if(!vis[x][y] && s[x][y] == s[X][Y]){
                vis[x][y] = true;
                res &= dfs(x, y);
            }
        }else if(s[X][Y] == '0') res = 0;
    }
    return res;
}

int main()
{
    int cnt[2], ans;

    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
        memset(vis, false, sizeof(vis));
        cnt[0] = cnt[1] = ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!vis[i][j]){
                    vis[i][j] = true;
                    cnt[s[i][j] - '0'] += dfs(i, j);
                    if(cnt[1] > 1 || cnt[0] > 1){ans = -1; break;}
                }
            }
            if(!~ans) break;
        }
        if(~ans) ans = cnt[1] == 1 ? cnt[0] == 0 ? 1 : cnt[0] == 1 ? 0 : -1 : -1;
        printf("%d\n", ans);
    }
    return 0;
}
