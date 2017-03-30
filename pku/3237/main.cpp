#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1e4 + 7;

int n;

struct Edge{
    int to, next;
};

int fa[MAX], sz[MAX], de[MAX], sn[MAX], tp[MAX], id[MAX];
int Max[MAX << 2], Min[MAX << 2], Mul[MAX << 2];
int val[MAX], Road[MAX][3];
int tol;
int head[MAX];
Edge Edges[MAX << 1];
int cnt;

void DfsTree(int x, int father, int deep = 0){
    fa[x] = father, de[x] = deep, sz[x] = 1, sn[x] = 0;
    for(int i = head[x]; ~i; i = Edges[i].next){
        int v = Edges[i].to;
        if(v != father){
            DfsTree(v, x, deep + 1);
            sz[x] += sz[v];
            if(sz[v] > sz[sn[x]]) sn[x] = v;
        }
    }
}

void DfsChain(int x, int top){
    tp[x] = top;
    id[x] = ++tol;
    if(sn[x]){
        DfsChain(sn[x], top);
        for(int i = head[x]; ~i; i = Edges[i].next){
            int v = Edges[i].to;
            if(v != fa[x] && v != sn[x]){
                DfsChain(v, v);
            }
        }
    }
}

void PushUp(int rt){
    Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
    Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
}

void BuildUp(int l, int r, int rt){
    Mul[rt] = 1;
    if(l == r){
        Max[rt] = Min[rt] = val[l];
        return;
    }
    Max[rt] = Min[rt] = 0;
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, rt << 1 | 1);
    PushUp(rt);
}

void PushDown(int rt){
    if(Mul[rt] != 1){
        int temp;
        temp = Max[rt << 1];
        Mul[rt << 1] *= -1;
        Max[rt << 1] = -Min[rt << 1];
        Min[rt << 1] = -temp;
        temp = Max[rt << 1 | 1];
        Mul[rt << 1 | 1] *= -1;
        Max[rt << 1 | 1] = -Min[rt << 1 | 1];
        Min[rt << 1 | 1] = -temp;
    }
}

void Change(int p, int v, int l, int r, int rt){
    if(p == l && p == r){
        Max[rt] = Min[rt] = v;
        return;
    }
    int mid = (l + r) >> 1;
    PushDown(rt);
    if(p <= mid){
        Change(p, v, l, mid, rt << 1);
    }else{
        Change(p, v, mid + 1, r, rt << 1 | 1);
    }
    PushUp(rt);
}

void Negate(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
        int temp;
        Mul[rt] *= -1;
        temp = Max[rt];
        Max[rt] = -Min[rt];
        Min[rt] = -temp;
        return;
    }
    int mid = (l + r) >> 1;
    PushDown(rt);
    if(L <= mid){
        Negate(L, R, l, mid, rt << 1);
    }
    if(R > mid){
        Negate(L, R, mid + 1, r, rt << 1 | 1);
    }
    PushUp(rt);
}

int Query(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
        return Max[rt];
    }
    int mid = (l + r) >> 1;
    PushDown(rt);
    if(R <= mid){
        return Query(L, R, l, mid, rt << 1);
    }else if(L > mid){
        return Query(L, R, mid + 1, r, rt << 1 | 1);
    }else{
        return max(Query(L, R, l, mid, rt << 1), Query(L, R, mid + 1, r, rt << 1 | 1));
    }
}

void ChainNegate(int u, int v){
    if(u == v) return;
    if(tp[u] == tp[v]){
        if(id[u] > id[v]){
            Negate(id[sn[v]], id[u], 1, n, 1);
        }else{
            Negate(id[sn[v]], id[v], 1, n, 1);
        }
        return;
    }
    if(de[tp[u]] < de[tp[v]]){
        Negate(id[tp[v]], id[v], 1, n, 1);
        ChainNegate(u, fa[tp[v]]);
    }else{
        Negate(id[tp[u]], id[u], 1, n, 1);
        ChainNegate(fa[tp[u]], v);
    }
}

int ChainQuery(int u, int v){
    if(u == v) return 0;
    if(tp[u] == tp[v]){
        if(id[u] > id[v]){
            return Query(id[sn[v]], id[u], 1, n, 1);
        }else{
            return Query(id[sn[u]], id[v], 1, n, 1);
        }
    }
    if(de[tp[u]] < de[tp[v]]){
        return max(Query(id[tp[v]], id[v], 1, n, 1), ChainQuery(u, fa[tp[v]]));
    }else{
        return max(Query(id[tp[u]], id[u], 1, n, 1), ChainQuery(fa[tp[u]], v));
    }
}

int main()
{
    int T, u, v, c;
    char op[7];

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &c);
            Edges[cnt].to = v, Edges[cnt].next = head[u], head[u] = cnt++;
            Edges[cnt].to = u, Edges[cnt].next = head[v], head[v] = cnt++;
            Road[i][0] = u, Road[i][1] = v, Road[i][2] = c;
        }
        tol = 0;
        DfsTree(1, 1);
        DfsChain(1, 1);
        for(int i = 1; i < n; i++){
            if(de[Road[i][0]] < de[Road[i][1]]){
                swap(Road[i][0], Road[i][1]);
            }
            val[id[Road[i][0]]] = Road[i][2];
        }
        BuildUp(1, n, 1);
        while(scanf("%s", op) != EOF){
            if(op[0] == 'D') break;
            if(op[0] == 'Q'){
                scanf("%d%d", &u, &v);
                printf("%d\n", ChainQuery(u, v));
            }else if(op[0] == 'C'){
                scanf("%d%d", &u, &v);
                Change(id[Road[u][0]], v, 1, n, 1);
            }else if(op[0] == 'N'){
                ChainNegate(u, v);
            }
        }
    }
    return 0;
}
