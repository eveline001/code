#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node{
    int L, R;

    bool operator < (const Node& other) const{
        if(this->R != other.R) return this->R < other.R;
        return this->L > other.L;
    }
};

Node N[101];

int dp[101];

int main()
{
    int n, maxR, ans;

    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++) scanf("%d%d", &N[i].L, &N[i].R);
        sort(N, N + n);
        for(int i = 0; i < n; i++) dp[i] = 1;
        ans = 0;
        for(int i = 0; i < n; i++){
            maxR = -1;
            for(int j = i; j >= 0; j--){
                if(N[j].L <= maxR) break;
                if(N[j].R <= N[i].L) dp[i] = max(dp[i], dp[j] + 1), maxR = N[j].R;
            }
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
