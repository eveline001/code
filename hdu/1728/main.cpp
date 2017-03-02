//old wrong
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

/*    3
   2     0
      1
*/

int m, n, k, x2, y2;

bool Bfs(int x, int y, int v, int w){
    if(y < 0 || y >= m || x < 0 || x >= n || M[y][x] == '*' || w > k || vis[y][x][w]){
        return false;
    }
    vis[y][x][w] = true;
    if(x == x2 && y == y2 && w <= k){
        return true;
    }
    bool res = false;
    for(int i = 0; i <= 3; i++){
        if(i == v){
            if(i == 0){
                res ||= Bfs(x, y + 1, v, w);
            }else if(i == 1){
                res ||= Bfs(x + 1, y, v, w);
            }else if(i == 2){
                res ||= Bfs(x, y - 1, v, w);
            }else{
                res ||= Bfs(x - 1, y, v, w);
            }
        }else{
            if(i == 0){
                res ||= Bfs(x, y + 1, v, w + 1);
            }else if(i == 1){
                res ||= Bfs(x + 1, y, v, w + 1);
            }else if(i == 2){
                res ||= Bfs(x, y - 1, v, w + 1);
            }else{
                res ||= Bfs(x - 1, y, v, w + 1);
            }
        }
    }
    return res;
}

char M[101][101];
bool vis[101][101][11];

int main()
{
    int T, x1, y1;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        memset(vis, false, sizeof(vis));
        scanf("%d%d", &m, &n);
        getchar();
        for(int i = 0; i < m; i++){
            gets(M[i]);
        }
        scanf("%d%d%d%d%d", &k, &x1, &y1, &x2, &y2);
        printf("%s\n", (Bfs(x1, y1, 0, 0) || Bfs(x1, y1, 1, 0) || Bfs(x1, y1, 2, 0) || Bfs(x1, y1, 3, 0)) ? "yes" : "no");
    }
}
