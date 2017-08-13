#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int T, P, ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &P);
        ans = 0;
        for(long long i = 1; i <= sqrt(P - 1) + 1; i++){
            if((P - 1) % i == 0){
                ans++;
                if((P - 1) / i != i) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
