#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int offset = 1e5 + 7;

vector<int> Edge[1e5 + 1 + offset];

int main()
{
    int T, n, m, k, u, v;
    long long ans;

    scanf("%d", &T);
    for(int cas = 0; cas <= T; cas++){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < k; i++){
            scanf("%d%d", u, v);
            Edge[u].push_back(v + offset);
            Edge[v + offset].push_back(u);
        }
    }
    return 0;
}
