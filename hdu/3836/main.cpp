#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Edge{
    int to, next;
};

Edge Edges[50010];
int head[20010], Low[20010], Dfn[20010], Stk[20010], mark[20010], indgree[20010], outdgree[20010];
bool vis[20010], inStk[20010];
int cnt, index, top, cntSCC;

void Tarjan(int u) {
    Low[u] = Dfn[u] = ++index;
    Stk[top++] = u, vis[u] = true, inStk[u] = true;

    for (int i = head[u]; ~i; i = Edges[i].next) {
        int v = Edges[i].to;
        if (!vis[v]) {
            Tarjan(v);
            Low[u] = min(Low[u], Low[v]);
        } else if (inStk[v]) {
            Low[u] = min(Low[u], Dfn[v]);
        }
    }
    if (Dfn[u] == Low[u]) {
        int v;
        cntSCC++;
        do {
            v = Stk[top - 1];
            mark[v] = cntSCC;
            top--;
            inStk[v] = false;
        } while (u != v);
    }
}

int main()
{
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF) {
        cnt = 0;
        memset(head, -1, sizeof(head));
        memset(vis, false, sizeof(vis));
        memset(inStk, false, sizeof(inStk));
        memset(mark, 0, sizeof(mark));
        memset(indgree, 0, sizeof(indgree));
        memset(outdgree, 0, sizeof(outdgree));
        for (int i = 0, u, v; i < m; i++) {
            scanf("%d%d", &u, &v);
            Edges[cnt].to = v, Edges[cnt].next = head[u], head[u] = cnt++;
        }
        index = 0, top = 0, cntSCC = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) Tarjan(i);
        }
        for (int u = 1; u <= n; u++) {
            for (int i = head[u]; ~i; i = Edges[i].next) {
                int v = Edges[i].to;
                if (mark[u] != mark[v]) indgree[mark[v]]++, outdgree[mark[u]]++;
            }
        }
        int cntIn = 0, cntOut = 0;
        for (int i = 1; i <= cntSCC; i++) {
            if (indgree[i] == 0) cntIn++;
            if (outdgree[i] == 0) cntOut++;
        }
        if (cntSCC == 1) printf("0\n");
        else printf("%d\n", max(cntIn, cntOut));
    }

    return 0;
}
