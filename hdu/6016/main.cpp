#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int SIZE   = 1e5 + 1;

vector<int> Edge[SIZE];
int cnt[SIZE];

int main()
{
    int T, n, m, k, u, v;
    long long ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++){
            Edge[i].clear();
        }
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < k; i++){
            scanf("%d%d", &u, &v);
            Edge[v].push_back(u);
            cnt[u]++;
        }
        ans = 0;
        for(int i = 1; i <= m; i++){
            long long temp = Edge[i].size() - 1;
            for(int x : Edge[i]){
                ans += temp * (cnt[x] - 1);
            }
        }
        printf("%lld\n", ans <<1);
    }
    return 0;
}
