#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1e6 + 7;

int arr[MAX], dp[MAX];

int main()
{
    int n, ans;

    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            dp[i] = 1;
        }
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(arr[j] > arr[i] && dp[j] < dp[i] + 1) dp[j] = dp[i] + 1;
            }
        }
        ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] > ans) ans = dp[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
