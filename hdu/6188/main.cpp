#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;

int cnt[MAXN];
bool vis[MAXN];

int main()
{
    int n;

    while(scanf("%d", &n) != EOF){
        memset(vis, false, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1, x; i <= n; i++){
            scanf("%d", &x);
            cnt[x]++;
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            if(cnt[i] >= 2) vis[i] = true;
            ans += cnt[i] / 2, cnt[i] %= 2;
        }
        for(int i = 3; i <= n; i++){
            if(cnt[i - 1] == 1 && cnt[i - 2] == 1){
                if(cnt[i] == 0 && vis[i]) cnt[i - 1] = cnt[i - 2] = 0, cnt[i] = 1;
                else if(cnt[i] == 1) cnt[i] = cnt[i - 1] = cnt[i - 2] = 0, ans++;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
