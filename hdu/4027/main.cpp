#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct Node{
    long long sum[8];
    int add, cnt;
};

Node Tree[100000 << 2];

void PushUp(int rt){
    for(int i = 0; i < 8; i++){
        Tree[rt].sum[i] = Tree[rt << 1].sum[i] + Tree[rt << 1 | 1].sum[i];
    }
}

void BuildUp(int l, int r, int rt){
    Tree[rt].add = Tree[rt].cnt = 0;
    if(l == r){
        scanf("%I64d", &Tree[rt].sum[0]);
        if(Tree[rt].sum[0] == 0){
            for(int i = 1; i < 8; i++){
                Tree[rt].sum[i] = 0;
            }
        }else{
            for(int i = 1; i < 8; i++){
                Tree[rt].sum[i] = 1;
            }
            for(int i = 1; Tree[rt].sum[i - 1] > 1 && i < 8; i++){
                Tree[rt].sum[i] = sqrt((double)Tree[rt].sum[i - 1]);
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, rt << 1 | 1);
    PushUp(rt);
}

void PushDown(int rt){
    if(Tree[rt].add){
        Tree[rt << 1].cnt += Tree[rt].add;
        Tree[rt << 1].add += Tree[rt].add;
        Tree[rt << 1 | 1].cnt += Tree[rt].add;
        Tree[rt << 1 | 1].add += Tree[rt].add;
        Tree[rt].add = 0;
    }
}

void Update(int L, int R, int l, int r, int rt){
    if(l == r && l >= L && r <= R){
        if(Tree[rt].cnt < 7){
            Tree[rt].cnt++;
        }
        return;
    }
    if(l >= L && r <= R){
        Tree[rt].add++;
        Tree[rt].cnt++;
        return;
    }
    PushDown(rt);
    int mid = (l + r) >> 1;
    if(L <= mid){
        Update(L, R, l, mid, rt << 1);
    }
    if(R > mid){
        Update(L, R, mid + 1, r, rt << 1 | 1);
    }
}

long long Querry(int L, int R, int l, int r, int rt){
    if(l >= L && r <= R){
        if(Tree[rt].cnt > 7){
            Tree[rt].cnt = 7;
        }
        if(Tree[rt].cnt == 7 || l == r || Tree[rt].sum[Tree[rt].cnt] == 0){
            return Tree[rt].sum[Tree[rt].cnt];
        }
    }
    PushDown(rt);
    int mid = (l + r) >> 1;
    long long res = 0;
    if(L <= mid){
        res += Querry(L, R, l, mid, rt << 1);
    }
    if( R > mid){
        res += Querry(L, R, mid + 1, r, rt << 1 | 1);
    }
    return res;
}

int main()
{
    int N, M, cas = 1, T, X, Y;

    while(scanf("%d", &N) != EOF){
        printf("Case #%d:\n", cas++);
        BuildUp(1, N, 1);
        scanf("%d", &M);
        for(int i = 0; i < M; i++){
            scanf("%d%d%d", &T, &X, &Y);
            if(X > Y){
                swap(X, Y);
            }
            if(T == 0){
                Update(X, Y, 1, N, 1);
            }else{
                printf("%I64d\n", Querry(X, Y, 1, N, 1));
            }
        }
        printf("\n");
    }
    return 0;
}
