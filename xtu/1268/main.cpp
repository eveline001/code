#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main()
{
    long long n, m;

    while(scanf("%lld%lld", &n, &m) != EOF){
        printf("1/%lld\n", (long long)2 * m / gcd(m, n) * n);
    }
    return 0;
}
