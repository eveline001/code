#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 2e5 + 7;

struct Edge{
    int to, next;
};

Edge E[MAXN << 2];
int head[MAXN], cnt;

long long color[MAXN], sum[MAXN], sz[MAXN];
bool vis[MAXN];
long long ans;
int tol;

long long dfs(int x, int fa){
    long long all, pre, det;
    sz[x] = 1, all = 0;
    for(int i = head[x]; ~i; i = E[i].next){
        int v = E[i].to;
        if(v != fa){
            pre = sum[color[x]];
            sz[x] += dfs(v, x);
            det = sum[color[x]] - pre;
            ans += (sz[v] - det) * (sz[v] - det - 1) / 2;
            all += sz[v] - det;
        }
    }
    sum[color[x]] += all + 1;
    return sz[x];
}

int main()
{
    int u, v, cas = 1;;
    long long n;

    while(scanf("%I64d", &n) != EOF){
        tol = 0;
        memset(sum, 0, sizeof(sum));
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++){
            scanf("%I64d", &color[i]);
            if(!vis[color[i]]) tol++, vis[color[i]] = true;
        }
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 0; i < n - 1; i++){
            scanf("%d%d", &u, &v);
            E[cnt].to = v, E[cnt].next = head[u], head[u] = cnt++;
            E[cnt].to = u, E[cnt].next = head[v], head[v] = cnt++;
        }
        printf("Case #%d: ", cas++);
        if(tol == 1) printf("%I64d\n", n * (n - 1) / 2);
        else{
            ans = 0;
            dfs(1, 0);
            for(int i = 1; i <= n; i++) if(vis[i]) ans += (n - sum[i]) * (n - sum[i] - 1) / 2;
            printf("%I64d\n", n * (n - 1) / 2 * tol - ans);
        }
    }
    return 0;
}
