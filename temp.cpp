#include <iostream>
#include <cstring>

using namespace std;

int e[150001], f[150001];
bool vis[150001];

int FindFather(int x){
    if(f[x] == x) return x;
    return f[x] = FindFather(f[x]);
}

void Merge(int a, int b){
    int fa = FindFather(a),
        fb = FindFather(b);

    if(fa != fb) f[fb] = fa;
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        f[i] = i;
    }
    memset(e, 0, sizeof(e));
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        Merge(u, v);
        e[u]++, e[v]++;
    }

}
