#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const long long INF = 1e17;

struct Skill{
    int k, p;
};

Skill S[2007];

int a[200007], b[200007];
long long dp[2007][16];

void BagTable(int b, int V, int n){
    for(int i = 0; i <= V; i++) dp[i][b] = INF;
    for(int i = 0; i < n; i++){
        if(S[i].p <= b) continue;
        for(int j = 0; j <= S[i].p - b; j++) dp[j][b] = min(dp[j][b], (long long)S[i].k);
        for(int j = S[i].p - b + 1; j <= V; j++) dp[j][b] = min(dp[j][b], dp[j - S[i].p + b][b] + S[i].k);
    }
}

int main()
{
    int n, m, minb, maxa, maxb;
    long long ans;

    while(scanf("%d%d", &n, &m) != EOF){
        minb = 10, maxa = 0, maxb = 0;
        for(int i = 0; i < n; i++){scanf("%d%d", &a[i], &b[i]); minb = min(minb, b[i]), maxb = max(maxb, b[i]), maxa = max(maxa, a[i]);}
        for(int i = 0; i < m; i++) scanf("%d%d", &S[i].k, &S[i].p);
        for(int i = minb; i <= maxb; i++) BagTable(i, maxa, m);
        ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[a[i]][b[i]] != INF) ans += dp[a[i]][b[i]];
            else{ans = -1; break;}
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
