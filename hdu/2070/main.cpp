#include <iostream>
#include <cstdio>

using namespace std;

long long f[51] = {0, 1};

int main()
{
    int n;

    for(int i = 2; i <= 50; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    while(scanf("%d", &n) != EOF && n != -1){
        printf("%I64d\n", f[n]);
    }
    return 0;
}
