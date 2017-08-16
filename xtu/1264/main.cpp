#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 7;

long long S[MAXN];

bool cmp(long long u, long long v){
    return u > v ? true : false;
}

int main()
{
    int n, m, C, a, temp;
    long long ans;

    while(scanf("%d%d%d", &n, &m, &C) != EOF){
        S[0] = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            S[i + 1] = S[i] + a;
        }
        sort(S, S + n + 1, cmp);
        ans = 0;
        for(int i = 0; i < m; i++)
            if((temp = S[i] - S[n - i] - C) > 0) ans += temp; else break;
        printf("%lld\n", ans);
    }
}
