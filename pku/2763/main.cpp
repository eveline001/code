#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 100001;

struct Edge{
    int to, next;
};

Edge Edges[MAX << 1];
int head[MAX];
int cnt;
int Road[MAX][3];
int fa[MAX], sz[MAX], de[MAX], sn[MAX], tp[MAX], id[MAX];
int val[MAX];
int sum[MAX << 2];
int tol;

void DfsTree(int x, int father, int deep){
    fa[x] = father, de[x] = deep, sz[x] = 1, sn[x] = 0;
    for(int i = head[x]; ~i; i = Edges[i].next){
        int v = Edges[i].to;
        if(v != father){
            DfsTree(v, x, deep + 1);
            sz[x] += sz[v];
            if(sz[v] > sz[sn[x]]){
                sn[x] = v;
            }
        }
    }
    return;
}

void DfsChain(int x, int top){
    tp[x] = top;
    id[x] = ++tol;
    if(sn[x]){
        DfsChain(sn[x], top);
        for(int i = head[x]; ~i; i = Edges[i].next){
            int v = Edges[i].to;
            if(v != sn[x] && v != fa[x]){
                DfsChain(v, v);
            }
        }
    }
    return;
}

void PushUp(int rt){
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    return;
}

void BuildUp(int l, int r, int rt){
    if(l == r){
        sum[rt] = val[l];
        return;
    }
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, rt << 1 | 1);
    PushUp(rt);
    return;
}

void Update(int pos, int val, int l, int r, int rt){
    if(l == r && l == pos){
        sum[rt] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid){
        Update(pos, val, l, mid, rt << 1);
    }else{
        Update(pos, val, mid + 1, r, rt << 1 | 1);
    }
    PushUp(rt);
    return;
}

int Query(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
        return sum[rt];
    }
    int mid = (l + r) >> 1, res = 0;
    if(L <= mid){
        res += Query(L, R, l, mid, rt << 1);
    }
    if(R > mid){
        res += Query(L, R, mid + 1, r, rt << 1 | 1);
    }
    return res;
}

int ChainQuery(int a, int b, int n){
    if(a == b){
        return 0;
    }
    if(tp[a] == tp[b]){
        if(id[a] > id[b]){
            return Query(id[b] + 1, id[a], 2, n, 1);
        }else{
            return Query(id[a] + 1, id[b], 2, n, 1);
        }
    }
    if(tp[a] < tp[b]){
        return Query(id[tp[b]], id[b], 2, n, 1) + ChainQuery(a, fa[b], n);
    }else{
        return Query(id[tp[a]], id[a], 2, n, 1) + ChainQuery(fa[a], b, n);
    }
}

int main()
{
    int n, q, s, u, v, w, op;

    while(scanf("%d%d%d", &n, &q, &s) != EOF){
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &w);
            Edges[cnt].to = v, Edges[cnt].next = head[u], head[u] = cnt++;
            Edges[cnt].to = u, Edges[cnt].next = head[v], head[v] = cnt++;
            Road[i][0] = u, Road[i][1] = v, Road[i][2] = w;
        }
        tol = 0;
        DfsTree(1, 1, 0);
        DfsChain(1, 1);
        for(int i = 1; i < n; i++){
            if(de[Road[i][0]] < de[Road[i][1]]){
                swap(Road[i][0], Road[i][1]);
            }
            val[id[Road[i][0]]] = Road[i][2];
        }
        BuildUp(2, n, 1);
        for(int i = 0; i < q; i++){
            scanf("%d", &op);
            if(op == 0){
                scanf("%d", &u);
                printf("%d\n", ChainQuery(s, u, n));
                s = u;
            }else if(op == 1){
                scanf("%d%d", &v, &w);
                Update(id[Road[v][0]], w, 2, n, 1);
            }
        }
    }
    return 0;
}
