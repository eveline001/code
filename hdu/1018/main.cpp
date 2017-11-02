//Stirling¡¯s approximation
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);
const double  e = exp(1.0);

int main()
{
    int n;
    double m;

    scanf("%d", &n);
    for(int i = 0; i < n ;i++){
        scanf("%lf", &m);
        printf("%d\n", (int)(log10(sqrt(2.0 * pi * m)) + m * log10(m / e)) + 1);
    }
    return 0;
}
