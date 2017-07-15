#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 7;

int ori[MAXN], sor[MAXN];

struct Node{
    int ls, rs, cnt;
};

Node T[MAXN * 22];
int segRt[MAXN];
int segCnt;

void BuildUp(int l, int r, int& rt){
    rt = ++segCnt;
    T[rt].cnt = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    BuildUp(l, mid, T[rt].ls);
    BuildUp(mid + 1, r, T[rt].rs);
}

void Update(int l, int r, int preRt, int& curRt, int pos){
    curRt = ++segCnt;
    T[curRt].cnt = T[preRt].cnt + 1;
    T[curRt].ls = T[preRt].ls;
    T[curRt].rs = T[preRt].rs;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(pos <= mid) Update(l, mid, T[preRt].ls, T[curRt].ls, pos);
    else Update(mid + 1, r, T[preRt].rs, T[curRt].rs, pos);
}

int Query(int L, int R, int l, int r, int k){
    if(l == r) return l;
    int num = T[T[R].ls].cnt - T[T[L].ls].cnt;
    int mid = (l + r) >> 1;
    if(k <= num) return Query(T[L].ls, T[R].ls, l, mid, k);
    else return Query(T[L].rs, T[R].rs, mid + 1, r, k - num);
}

int main()
{
    int T, num, m, n, l, r, k;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &num, &m);
        for(int i = 1; i <= num; i++){
            scanf("%d", &ori[i]);
            sor[i] = ori[i];
        }
        sort(sor + 1, sor + num + 1);
        n = unique(sor + 1, sor + num + 1) - sor - 1;
        segCnt = 0;
        BuildUp(1, n, segRt[0]);
        for(int i = 1; i <= num; i++){
            Update(1, n, segRt[i - 1], segRt[i], lower_bound(sor + 1, sor + n + 1, ori[i]) - sor);
        }
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", sor[Query(segRt[l - 1], segRt[r], 1, n, k)]);
        }
    }
    return 0;
}
