#include <iostream>
#include <cstdio>

using namespace std;

const int EulerRange = 1000;

int Euler[EulerRange + 1];

void EulerInit(){
    Euler[1] = 1;
    for(int i = 2; i <= EulerRange; i++) Euler[i] = i;
    for(int i = 2; i <= EulerRange; i++) if(Euler[i] == i) for(int j = i; j <= EulerRange; j += i) Euler[j] = Euler[j] / i * (i - 1);
}

int main()
{
    int C, N, ans;

    EulerInit();
    scanf("%d", &C);
    for(int cas = 1; cas <= C; cas++){
        scanf("%d", &N);
        ans = 0;
        for(int i = 2; i <= N; i++) ans += Euler[i];
        ans = ans * 2 + 3;
        printf("%d %d %d\n", cas, N, ans);
    }
    return 0;
}
