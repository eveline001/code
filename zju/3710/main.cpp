#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int cnt[100];
bool sta[100][100];
int n;

void Merge(int a, int b){
    sta[a][b] = sta[b][a] = true;
}

int Check(int a, int b){
    int res = 0;
    for(int i = 0; i < n; i++) if(sta[a][i] && sta[b][i]) res++;
    return res;
}

int main()
{
    int T, m, k, u, v, num;
    bool boolean;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d", &n, &m, &k);
        memset(cnt, 0, sizeof(cnt));
        memset(sta, false, sizeof(sta));
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            cnt[u]++, cnt[v]++;
            sta[u][v] = true, sta[v][u] = true;
            Merge(u, v);
        }
        num = 0;
        for(;;){
            boolean = true;
            for(int i = 0; i < n; i++) if(cnt[i] >= k && cnt[i] < n - 1)
                for(int j = i + 1; j < n; j++) if(cnt[j] >= k && cnt[j] < n - 1 && !sta[i][j])
                    if(Check(i, j) >= k){
                        boolean = false;
                        cnt[i]++, cnt[j]++;
                        Merge(i, j);
                        num++;
                    }
            if(boolean) break;
        }
        printf("%d\n", num);
    }
    return 0;
}