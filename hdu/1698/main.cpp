#include <iostream>
#include <cstdio>

using namespace std;

int Sum[100000 << 2];
int Set[100000 << 2];

void PushUp(int rt){
    Sum[rt] = Sum[rt << 1] + Sum[(rt << 1) | 1];
}

void PushDown(int l, int r, int rt){
    if(Set[rt]){
        Set[rt << 1] = Set[(rt << 1) | 1] = Set[rt];
        int mid = (l + r) >> 1;
        Sum[rt << 1] = (mid - l + 1) * Set[rt];
        Sum[(rt << 1) | 1] = (r - mid) * Set[rt];
        Set[rt] = 0;
    }
}

void BuildUp(int l, int r, int rt){
    Set[rt] = 0;
    if(l == r){
        Sum[rt] = 1;
        return;
    }
    Sum[rt] = r - l + 1;
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, (rt << 1) | 1);
}

void Update(int L, int R, int x, int l, int r, int rt){
    if(L <= l && R >= r){
        Sum[rt] = (r - l + 1) * x;
        Set[rt] = x;
        return;
    }
    PushDown(l, r, rt);
    int mid = (l + r) >> 1;
    if(L <= mid){
        Update(L, R, x, l, mid, rt << 1);
    }
    if(R >= mid + 1){
        Update(L, R, x, mid + 1, r, (rt << 1) | 1);
    }
    PushUp(rt);
}

int main()
{
    int T, n, q, L, R, x;

    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d", &n);
        BuildUp(1, n, 1);
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d%d%d", &L, &R, &x);
            Update(L, R, x, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", t, Set[1] == 0 ? Sum[1] : Set[1] * n);
    }
}
