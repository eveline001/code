#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 50000 + 7;

int camp[MAX];
vector<int> Edge[MAX];
int fa[MAX], sz[MAX], sn[MAX], de[MAX], id[MAX], rk[MAX], tp[MAX];
int sum[MAX << 2], add[MAX << 2];
int tol = 0;

void DfsTree(int x, int father, int deep){
    fa[x] = father, sz[x] = 1, sn[x] = 0, de[x] = deep;
    for(int v : Edge[x]){
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
    rk[tol] = x;
    if(sn[x]){
        DfsChain(sn[x], top);
        for(int v : Edge[x]){
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

void PushDown(int l, int r, int rt){
    if(add[rt]){
        int mid = (l + r) >> 1;
        add[rt << 1] += add[rt];
        sum[rt << 1] += (mid - l + 1) * add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1 | 1] += (r - mid) * add[rt];
        add[rt] = 0;
    }
    return;
}

void BuildUp(int l, int r, int rt){
    add[rt] = 0;
    if(l == r){
        sum[rt] = camp[rk[l]];
        return;
    }
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, rt << 1 | 1);
    PushUp(rt);
    return;
}

void Update(int L, int R, int v, int l, int r, int rt){
    if(L <= l && R >= r){
        sum[rt] += (r - l + 1) * v;
        add[rt] += v;
        return;
    }
    PushDown(l, r, rt);
    int mid = (l + r) >> 1;
    if(L <= mid){
        Update(L, R, v, l, mid, rt << 1);
    }
    if(R > mid){
        Update(L, R, v, mid + 1, r, rt << 1 | 1);
    }
    PushUp(rt);
    return;
}

int Query(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
        return sum[rt];
    }
    PushDown(l, r, rt);
    int mid = (l + r) >> 1, res = 0;
    if(L <= mid){
        res += Query(L, R, l, mid, rt << 1);
    }
    if(R > mid){
        res += Query(L, R, mid + 1, r, rt << 1 | 1);
    }
    return res;
}

void ChainUpdate(int a, int b, int n, int v){
    int x, y;
    if(tp[a] == tp[b]){
        x = id[a], y = id[b];
        if(x > y){
            swap(x, y);
        }
        Update(x, y, v, 1, n, 1);
        return;
    }
    if(de[tp[a]] > de[tp[b]]){
        x = id[tp[a]], y = id[a];
        if(x > y){
            swap(x, y);
        }
        Update(x, y, v, 1, n, 1);
        ChainUpdate(fa[tp[a]], b, n, v);
    }else{
        x = id[tp[b]], y = id[b];
        if(x > y){
            swap(x, y);
        }
        Update(x, y, v, 1, n, 1);
        ChainUpdate(a, fa[tp[b]], n, v);
    }
}

int ChainQuery(int a, int b, int n){
    int x, y;
    if(tp[a] == tp[b]){
        x = id[a], y = id[b];
        if(x > y){
            swap(x, y);
        }
        return Query(x, y, 1, n, 1);
    }
    if(de[tp[a]] > de[tp[b]]){
        x = id[tp[a]], y = id[a];
        if(x > y){
            swap(x, y);
        }
        return Query(x, y, 1, n, 1) + ChainQuery(fa[tp[a]], b, n);
    }else{
        x = id[tp[b]], y = id[b];
        if(x > y){
            swap(x, y);
        }
        return Query(x, y, 1, n, 1) + ChainQuery(a, fa[tp[b]], n);
    }
}

int main()
{
    int n, m, p, u, v, c1, c2, k;
    char op[2];

    while(scanf("%d%d%d", &n, &m, &p) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d", &camp[i]);
            Edge[i].clear();
        }
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            Edge[u].push_back(v);
            Edge[v].push_back(u);
        }
        tol = 0;
        DfsTree(1, 1, 0);
        DfsChain(1, 1);
        BuildUp(1, n, 1);
        for(int i = 0; i < p; i++){
            scanf("%s", op);
            if(op[0] == 'I'){
                scanf("%d%d%d", &c1, &c2, &k);
                if(k != 0){
                    ChainUpdate(c1, c2, n, k);
                }
            }else if(op[0] == 'D'){
                scanf("%d%d%d", &c1, &c2, &k);
                if(k != 0){
                    ChainUpdate(c1, c2, n, -k);
                }
            }else if(op[0] == 'Q'){
                scanf("%d", &c1);
                printf("%d\n", ChainQuery(c1, c1, n));
            }
        }
    }
    return 0;
}
