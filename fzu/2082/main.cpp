#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 5e4 + 7;

int fa[MAX], de[MAX], sz[MAX], sn[MAX], tp[MAX], id[MAX];
int val[MAX], head[MAX], Road[MAX][3];
int n, tol;

struct Edge{
    int to, next;
};

Edge Edges[MAX << 1];
int cnt;

void DfsTree(int x, int father, int deep){
    fa[x] = father, de[x] = deep, sz[x] = 1, sn[x] = 0;
    for(int i = head[x]; ~i; i = Edges[i].next){
        int v = Edges[i].to;
        if(v != father){
            DfsTree(v, x, deep + 1);
            sz[x] += sz[v];
            if(sz[sn[x]] < sz[v]) sn[x] = v;
        }
    }
}

void DfsChain(int x, int top){
    id[x] = ++tol, tp[x] = top;
    if(sn[x]){
        DfsChain(sn[x], top);
        for(int i = head[x]; ~i; i = Edges[i].next){
            int v = Edges[i].to;
            if(v != fa[x] && v != sn[x]) DfsChain(v, v);
        }
    }
}

long long Sum[MAX << 2];

void PushUp(int rt){
    Sum[rt] = Sum[rt << 1] + Sum[rt << 1 | 1];
}

void BuildUp(int l, int r, int rt){
    if(l == r){
        Sum[rt] = val[l];
        return;
    }
    Sum[rt] = 0;
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, rt << 1 | 1);
    PushUp(rt);
}

void Update(int pos, int v, int l, int r, int rt){
    if(l == r){
        if(l == pos) Sum[rt] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) Update(pos, v, l, mid, rt << 1);
    else Update(pos, v, mid + 1, r, rt << 1 | 1);
    PushUp(rt);
}

long long Query(int L, int R, int l, int r, int rt){
    long long res = 0;
    if(L <= l && R >= r) return Sum[rt];
    int mid = (l + r) >> 1;
    if(L <= mid) res += Query(L, R, l, mid, rt << 1);
    if(R > mid) res += Query(L, R, mid + 1, r, rt << 1 | 1);
    return res;
}

void ChainUpdate(int u, int v){
    Update(id[u], v, 1, n, 1);
}

long long ChainQuery(int u, int v){
    if(tp[u] != tp[v]){
        if(de[tp[u]] > de[tp[v]]) return Query(id[tp[u]], id[u], 1, n, 1) + ChainQuery(fa[tp[u]], v);
        else return Query(id[tp[v]], id[v], 1, n, 1) + ChainQuery(u, fa[tp[v]]);
    }
    if(u == v) return 0;
    if(de[u] > de[v]) return Query(id[v] + 1, id[u], 1, n, 1);
    else return Query(id[u] + 1, id[v], 1, n, 1);
}

int main()
{
    int m, u, v, c;

    while(scanf("%d%d", &n, &m) != EOF){
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &c);
            Edges[cnt].to = u, Edges[cnt].next = head[v], head[v] = cnt++;
            Edges[cnt].to = v, Edges[cnt].next = head[u], head[u] = cnt++;
            Road[i][0] = u, Road[i][1] = v, Road[i][2] = c;
        }
        tol = 0;
        DfsTree(1, 1, 0);
        DfsChain(1, 1);
        for(int i = 1; i < n; i++){
            if(de[Road[i][0]] < de[Road[i][1]]) swap(Road[i][0], Road[i][1]);
            val[id[Road[i][0]]] = Road[i][2];
        }
        BuildUp(1, n, 1);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &c, &u, &v);
            if(c == 0){
                ChainUpdate(Road[u][0], v);
            }else if(c == 1){
                printf("%I64d\n", ChainQuery(u, v));
            }
        }
    }
    return 0;
}
