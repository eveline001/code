#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    long long a;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%I64d", &a);
        printf("%I64d\n", (a + 1) / 2 + 1);
    }
    return 0;
}
