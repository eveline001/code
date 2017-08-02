#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, a, ans = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){scanf("%d", &a); if(a <= 35) ans++;}
    printf("%d\n", ans);
    return 0;
}
