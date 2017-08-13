#include <iostream>
#include <cstdio>

using namespace std;

bool isLeapYear(int y){
    return y % 100 ? y % 4 ? false : true : y % 400 ? false : true;
}

int main()
{
    int T, y, m, d, ans, cnt;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d-%d-%d", &y, &m, &d);
        ans = y,  cnt = 0;
        if(m == 2 && d == 29){
            ans += 4;
            if(isLeapYear(ans)) cnt += (365 * 3 + 366);
            else ans += 4, cnt += (365 * 7 + 366);
            while(cnt % 7 != 0){
                ans += 4;
                if(isLeapYear(ans)) cnt += (365 * 3 + 366);
                else ans += 4, cnt += (365 * 7 + 366);
            }
        }else{
            ans++;
            cnt += isLeapYear(m > 2 ? ans : ans - 1) ? 366 : 365;
            while(cnt % 7 != 0)
                ans++, cnt += isLeapYear(m > 2 ? ans : ans - 1) ? 366 : 365;
        }
        printf("%d\n", ans);
    }
    return 0;
}
