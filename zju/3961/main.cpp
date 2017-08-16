#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node{
    int pos, vct;

    Node(int pos = 0, int vct = 0) : pos(pos), vct(vct) {}

    bool operator < (const Node& other) const{
        return this->pos < other.pos;
    }
};

Node N[500];
int tol;

int main()
{
    int T, n, m, x, y, l, r, v, pre;
    long long ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d%d", &n, &m, &x, &y);
        tol = 0;
        for(int i = 0; i < x; i++){
            scanf("%d%d", &l, &r);
            N[tol++] = Node(l, 1);
            N[tol++] = Node(r, -1);
        }
        for(int i = 0; i < y; i++){
            scanf("%d%d", &l, &r);
            N[tol++] = Node(l, 1);
            N[tol++] = Node(r, -1);
        }
        sort(N, N + tol);
        v   = 0;
        pre = 1;
        ans = 0;
        for(int i = 0; i < tol; i++){
            if(N[i].vct == 1){
                v++;
                if(v == 2) pre = N[i].pos;
            }else{
                if(v == 2) ans += N[i].pos - m + 1 - pre >= 0 ? N[i].pos - m + 1 - pre + 1 : 0;
                v--;
            }
        }
        printf("%lld\n", ans);
    }
}