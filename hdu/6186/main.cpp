#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 10;

int ori[MAXN], A[MAXN][2], O[MAXN][2], X[MAXN][2];

int main()
{
    int n, q;

    while(scanf("%d%d", &n, &q) != EOF){
        for(int i = 1; i <= n; i++) scanf("%d", &ori[i]);
        A[1][0] = O[1][0] = X[1][0] = ori[1];
        for(int i = 2; i <= n; i++){
            A[i][0] = ori[i] & A[i - 1][0];
            O[i][0] = ori[i] |  O[i - 1][0];
            X[i][0] = ori[i] ^ X[i - 1][0];
        }
        A[n][1] = O[n][1] = X[n][1] = ori[n];
        for(int i = n - 1; i >= 1; i--){
            A[i][1] = ori[i] & A[i + 1][1];
            O[i][1] = ori[i] |  O[i + 1][1];
            X[i][1] = ori[i] ^ X[i + 1][1];
        }
        for(int i = 0, x; i < q; i++){
            scanf("%d", &x);
            if(x == 1) printf("%d %d %d\n", A[2][1], O[2][1], X[2][1]);
            else if(x == n) printf("%d %d %d\n", A[n - 1][0], O[n - 1][0], X[n - 1][0]);
            else printf("%d %d %d\n", A[x - 1][0] & A[x + 1][1], O[x - 1][0] | O[x + 1][1], X[x - 1][0] ^ X[x + 1][1]);
        }
    }
    return 0;
}
