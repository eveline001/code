#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int A, B, n, z = 1;
    int f[54] = {0, 1, 1};
    while(scanf("%d%d%d", &A, &B, &n) != EOF){
        if(A == 0 && B == 0 && n == 0){
            break;
        }
        for(int i = 3; i < 54; ++i){
            f[i] = (A * f[i - 1] + B * f[i - 2]) % 7;
            if(i > 5 && f[i - 1] == f[3] && f[i] == f[4]){
                z = i - 4;
                break;
            }
        }
        if(n > 2){
            printf("%d\n", f[(n - 3) % z + 3]);
        }else{
            printf("1\n");
        }
    }
    return 0;
}
