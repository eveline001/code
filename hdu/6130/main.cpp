#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e7;

int k[MAXN];

int main()
{
    int T, n;

    k[0] = 1, k[1] = 2, k[2] = 2;
    int cnt = 3, v = 0;
    for(int i = 2; cnt <= MAXN; i++){
        for(int j = 1; j <= k[i]; j++) k[cnt++] = 1 + v;
        v ^= 1;
    }

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        printf("%d\n", k[n - 1]);
    }
    return 0;
}
