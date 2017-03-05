#include <iostream>
#include <cstdio>

using namespace std;

int a[100001];
int s[100001];

int main()
{
    int T, n, m;
    bool flag;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        s[0] = a[0];
        for(int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
        flag = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if((s[j] - s[i] + a[i]) >= m && (s[j] - s[i] + a[i]) % m == 0)
                {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) printf("YES\n"); else printf("NO\n");
    }

    return 0;
}
