#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

namespace fastIO {
    #define BUF_SIZE 10 * 1024 * 1024
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    #undef BUF_SIZE
};
using namespace fastIO;

const int MAXN = 100010;

struct Edge{
    int to, next;
};

Edge Edges[MAXN << 1];
int head[MAXN], cnt, Nx, Ny;

int Mx[MAXN], My[MAXN];
queue<int> Q;
int dx[MAXN], dy[MAXN];
bool vis[MAXN];

bool HopcroftKarpDfs(int u){
    for(int i = head[u]; ~i; i = Edges[i].next){
        int v = Edges[i].to;
        if(!vis[v] && dy[v] == dx[u] + 1){
            vis[v] = true;
            if(!My[v] || HopcroftKarpDfs(My[v])){
                Mx[u] = v, My[v] = u;
                return true;
            }
        }
    }
    return false;
}

int HopcroftKarp(){
    memset(Mx, 0, sizeof(Mx));
    memset(My, 0, sizeof(My));
    int ans = 0;
    while(true){
        bool flag = false;
        while(!Q.empty()) Q.pop();
        memset(dx, 0, sizeof(dx));
        memset(dy, 0, sizeof(dy));
        for(int i = 1; i <= Nx; i++) if(!Mx[i]) Q.push(i);
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            for(int i = head[u]; ~i; i = Edges[i].next){
                int v = Edges[i].to;
                if(!dy[v]){
                    dy[v] = dx[u] + 1;
                    if(My[v]){
                        dx[My[v]] = dy[v] + 1;
                        Q.push(My[v]);
                    }else flag = true;
                }
            }
        }
        if(!flag) break;
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= Nx; i++) if(!Mx[i] && HopcroftKarpDfs(i)) ans++;
    }
    return ans;
}

int main()
{
    int T, N, K, ans;

    read(T);
    for(int cas = 1; cas <= T; cas++){
        read(N);
        read(K);
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 2, x; i <= N; i++){
            read(x);
            Edges[cnt].to = x, Edges[cnt].next = head[i], head[i] = cnt++;
            Edges[cnt].to = i, Edges[cnt].next = head[x], head[x] = cnt++;
        }
        Nx = Ny = N;
        ans = HopcroftKarp();
        ans = min(ans / 2, K / 2);
        printf("%d\n", K - ans);
    }
    return 0;
}
