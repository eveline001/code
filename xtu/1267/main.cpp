#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 2e5 + 7;

struct Edge{
    int to, next, w;
};

Edge E[MAXN];
int head[MAXN], cnt;
bool vis[MAXN];
long long dis[2][MAXN];

int BFS(long long dis[], int x){
    queue<int> Q;
    long long maxdis;
    int maxpos;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, MAXN * sizeof(long long));
    Q.push(x);
    maxdis = 0, maxpos = 1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        vis[u] = true;
        for(int i = head[u]; ~i; i = E[i].next){
            int v = E[i].to;
            if(!vis[v]){
                Q.push(v);
                dis[v] = dis[u] + E[i].w;
                if(dis[v] > maxdis) maxdis = dis[v], maxpos = v;
            }
        }
    }
    return maxpos;
}

int main()
{
    int n, u, v, w;

    while(scanf("%d", &n) != EOF){
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &w);
            E[cnt].to = v, E[cnt].next = head[u], E[cnt].w = w, head[u] = cnt++;
            E[cnt].to = u, E[cnt].next = head[v], E[cnt].w = w, head[v] = cnt++;
        }
        u = BFS(dis[0], 1);
        v = BFS(dis[0], u);
        BFS(dis[1], v);
        long long ans = dis[0][v];
        for(int i = 1; i <= n; i++){
            if(i == u || i == v) continue;
            ans += max(dis[0][i], dis[1][i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
