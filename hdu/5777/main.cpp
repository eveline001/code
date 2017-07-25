#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];

int main()
{
    int T, n, k;
    long long ans;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n,&k);
        for(int i = 0; i < n - 1; i++) scanf("%d", &a[i]);
        if(k >= n){printf("%d\n", n); continue;}
        sort(a, a + n - 1);
        ans = 0;
        for(int i = 0; i < n - k; i++) ans += a[i] + 1;
        ans += k;
        cout << ans << endl;
    }

    return 0;
}
