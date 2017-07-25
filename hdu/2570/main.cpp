#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const double esp = 1e-6;

double P[101];

int main()
{
    int T, n;
    double V, W, cnt, sum;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%lf%lf", &n, &V, &W);
        for(int i = 0; i < n; i++){
            scanf("%lf", &P[i]);
        }
        sort(P, P + n);
        if(P[0] > W){
            printf("0 0.00\n");
        }else{
            cnt = 1.0;
            sum = P[0];
            for(int i = 1; i < n; i++){
                if((sum + P[i]) / (cnt + 1.0) <= W){
                    cnt += 1.0;
                    sum += P[i];
                }else{
                    break;
                }
            }
            printf("%d %.2f\n", (int)(cnt * V), sum / (cnt * 100.0));
        }
    }
    return 0;
}
