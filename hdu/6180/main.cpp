#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node{
    int pos, v;

    bool operator < (const Node& other) const{
        if(this->pos == other.pos) return this->v < other.v;
        return this->pos < other.pos;
    }
};

Node No[200010];
int st[100001], ed[100001], tol;

int main()
{
    int T, N, v, num;
    long long time;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &N);
        tol = 0;
        for(int i = 0, s, e; i < N; i++){
            scanf("%d%d", &s, &e);
            No[tol].pos = s, No[tol++].v =  1;
            No[tol].pos = e, No[tol++].v = -1;
        }
        sort(No, No + tol);
        memset(st, -1, sizeof(st));
        memset(ed,  0, sizeof(ed));
        v = num = time = 0;
        for(int i = 0; i < tol; i++){
            v += No[i].v;
            if(No[i].v == 1){
                if(st[v] == -1) st[v] = No[i].pos;
            }else{
                ed[v + 1] = No[i].pos;
            }
            if(v > num) num = v;
        }
        for(int i = 1; i <= num; i++) time += ed[i] - st[i];
        printf("%d %I64d\n", num, time);
    }
    return 0;
}
