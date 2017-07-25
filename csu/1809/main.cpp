#include <stdio.h>
#include <algorithm>

using namespace std;

char buf[200000];
int  Sum[200000 << 2];
int n, q, x, y, temp;

void PushUp(int rt){
    Sum[rt] = min(Sum[rt << 1], Sum[rt << 1 | 1]);
}

void BuildUp(int l, int r, int rt){
    if(l == r){
        if(buf[l - 1] == '('){
            Sum[rt] = ++temp;
        }else Sum[rt] = --temp;
        return;
    }
    int m = (l + r) >> 1;
    BuildUp(l, m, rt << 1);
    BuildUp(m + 1, r, rt << 1 | 1);
    PushUp(rt);
}

int Query(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r) return Sum[rt];
    int m = (l + r) >> 1,
        res = 1e9;
    if(L <= m) res = min(res, Query(L, R, l, m, rt << 1));
    if(R >= m + 1) res = min(res, Query(L, R, m + 1, r, rt << 1 | 1));
    return res;
}

int main()
{
    while(scanf("%d%d", &n, &q) != EOF){
        getchar();
        gets(buf);
        temp = 0;
        BuildUp(1, n, 1);
        for(int i = 0; i < q; i++){
            scanf("%d%d", &x, &y);
            if(buf[x - 1] == buf[y - 1]){
                printf("Yes\n");
                continue;
            }
            if(x > y){
                temp = x;
                x = y;
                y = temp;
            }
            if(buf[x - 1] == '('){
                if(Query(x, y - 1, 1, n, 1) < 2) printf("No\n");
                    else printf("Yes\n");
            }else{
                printf("Yes\n");
            }
        }
    }
    return 0;
}
