#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

queue<int> Q;
vector<int> E[1001];
bool Mtx[1001][1001];

void bfs(int s){
    while(!Q.empty()) Q.pop();
    Q.push(s);
    Mtx[s][s] = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(auto it = E[v].begin(); it != E[v].end(); ++it){
            if(!Mtx[s][*it]){Mtx[s][*it] = true; Q.push(*it);}
        }
    }
}

int main()
{
    int T, n, m;
    bool ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) E[i].clear();
        for(int i = 0, u, v; i < m; i++){
            scanf("%d%d", &u, &v);
            E[u].push_back(v);
        }
        memset(Mtx, false, sizeof(Mtx));
        ans = false;
        for(int i = 1; i <= n; i++) bfs(i);
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                if(Mtx[i][j] == false && Mtx[j][i] == false) ans = true;
            }
        }
        printf("%s\n", ans ? "Light my fire!" : "I love you my love and our love save us!");
    }
    return 0;
}
