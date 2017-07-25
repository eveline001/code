#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAXN = 200;

struct Edge{
    int to, cap, rev;

    Edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
    Edge() {}
};

vector<Edge> E[MAXN << 1 | 1];

bool vis[MAXN];

int Dfs(int s, int t, int flow){
    if(s == t) return flow;
    vis[s] = true;
    for(int i = 0; i < E[s].size(); i++){
        Edge& e = E[s][i];
        if(!vis[e.to] && e.cap > 0){
            int det = Dfs(e.to, t, min(flow, e.cap));
            if(det > 0){
                e.cap  -= det;
                E[e.to][e.rev].cap += det;
                return det;
            }
        }
    }
    return 0;
}

int MaxFlow(int s, int t){
    int flow = 0;
    for(;;){
        memset(vis, false, sizeof(vis));
        int det = Dfs(s, t, INF);
        if(det == 0) return flow;
        flow += det;
    }
    return flow;
}

void AddEdge(int u, int v, int c){
    E[u].push_back(Edge(v, c, E[v].size()));
    E[v].push_back(Edge(u, 0, E[u].size() - 1));
}

int main()
{
    int n, m, u, v, c;

    while(scanf("%d%d", &m, &n) != EOF){
        for(int i = 1; i < n; i++) E[i].clear();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &c);
            E[u].push_back(Edge(v, c, E[v].size()));
            E[v].push_back(Edge(u, 0, E[u].size() - 1));
        }
        printf("%d\n", MaxFlow(1, n));
    }
    return 0;
}
