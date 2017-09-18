#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int M, K;

    while(scanf("%d%d", &M, &K) != EOF){
        printf("%I64d\n", ((long long)M - K + 1) * K);
    }
    return 0;
}
