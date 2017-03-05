#include <iostream>
#include <cstdio>

using namespace std;

struct Sta{
    int sum, begin;
    Sta(int sum, int begin) : sum(sum), begin(begin) {}
    Sta(){}
};

int que[10001];
Sta dp[10001];

int main()
{
    int K;

    while(scanf("%d", &K) != EOF && K)
    {
        for(int i = 0; i < K; i++) scanf("%d", &que[i]);
        for(int i = 0; i < K; i++) dp[i] = Sta(que[i], i);
        for(int i = 1; i < K; i++) if(dp[i - 1].sum > 0 && dp[i - 1].sum + que[i] > 0){dp[i].sum = dp[i - 1].sum + que[i]; dp[i].begin = dp[i - 1].begin;}
        int max = -1, posx = que[0], posy = que[K - 1];
        for(int i = 0; i < K; i++) if(dp[i].sum > max){max = dp[i].sum; posx = que[dp[i].begin]; posy = que[i];}
        if(max == -1) max = 0;
        printf("%d %d %d\n", max, posx, posy);
    }
}
