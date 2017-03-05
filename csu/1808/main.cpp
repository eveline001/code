
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const long long inf = 1e18;

struct Edge{
    int v, next;
    int c;
    int t;

    Edge(int v, int next, int c, int t) : v(v) , next(next), c(c), t(t) {}

    Edge(){}
};

struct Node{
    int id;
    int val;

    bool operator < (const Node& b) const{
        return this->val > b.val;
    }

    Node(int id, int val) : id(id), val(val) {}

    Node(){}
};

Edge E[200001];
int G[200001];
bool vis[200001];
long long dis[200001];

int main()
{
    int n, m, tol, u, v, c, t;
    long long ans;
    Node x;

    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i<= n; i++){
            G[i] = -1;
        }
        tol = 0;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d%d", &u, &v, &c, &t);
            E[tol] = Edge(u, G[v], c, t);
            G[v] = tol++;
            E[tol] = Edge(v, G[u], c, t);
            G[u] = tol++;
        }
        priority_queue<Node> heap;
        ans = inf;
        for(int i = 0; i < tol; i++){
            dis[i] = inf;
            vis[i] = false;
        }
        for(int i = G[1]; i != -1; i = E[i].next){
            dis[i] = E[i].t;
            heap.push(Node(i, E[i].t));
        }
        while(!heap.empty()){
            x = heap.top();;
            heap.pop();
            u = x.id;
            if(!vis[u]){
                vis[u] = true;
                v = E[u].v;
                if(v == n){
                    ans = min(ans, dis[u]);
                }
                for(int i = G[v]; i != -1; i = E[i].next){
                    if(!vis[i] && dis[i] > dis[u] + E[i].t + abs(E[i].c - E[u].c)){
                        dis[i] = dis[u] + E[i].t + abs(E[i].c - E[u].c);
                        heap.push(Node(i, dis[i]));
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
