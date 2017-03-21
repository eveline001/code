#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int MAX = 1e4 + 7;

int n;

int fa[MAX], sz[MAX], de[MAX], sn[MAX], tp[MAX], id[MAX];
int Max[MAX << 2], Min[MAX << 2], Mul[MAX << 2];
int val[MAX], Road[MAX][3];
int tol;
vector<int> Edge[MAX];

void DfsTree(int x, int father, int deep = 0){
    fa[x] = father, de[x] = deep, sz[x] = 1, sn[x] = 0;
    for(int v : Edge[x]){
        if(v != father){
            DfsTree(v, x, deep + 1);
            sz[x] += sz[v];
            if(sz[v] > sz[sn[x]]) sn[x] = v;
        }
    }
    return;
}

void DfsChain(int x, int top){
    tp[x] = top;
    id[x] = ++tol;
    if(sn[x]){
        DfsChain(sn[x], top);
        for(int v : Edge[x]){
            if(v != fa[x] && v != sn[x]){
                DfsChain(v, v);
            }
        }
    }
    return;
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
    return;
}

void PushDown(int rt){
    if(Mul[rt] != 1){
        int temp;
        temp = Max[rt << 1];
        Mul[rt << 1] *= Mul[rt];
        Max[rt << 1] = -Min[rt << 1];
        Min[rt << 1] = -temp;
        temp = Max[rt << 1 | 1];
        Mul[rt << 1 | 1] *= Mul[rt];
        Max[rt << 1 | 1] = -Min[rt << 1 | 1];
        Min[rt << 1 | 1] = -temp;
    }
    return;
}

void Update(int L, int R, int v, int l, int r, int rt){
}

int Query(int L, int R, int l, int r, int rt){
}

void ChainUpdate(int u, int v, int val){
}

int ChainQuery(int u, int v){
}

int main()
{
    int T, n, u, v, c;
    char op[7];

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &c);
            Edge[u].push_back(v);
            Edge[v].push_back(u);
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

            }else if(op[0] == 'C'){

            }else if(op[0] == 'N'){

            }
        }
    }
}
