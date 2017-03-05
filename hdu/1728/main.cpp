#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

/*    3
   2     0
      1
*/
char M[101][101];
bool vis[101][101][11][4];

int m, n, k, x2, y2;

bool Bfs(int x, int y, int v, int w){
    if(y <= 0 || y > m || x <= 0 || x > n || M[y][x] == '*' || w > k){
        return false;
    }
    if(x == x2 && y == y2 && w <= k){
        return true;
    }
    for(int i = 0; i <= w; i++){
        if(vis[y][x][i][v]){
            return false;
        }
    }
    vis[y][x][w][v] = true;
    bool res = false;
    for(int i = 0; i <= 3; i++){
        if(i == v){
            if(i == 0){
                res = res || Bfs(x, y + 1, v, w);
            }else if(i == 1){
                res = res || Bfs(x + 1, y, v, w);
            }else if(i == 2){
                res = res || Bfs(x, y - 1, v, w);
            }else{
                res = res || Bfs(x - 1, y, v, w);
            }
        }else{
            if(i == 0){
                res = res || Bfs(x, y + 1, i, w + 1);
            }else if(i == 1){
                res = res || Bfs(x + 1, y, i, w + 1);
            }else if(i == 2){
                res = res || Bfs(x, y - 1, i, w + 1);
            }else{
                res = res || Bfs(x - 1, y, i, w + 1);
            }
        }
        if(res){
            return res;
        }
    }
    return res;
}

int main()
{
    int T, x1, y1;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        memset(vis, false, sizeof(vis));
        scanf("%d%d", &m, &n);
        getchar();
        for(int i = 1; i <= m; i++){
            gets(M[i] + 1);
        }
        scanf("%d%d%d%d%d", &k, &x1, &y1, &x2, &y2);
        printf("%s\n", (Bfs(x1, y1, 0, 0) || Bfs(x1, y1, 1, 0) || Bfs(x1, y1, 2, 0) || Bfs(x1, y1, 3, 0)) ? "yes" : "no");
    }
    return 0;
}
