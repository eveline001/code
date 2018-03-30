#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Edge {
    int u, v, dis;

    bool operator < (const Edge& other) const {
        if (this->dis == other.dis) {
            if (this->u == other.u) {
                return this->v < other.v;
            }
            return this->u < other.u;
        }
        return this->dis < other.dis;
    }
};

Edge edges[100010];

int F[110];

void init(int x) {
    for (int i = 1; i <= x; i++) F[i] = i;
}

int FindFather(int x) {
    return F[x] == x ? x : FindFather(F[x]);
}

void Merge(int a, int b) {
    int Fa = FindFather(a),
        Fb = FindFather(b);

    if (Fa != Fb) F[Fb] = Fa;
}

int main()
{
    int N, M;

    while (scanf("%d", &N) != EOF && N) {
        scanf("%d", &M);
        init(M);
        for (int i = 0; i < N; i++) scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].dis);
        sort(edges, edges + N);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int Fu = FindFather(edges[i].u),
                Fv = FindFather(edges[i].v);

            if (Fu != Fv) {
                ans += edges[i].dis;
                Merge(edges[i].u, edges[i].v);
            }
        }
        int cnt = 0;
        for (int i = 1; i <= M; i++) if (F[i] == i) cnt++;
        if (cnt != 1) printf("?\n");
        else printf("%d\n", ans);
    }

    return 0;
}
