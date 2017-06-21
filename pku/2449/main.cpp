#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000 + 7;
const int INF = 0x3f3f3f;

int dis[MAXN];
bool vis[MAXN];

void Dijkstra(int st){
    for(int i = 0; i <= n; i++){
        dis[i] = INF;
        vis[i] = false;
    }

}

int cnt[MAXN];

int AStar(int st, int ed, int k){
    memset(cnt ,0, sizeof(cnt));

}

int main()
{
    int n, m;

    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i <= n; i++) E[i].clear();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &c);
            E[u].push_back(make_pair(v, c));
            E[v].push_back(make_pair(u, c));
        }
        scanf("%d%d%d", &st, &ed, &k);
        Dijkstra(ed);
        printf("%d\n", AStar(st, ed, k));
    }
    return 0;
}
