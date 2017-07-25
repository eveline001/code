#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T, n, m;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &n, &m);
        m /= 2;
        printf("%d %d\n", m - n, n + n - m);
    }
    return 0;
}
