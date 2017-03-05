//BestCoder 2nd Anniversary B
#include <iostream>
#include <cstdio>

using namespace std;

const long long M = 998244353;

int B[100010], C[100010];

int main()
{
    int T, n, i, cnt, wid;
    bool flag;
    long long ans;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++) scanf("%d", &B[i]);
        for(i = 1; i <= n; i++) scanf("%d", &C[i]);
        if(B[1] != C[1]){printf("0\n"); continue;}
        flag = true;
        ans = 1;
        cnt = 0;
        wid = 0;
        for(i = 2; i <= n; i++)
        {
            if(B[i] > B[i-1] || C[i] < C[i-1] || B[i] > C[i] || (B[i] != B[i-1] && C[i] != C[i-1])){flag = false; break;}
            if(B[i] == B[i-1] && C[i] == C[i-1])
            {
                if(cnt == 0)
                {
                    flag = false;
                    break;
                }
                ans = (ans * cnt) % M;
                cnt--;
            }
            else
            {
                cnt += C[i] - B[i] - wid - 1;
                wid = C[i] - B[i];
            }
        }
        if(!flag){printf("0\n"); continue;}
        cout << ans % M << endl;
    }
}
