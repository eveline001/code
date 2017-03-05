#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int p[1001];
int w[1001];

int main()
{
    int n, m;

    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++){
            scanf("%d", &p[i]);
        }
        sort(p, p + n);
        scanf("%d", &m);
        if(m < 5){
            printf("%d\n", m);
            continue;
        }
        for(int i = 0; i <= m - 5; i++){
            w[i] = 0;
        }
        for(int i = 0; i < n - 1; i++){
            for(int j = m - 5; j >= p[i]; j--){
                w[j] = max(w[j], w[j - p[i]] + p[i]);
            }
        }
        printf("%d\n", m - w[m - 5] - p[n - 1]);
    }

    return 0;
}
