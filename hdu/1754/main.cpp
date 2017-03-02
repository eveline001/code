#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int Max[2000000 << 2];

void PushUp(int rt){
    Max[rt] = max(Max[rt << 1], Max[(rt << 1) | 1]);
}

void BuildUp(int l, int r, int rt){
    if(l == r){
        scanf("%d", &Max[rt]);
        return;
    }
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, (rt << 1) | 1);
    PushUp(rt);
}

void Update(int p, int x, int l, int r, int rt){
    if(p == l && l == r){
        Max[rt] = x;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid){
        Update(p, x, l, mid, rt << 1);
    }else{
        Update(p, x, mid + 1, r, (rt << 1) | 1);
    }
    PushUp(rt);
}

int Search(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
        return Max[rt];
    }
    int mid = (l + r) >> 1;
    if(R <= mid){
        return Search(L, R, l, mid, rt << 1);
    }else if(L > mid){
        return Search(L, R, mid + 1, r, (rt << 1) | 1);
    }else{
        return max(Search(L, R, l, mid, rt << 1), Search(L, R, mid + 1, r, (rt << 1 | 1)));
    }

}

int main()
{
    int n, m, a, b;
    char op[2];

    while(scanf("%d%d", &n, &m) != EOF){
        BuildUp(1, n, 1);
        for(int i = 0; i < m; i++){
            scanf("%s%d%d", op, &a, &b);
            if(op[0] == 'U'){
                Update(a, b, 1, n, 1);
            }else{
                printf("%d\n", Search(a, b, 1, n, 1));
            }
        }
    }
}
