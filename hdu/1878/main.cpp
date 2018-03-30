#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int degree[1024], fa[1024];

int FindFather(int x){
    return fa[x] == x ? x : fa[x] = FindFather(fa[x]);
}

void Merge(int u, int v){
    int fu = FindFather(u), fv = FindFather(v);

    fa[fv] = fa[fu];
}

int main()
{
    int N, M;

    while(scanf("%d", &N) != EOF && N){
        scanf("%d", &M);
        memset(degree, 0, sizeof(degree));
        for(int i = 0; i <= N; i++) fa[i] = i;
        for(int i = 0, u , v; i < M; i++){
            scanf("%d%d", &u, &v);
            degree[u]++, degree[v]++;
            Merge(u, v);
        }
        bool ans = true;
        for(int i = 1; i < N; i++){
            if(fa[i] != fa[i + 1]){
                ans = false;
                break;
            }
        }
        if(ans){
            for(int i = 1; i <= N; i++){
                if(degree[i] & 1){
                    ans = false;
                    break;
                }
            }
        }
        printf("%d\n", ans ? 1 : 0);
    }
    return 0;
}
