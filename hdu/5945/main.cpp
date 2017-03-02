#include <iostream>
#include <cstdio>

using namespace std;

const int inf = 1e9;

int dp[1000001];

int main()
{
    int T;
    int X, k, t;
    int tmp1, tmp2, p, p1, p2;

    scanf("%d", &T);
    for(int c = 1; c <= T; c++){
        scanf("%d%d%d", &X, &k, &t);
        dp[1] = 0;
        p = 0;
        for(int i = 2; i <= X; i++){
            if(k != 1 && i % k == 0){
                tmp1 = dp[i / k] + 1;
                p = 0;
            }else
        }
    }
}

/*
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int inf = 1e9;

int dp[1100000];

int main()
{
    int i, t, x, k, T;
    int tmp1, tmp2, p1, p2, p;

    scanf("%d",&T);
    for(int c = 1; c <= T; c++){
        scanf("%d%d%d",&x,&k,&t);
        dp[1] = 0;
        p = 0;
        for(i = 2; i <= x; i++)
        {
            if(i % k == 0 && k != 1){
                tmp1 = dp[i / k] + 1;
                p1 = 0;
            }else{
                tmp1 = inf;
            }
            if(p > 0){
                tmp2 = dp[i - 1];
                p2 = p - 1;
            }else{
                tmp2 = dp[i - 1] + 1;
                p2 = t - 1;
            }
            if(tmp1 >= tmp2){
                dp[i] = tmp2;
                p = p2;
            }else{
                dp[i] = tmp1;
                p = p1;
            }
            printf("^^^%d %d\n",i,dp[i]);
        }
        printf("%d\n",dp[x]);
    }
}
*/
