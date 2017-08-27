#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 100010;
const long long INF = (1ULL << 63) - 1;

struct Edge{
    int v, w;
};

vector<Edge> E[MAXN << 1];
priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > Q;
long long dis0[MAXN], dis1[MAXN];

long long DijkstraSecondDis(int s, int t, int tol){
    for(int i = 1; i <= tol; i++) dis0[i] = dis1[i] = INF;
    while(!Q.empty()) Q.pop();
    dis0[s] = 0;
    Q.push(make_pair(0, s));
    while(!Q.empty()){
        pair<long long, int> p = Q.top();
        Q.pop();
        long long d0 = p.first;
        int v = p.second;
        if(dis1[v] < d0) continue;
        for(auto it = E[v].begin(); it != E[v].end(); ++ it){
            long long d1 = d0 + it->w;
            if(dis0[it->v] > d1){
                swap(dis0[it->v], d1);
                Q.push(make_pair(dis0[it->v], it->v));
            }
            if(dis1[it->v] > d1 && dis0[v] < d1){
                dis1[it->v] = d1;
                Q.push(make_pair(dis1[it->v], it->v));
            }
        }
    }
    return dis1[t];
}

int main()
{
    int T, n, m;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) E[i].clear();
        for(int i = 0, u, v, w; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            E[u].push_back(Edge{v, w});
            E[v].push_back(Edge{u, w});
        }
        printf("%I64d\n", DijkstraSecondDis(1, n, n));
    }
    return 0;
}
