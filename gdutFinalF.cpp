#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 100000 + 7;

int n;

struct Node{
    int to, next;
};
Node Edge[MAX << 1];
int head[MAX];
int cnt;
int Road[MAX][3];

int fa[MAX], sz[MAX], de[MAX], sn[MAX], tp[MAX], id[MAX];
int tol;

void Dfs_Tree(int x, int father, int deep){
    fa[x] = father, de[x] = deep, sz[x] = 1, sn[x] = 0;
    for(int i = head[x]; ~i; i = Edge[i].next){
        v = Edge[i].to;
        if(v != father){
            Dfs_Tree(v, x, deep + 1);
            if(sz[v] > sz[sn[x]]) sn[x] = v;
        }
    }
}

void Dfs_Chain(int x, int top){
    tp[x] = top, id[x] = ++tol;
    if(sn[x]){
        Dfs_Chain(sn[x], top);
        for(int i = head[x]; ~i; i = Edge[i].next){
            v = Edge[i].to;
            if(v != fa[x] && v != sn[x]){
                Dfs_Chain(v, v);
            }
        }
    }
}

int val[MAX];

int main()
{
    int T, a, b, len;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        cnt = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &a, &b, &len);
            Edge[cnt].to = a, Edge[cnt].next = head[b], head[b] = cnt++;
            Edge[cnt].to = b, Edge[cnt].next = head[a], head[a] = cnt++;
            Road[i][0] = a, Road[i][1] = b, Road[i][2] = len;
        }
        Dfs_Tree(1, 1, 0);
        Dfs_Chain(1, 1);
        for(int i = 0; i < n; i++){
            if(Road[i][0] < Road[i][1]) swap(Road[i][0], Road[i][1]);
            val[Road[i][0]] = Road[i][2];
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d%d", &a, &b);
            printf("%s\n", Query(a, b) ? "Yes" : "No");
        }
    }
    return 0;
}
