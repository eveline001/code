#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

set<int> s;

int main()
{
    int T, A, B, C;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d", &A, &B, &C);
        printf("%d %d\n", (A * A) * 300 + (2 * A * B + B * B) * 100 + (2 *(A + B) * C + C * C) * 50,
               (C * C) * 50 + (2 * C * B + B * B) * 100 + (2 *(C + B) * A + A * A) * 300);
    }
    return 0;
}