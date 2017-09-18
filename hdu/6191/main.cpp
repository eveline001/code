#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 10;

struct Edge{
    int to, next;
};

Edge Edges[MAXN];
int head[MAXN], cnt;

int id[MAXN], rk[MAXN], st[MAXN], ed[MAXN];

void Dfs(int x){
    id[x] = ++cnt, rk[cnt] = x, st[x] = cnt;
    for(int i = head[x]; ~i; i = Edges[i].next) Dfs(Edges[i].to);
    ed[x] = cnt;
}

int v[MAXN];

int main()
{
    int n, q;

    while(scanf("%d%d", &n, &q) != EOF){
        for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 2, f; i <= n; i++){
            scanf("%d", &f);
            Edges[cnt].to = i, Edges[cnt].next = head[f], head[f] = cnt++;
        }
        cnt = 0;
        Dfs(1);
        for(int i = 0, u, x; i < q; i++){
            scanf("%d%d", &u, &x);
            int ans = x ^ v[rk[st[u]]];
            for(int i = st[u] + 1; i <= ed[u]; i++){
                int res = x ^ v[rk[i]];
                if(res > ans) ans = res;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
