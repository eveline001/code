#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

char A[100000], B[100000];

int main()
{
    int T, n, x, y, xdef, sdef;
    bool islegal;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d", &n, &x, &y);
        scanf("%s", A);
        scanf("%s", B);
        xdef = fabs(x - y), sdef = 0;
        for(int i = 0; i < n; i++) if(A[i] != B[i]) sdef++;
        islegal = false;
        for(int scurt = 0; scurt <= min(min(x, y), n - sdef); scurt++){
            if(x - scurt <= sdef && y - scurt <= sdef && x + y <= sdef + scurt + scurt){islegal = true; break;}
        }
        printf("%s\n", islegal && xdef <= sdef ? "Not lying" : "Lying");
    }
    return 0;
}
