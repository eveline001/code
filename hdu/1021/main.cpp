#include <iostream>
#include <cstdio>

using namespace std;

long long F[1000000];

int main()
{
    int n;

    F[0] = 7;
    F[1] = 11;
    for(int i = 2; i < 1000000; i++){
        F[i] = (F[i - 2] % 3 + F[i - 1] % 3) % 3;
    }
    while(scanf("%d", &n) != EOF){
        if(F[n] % 3 == 0){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}
