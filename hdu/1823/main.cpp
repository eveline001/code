#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node{
    int Sub[1000 << 2];
};

Node T[100 << 2];

void BuildUp(int l, int r, int rt){
    memset(T[rt].Sub, 0, sizeof(T[rt].Sub));
    if(l == r){
        return;
    }
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, (rt << 1) | 1);

    return;
}

void SubPushUp(int rt, int sub_rt){
    T[rt].Sub[sub_rt] = max(T[rt].Sub[sub_rt << 1], T[rt].Sub[(sub_rt << 1) | 1]);
}

void SubInsert(int A, int L, int rt, int sub_l, int sub_r, int sub_rt){
    if(sub_l == sub_r && sub_l == A){
        if(L > T[rt].Sub[sub_rt]){
            T[rt].Sub[sub_rt] = L;
        }
        return;
    }
    int mid = (sub_l + sub_r) >> 1;
    if(A <= mid){
        SubInsert(A, L, rt, sub_l, mid, sub_rt << 1);
    }else{
        SubInsert(A, L, rt, mid + 1, sub_r, (sub_rt << 1) | 1);
    }
    SubPushUp(rt, sub_rt);
}

void Insert(int H, int A, int L, int l, int r, int rt){
    SubInsert(A, L, rt, 0, 1000, 1);
    if(l == r && l == H){
        return;
    }
    int mid = (l + r) >> 1;
    if(H <= mid){
        Insert(H, A, L, l, mid, rt << 1);
    }else{
        Insert(H, A, L, mid + 1, r, (rt << 1) | 1);
    }
    return;
}

int SubSearch(int LA, int RA, int rt, int sub_l, int sub_r, int sub_rt){
    if(T[rt].Sub[sub_rt] == 0){
        return 0;
    }
    if(LA <= sub_l && RA >= sub_r){
        return T[rt].Sub[sub_rt];
    }
    int mid = (sub_l + sub_r) >> 1;
    if(RA <= mid){
        return SubSearch(LA, RA, rt, sub_l, mid, sub_rt << 1);
    }else if(LA > mid){
        return SubSearch(LA, RA, rt, mid + 1, sub_r, (sub_rt << 1) | 1);
    }else{
        return max(SubSearch(LA, RA, rt, sub_l, mid, sub_rt << 1), SubSearch(LA, RA, rt, mid + 1, sub_r, (sub_rt << 1) | 1));
    }
}

int Search(int LH, int RH, int LA, int RA, int l, int r, int rt){
    if(T[rt].Sub[1] == 0){
        return 0;
    }
    if(LH <= l && RH >= r){
        return SubSearch(LA, RA, rt, 0, 1000, 1);
    }
    int mid = (l + r) >> 1;
    if(RH <= mid){
        return Search(LH, RH, LA, RA, l, mid, rt << 1);
    }else if(LH > mid){
        return Search(LH, RH, LA, RA, mid + 1, r, (rt << 1) | 1);
    }else{
        return max(Search(LH, RH, LA, RA, l, mid, rt << 1), Search(LH, RH, LA, RA, mid + 1, r, (rt << 1) | 1));
    }
}

int main(){
    int M, ans;
    char op[2];
    int H, LH, RH, iLA, iRA;
    double A, L, LA, RA;

    while(scanf("%d", &M) != EOF && M){
        BuildUp(100, 200, 1);
        for(int i = 0; i < M; i++){
            scanf("%s", op);
            if(op[0] == 'I'){
                scanf("%d%lf%lf", &H, &A, &L);
                Insert(H, (int)(A * 10), (int)(L * 10), 100, 200, 1);
            }else{
                scanf("%d%d%lf%lf", &LH, &RH, &LA, &RA);
                if(LH > RH){
                    swap(LH, RH);
                }
                iLA = (int)(LA * 10);
                iRA = (int)(RA * 10);
                if(iLA > iRA){
                    swap(iLA, iRA);
                }
                ans = Search(LH, RH, iLA, iRA, 100, 200, 1);
                if(ans == 0){
                    printf("-1\n");
                }else{
                    printf("%d.%d\n", ans / 10, ans % 10);
                }
            }
        }
    }
    return 0;
}
