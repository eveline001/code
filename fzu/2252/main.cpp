#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    long long a, b, c, AB, AC, BC, ra, rb, rc, temp, curMax, finMax;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &a, &b, &c, &AB, &AC, &BC);
        finMax = 0;
        for(long long x = 0; x <= min(a, b); x++){
            ra = a - x;
            rb = b - x;
            curMax = x * AB;
            if(AC > BC){
                temp = min(ra, c);
                curMax += temp * AC;
                rc = c - temp;
                curMax += min(rb, rc) * BC;
            }else{
                temp = min(rb, c);
                curMax += temp * BC;
                rc = c - temp;
                curMax += min(ra, rc) * AC;
            }
            if(finMax < curMax) finMax = curMax;
        }
        printf("%I64d\n", finMax);
    }
    return 0;
}
