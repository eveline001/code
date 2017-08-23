#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 7;
const long long MOD = 1e9 + 7;

char t[MAXN], s[MAXN];
int nxt[MAXN], cnt[MAXN];

int main()
{
    int T, n, m;
    long long ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%s%s", t, s);
        n = strlen(t), m = strlen(s);
        reverse(t, t + n);
        reverse(s, s + m);
        nxt[0] = nxt[1] = 0;
        for(int i = 1; i < m; i++){
            int j = nxt[i];
            while(j && s[j] != s[i]) j = nxt[j];
            nxt[i + 1] = s[j] == s[i] ? j + 1 : 0;
        }
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0, j = 0; i < n; i++){
            while(j && s[j] != t[i]) j = nxt[j];
            j += (s[j] == t[i]);
            cnt[j]++;
        }
        for(int i = m; i > 0; i--) cnt[nxt[i]] += cnt[i];
        ans = 0;
        for(int i = 1; i <= m; i++) ans = (ans + (long long)cnt[i] * i % MOD) % MOD;
        printf("%I64d\n", ans);
    }
    return 0;
}
