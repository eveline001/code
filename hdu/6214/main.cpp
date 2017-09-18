#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAXN = 200;
const int MAXM = 1000;
const int minE = (MAXM << 1) + 7;

struct Edge{
    int to, cap, next;
};

Edge Edges[MAXM << 1 | 1];
int head[MAXN + 1], cnt;

int d[MAXN + 1], q[MAXN + 1];

void MaxFlowInit(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}

bool MaxFlowBfs(int s, int t){
    int rear = 0;
    memset(d, -1, sizeof(d));
    d[s] = 0, q[rear++] = s;
    for(int i = 0; i < rear; i++){
        for(int j = head[q[i]]; ~j; j = Edges[j].next){
            Edge& e = Edges[j];
            if(e.cap && d[e.to] == -1){
                d[e.to] = d[q[i]] + 1;
                q[rear++] = e.to;
                if(e.to == t) return 1;
            }
        }
    }
    return 0;
}

int MaxFlowDfs(int s, int t, int cur,int maxflow){
    if(cur == t) return maxflow;
    for(int i = head[cur]; ~i; i = Edges[i].next){
        Edge& e = Edges[i];
        if(e.cap && d[e.to] == d[cur] + 1)
            if(int det = MaxFlowDfs(s, t, e.to, min(maxflow, e.cap))){
                e.cap -= det, Edges[i ^ 1].cap += det;
                return det;
            }
    }
    return 0;
}

int MaxFlowDinic(int s, int t){
    int flow = 0;
    while(MaxFlowBfs(s, t)) flow += MaxFlowDfs(s, t, s, INF);
    return flow;
}

void AddEdge(int u, int v, int c){
    Edges[cnt].to = v, Edges[cnt].cap = c, Edges[cnt].next = head[u], head[u] = cnt++;
    Edges[cnt].to = u, Edges[cnt].cap = 0, Edges[cnt].next = head[v], head[v] = cnt++;
}

int main()
{
    int T, n, m, s, t;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        MaxFlowInit();
        scanf("%d%d%d%d", &n, &m, &s, &t);
        for(int i = 0, u, v, w; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            AddEdge(u, v, w * minE + 1);
        }
        printf("%d\n", MaxFlowDinic(s, t) % minE);
    }
    return 0;
}
