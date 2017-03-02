#include <iostream>
#include <cstdio>

using namespace std;

const double esp = 1e-6;

int main()
{
    int T, S, H, Vx, Vy;
    double time, high;

    scanf("%d", &T);
    getchar();
    for(int t = 1; t <= T; t++){
        scanf("%d%d%d%d", &S, &H, &Vx, &Vy);
        time = (double)S / (double)Vx;
        high = (double)Vy * time - 5.0 * time * time;
        if(high >= (double)H && (double)H - high < esp){
            printf("good done!\n");
        }else{
            printf("poor Merida!\n");
        }
    }
    return 0;
}
