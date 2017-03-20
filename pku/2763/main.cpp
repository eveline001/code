/*
*
http://blog.csdn.net/y990041769/article/details/40983749 2125ms
TLE
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define Del(a,b) memset(a,b,sizeof(a))

const int N = 100005;
int dep[N],siz[N],fa[N],id[N],son[N],val[N],top[N]; //top 最近的重链父节点
int num,head[N],cnt;

struct Edge{
    int to,next;
};

Edge v[N*2];

struct tree{
    int x, y, val;
    void read(){
        scanf("%d%d%d", &x, &y, &val);
    }
};

void add_Node(int x,int y)
{
    v[cnt].to = y;
    v[cnt].next = head[x];
    head[x] = cnt++;
}

tree e[N];

void dfs1(int u, int f, int d){
    dep[u] = d, siz[u] = 1, son[u] = 0, fa[u] = f;
    for(int i = head[u]; i != -1 ;i = v[i].next){
        int to = v[i].to;
        if(to != f){
            dfs1(to,u,d+1);
            siz[u] += siz[to];
            if(siz[son[u]] < siz[to])
                son[u] = to;
        }
    }
}

void dfs2(int u, int tp){
    top[u] = tp;
    id[u] = ++num;
    if (son[u]) dfs2(son[u], tp);
    for(int i = head[u]; i != -1 ;i = v[i].next)
    {
        int to = v[i].to;
        if(to == fa[u] || to == son[u])
            continue;
        dfs2(to,to);
    }
}

#define lson(x) ((x<<1))
#define rson(x) ((x<<1)+1)

struct Tree
{
    int l,r,val;
};

Tree tree[4*N];

void pushup(int x){
    tree[x].val = tree[lson(x)].val + tree[rson(x)].val;
}

void build(int l,int r,int v)
{
    tree[v].l=l;
    tree[v].r=r;
    if(l==r){
        tree[v].val = val[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,v*2);
    build(mid+1,r,v*2+1);
    pushup(v);
}

void update(int o,int v,int val)  //log(n)
{
    if(tree[o].l==tree[o].r)
    {
        tree[o].val = val;
        return ;
    }
    int mid = (tree[o].l+tree[o].r)/2;
    if(v<=mid)
        update(o*2,v,val);
    else
        update(o*2+1,v,val);
    pushup(o);
}

int query(int o,int l, int r)
{
    if(tree[o].l >= l && tree[o].r <= r){
        return tree[o].val;
    }
    int mid = (tree[o].l + tree[o].r) / 2;
    if(r<=mid)
        return query(o+o,l,r);
    else if(l>mid)
        return query(o+o+1,l,r);
    else
        return query(o+o,l,mid) + query(o+o+1,mid+1,r);
}

int Yougth(int u, int v){
    int tp1 = top[u], tp2 = top[v];
    int ans = 0;
    while (tp1 != tp2){
        if (dep[tp1] < dep[tp2]){
            swap(tp1, tp2);
            swap(u, v);
        }
        ans += query(1,id[tp1], id[u]);
        u = fa[tp1];
        tp1 = top[u];
    }
    if(u == v) return ans;
    if(dep[u] > dep[v]) swap(u, v);
    ans += query(1,id[son[u]], id[v]);
    return ans;
}
int main()
{
    int n, m, s;
    while(scanf("%d%d%d", &n, &m, &s) != EOF){
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 1; i < n; i++){
            e[i].read();
            add_Node(e[i].x, e[i].y);
            add_Node(e[i].y, e[i].x);
        }
        num = 0;
        dfs1(1, 0, 1);
        dfs2(1, 1);
        for(int i = 1; i < n; i++){
            if(dep[e[i].x] < dep[e[i].y]) swap(e[i].x, e[i].y);
            val[id[e[i].x]] = e[i].val;
        }
        build(1, num, 1);
        for(int i = 0; i < m; i++){
            int ok, x, y;
            scanf("%d", &ok);
            if(ok == 0){
                scanf("%d", &x);
                printf("%d\n", Yougth(s, x));
                s = x;
            }else{
                scanf("%d%d", &x, &y);
                update(1,id[e[x].x],y);
            }
        }
    }
    return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 100001;

struct Edge{
    int to, next;
};

Edge Edges[MAX << 1];
int head[MAX];
int cnt;
int Road[MAX][3];
int fa[MAX], sz[MAX], de[MAX], sn[MAX], tp[MAX], id[MAX];
int val[MAX];
int sum[MAX << 2];
int tol;

void DfsTree(int x, int father, int deep){
    fa[x] = father, de[x] = deep, sz[x] = 1, sn[x] = 0;
    for(int i = head[x]; ~i; i = Edges[i].next){
        int v = Edges[i].to;
        if(v != father){
            DfsTree(v, x, deep + 1);
            sz[x] += sz[v];
            if(sz[v] > sz[sn[x]]){
                sn[x] = v;
            }
        }
    }
    return;
}

void DfsChain(int x, int top){
    tp[x] = top;
    id[x] = ++tol;
    if(sn[x]){
        DfsChain(sn[x], top);
        for(int i = head[x]; ~i; i = Edges[i].next){
            int v = Edges[i].to;
            if(v != sn[x] && v != fa[x]){
                DfsChain(v, v);
            }
        }
    }
    return;
}

void PushUp(int rt){
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    return;
}

void BuildUp(int l, int r, int rt){
    if(l == r){
        sum[rt] = val[l];
        return;
    }
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, rt << 1 | 1);
    PushUp(rt);
    return;
}

void Update(int pos, int val, int l, int r, int rt){
    if(l == r && l == pos){
        sum[rt] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid){
        Update(pos, val, l, mid, rt << 1);
    }else{
        Update(pos, val, mid + 1, r, rt << 1 | 1);
    }
    PushUp(rt);
    return;
}

int Query(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
        return sum[rt];
    }
    int mid = (l + r) >> 1, res = 0;
    if(L <= mid){
        res += Query(L, R, l, mid, rt << 1);
    }
    if(R > mid){
        res += Query(L, R, mid + 1, r, rt << 1 | 1);
    }
    return res;
}

int ChainQuery(int a, int b, int n){
    if(a == b){
        return 0;
    }
    if(tp[a] == tp[b]){
        if(id[a] > id[b]){
            return Query(id[b] + 1, id[a], 2, n, 1);
        }else{
            return Query(id[a] + 1, id[b], 2, n, 1);
        }
    }
    if(tp[a] < tp[b]){
        return Query(id[tp[b]], id[b], 2, n, 1) + ChainQuery(a, fa[b], n);
    }else{
        return Query(id[tp[a]], id[a], 2, n, 1) + ChainQuery(fa[a], b, n);
    }
}

int main()
{
    int n, q, s, u, v, w, op;

    while(scanf("%d%d%d", &n, &q, &s) != EOF){
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &w);
            Edges[cnt].to = v, Edges[cnt].next = head[u], head[u] = cnt++;
            Edges[cnt].to = u, Edges[cnt].next = head[v], head[v] = cnt++;
            Road[i][0] = u, Road[i][1] = v, Road[i][2] = w;
        }
        tol = 0;
        DfsTree(1, 1, 0);
        DfsChain(1, 1);
        for(int i = 1; i < n; i++){
            if(de[Road[i][0]] < de[Road[i][1]]){
                swap(Road[i][0], Road[i][1]);
            }
            val[id[Road[i][0]]] = Road[i][2];
        }
        BuildUp(2, n, 1);
        for(int i = 0; i < q; i++){
            scanf("%d", &op);
            if(op == 0){
                scanf("%d", &u);
                printf("%d\n", ChainQuery(s, u, n));
                s = u;
            }else if(op == 1){
                scanf("%d%d", &v, &w);
                Update(id[Road[v][0]], w, 2, n, 1);
            }
        }
    }
    return 0;
}
*/
