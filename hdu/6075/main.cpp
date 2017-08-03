#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T, n, a, cnt;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        cnt = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            if(a % 2 == 1) cnt++;
        }
        printf("%d %d\n", 2, cnt > n / 2 ? 1 : 0);
    }
    return 0;
}
