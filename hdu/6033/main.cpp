#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double ln2  = log10( 2.0);

int main()
{
    int m, cas = 1, ans;
    double m2;

    while(scanf("%d", &m) != EOF){
        m2 = ln2 * m;
        ans = floor(m2);
        printf("Case #%d: %d\n",cas++, ans);
    }
    return 0;
}
