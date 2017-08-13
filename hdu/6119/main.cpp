#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node{
    int L, R;

    bool operator < (const Node& other) const{
        if(this->R != other.R) return this->R > other.R;
        return this->L < other.L;
    }
};

Node A[100001], B[100001];
int ed[100001];

int main()
{
    int n, m, ans, st, ed, cos, len, cnt;

    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < n; i++) scanf("%d%d", &A[i].L, &A[i].R);
        sort(A, A + n);
        B[0].R = A[0].R, B[0].L = A[0].L, cnt = 0;
        for(int i = 1; i < n; i++){
            if(A[i].R >= B[cnt].L - 1) B[cnt].L = min(A[i].L, B[cnt].L);
            else cnt++, B[cnt].R = A[i].R, B[cnt].L = A[i].L;
        }
        st = ed = 0, cos = 0, ans = len = B[0].R - B[0].L + 1, ans += m;
        while(ed <= st && st <= cnt){
            if(st < cnt && cos <= m) st++, cos += B[st - 1].L - B[st].R - 1, len += B[st - 1].L - B[st].L;
            else ed++, cos -= B[ed - 1].L - B[ed].R - 1, len -= B[ed - 1].R - B[ed].R;
            if(cos <= m){if(len + m - cos > ans) ans = len + m - cos; if(st == cnt) break;}
        }
        printf("%d\n", ans);
    }
    return 0;
}
