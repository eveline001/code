#include <iostream>

using namespace std;

int dp[128][128];

int main()
{
    int a[128][128];

    int C, N, i, j, ans;

    cin >> C;
    while(C--)
    {
        cin >> N;
        for(i = 1; i <= N; i++)
        {
            for(j = 1; j <= i; j++)
            {
                cin >> a[i][j];
                dp[i][j] = 0;
            }
        }
        ans = 0;
        dp[1][1] = a[1][1];
        for(i = 2; i <= N; i++)
        {
            for(j = 1; j <= i; j++)
            {
                if(j != 1 && j != i)
                {
                    dp[i][j] = dp[i-1][j-1] >= dp[i-1][j] ? dp[i-1][j-1] : dp[i-1][j];
                    dp[i][j] += a[i][j];
                }
                else
                {
                    if(j == 1)
                    {
                        dp[i][j] = dp[i-1][1] + a[i][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j-1] + a[i][j];
                    }
                }
            }
        }
        for(i = 1; i <= N; i++)
        {
            if(dp[N][i] > ans)
            {
                ans = dp[N][i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
