#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    double A, B, C;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%lf%lf%lf", &A, &B, &C);
        printf("%s\n", A + B > C && C > abs(A - B) ? "YES" : "NO");
    }
    return 0;
}
