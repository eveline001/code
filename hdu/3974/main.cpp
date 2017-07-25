#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int tol;
vector<int> Tree[50001];
int Fa[50001], Beg[50001], End[50001], Map[50001], ST[50000 << 2], DL[50000 << 2];

void Dfs(int x){
    Map[x] = Beg[x] = ++tol;
    for(int i = 0; i < Tree[x].size(); i++){
        Dfs(Tree[x][i]);
    }
    End[x] = tol;
}

void BuildUp(int l, int r, int rt){
    ST[rt] = -1;
    DL[rt] = 0;
    if(l == r){
        return;
    }
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, rt << 1 | 1);
}

void PushDown(int rt){
    if(DL[rt] != 0){
        ST[rt << 1] = ST[rt << 1 | 1] = ST[rt];
        DL[rt << 1] = DL[rt << 1 | 1] = DL[rt];
        DL[rt] = 0;
    }
}

void Update(int L, int R, int v, int l, int r, int rt){
    if(l >= L && r <= R){
        ST[rt] = v;
        DL[rt] = 1;
        return;
    }
    PushDown(rt);
    int mid = (l + r) >> 1;
    if(mid >= L){
        Update(L, R, v, l, mid, rt << 1);
    }
    if(mid < R){
        Update(L, R, v, mid + 1, r, rt << 1 | 1);
    }
}

int Query(int x, int l, int r, int rt){
    if(l == r && r == x){
        return ST[rt];
    }
    PushDown(rt);
    int mid = (l + r) >> 1;
    if(mid >= x){
        return Query(x, l, mid, rt << 1);
    }else{
        return Query(x, mid + 1, r, rt << 1 | 1);
    }
}

int main()
{
    int T, N, u, v, M, x, y;
    char C[6];

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        printf("Case #%d:\n", cas);
        scanf("%d", &N);
        for(int i = 1; i <= N; i++){
            Tree[i].clear();
        }
        memset(Fa, 0, sizeof(Fa));
        for(int i = 0; i < N - 1; i++){
            scanf("%d%d", &u, &v);
            Tree[v].push_back(u);
            Fa[u] = v;
        }
        tol = 0;
        for(int i = 1; i <= N; i++){
            if(Fa[i] == 0){
                Dfs(i);
                break;
            }
        }
        BuildUp(1, N, 1);
        scanf("%d", &M);
        for(int i = 0; i < M; i++){
            scanf(" %s%d", C, &x);
            if(C[0] == 'C'){
                printf("%d\n", Query(Map[x], 1, N, 1));
            }else{
                scanf("%d", &y);
                Update(Beg[x], End[x], y, 1, N, 1);
            }
        }
    }
    return 0;
}
