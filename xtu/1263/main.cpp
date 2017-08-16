#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char x[20][20];

int main()
{
    int n, m, a, b;

    while(scanf("%d%d%d%d", &n, &m, &a, &b) != EOF){
        getchar();
        for(int i = 0; i < n; i++) scanf("%s", x[i]);
        for(int i = 0; i < n; i++) for(int k = 0; k < a; k++){
                for(int j = 0; j < m; j++) for(int l = 0; l < b; l++) printf("%c", x[i][j]);
                printf("\n");
        }
    }
    return 0;
}
