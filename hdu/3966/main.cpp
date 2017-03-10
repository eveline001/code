#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1e5 + 7;

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
        sum[rt << 1] += (mid - l + r) * add[rt];
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
    int mid = ()
}

void ChainUpdate(int a, int b, int v){

}

void ChainQuery(int a, int b){
}

int main()
{
    int n, m, p, u, v, c, c1, c2, k;
    char op;

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
        DfsTree(1, 1, 0);
        DfsChain(1, 1);
        BuildUp(1, n, 1);
        for(int i = 0; i < p; i++){
            scanf("%c", &op);
            if(op == 'I'){
                scanf("%d%d%d", &c1, &c2, &k);
                ChainUpdate(c1, c2, k);

            }else if(op == 'D'){
                scanf("%d%d%d", &c1, &c2, &k);
                ChainUpdate(c1, c2, -k);
            }else if(op == 'Q'){
                scanf("%d", &c);
                ChainQuery(c, c);
            }
        }
    }
    return 0;
}
