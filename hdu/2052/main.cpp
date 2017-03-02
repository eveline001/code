#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, m;

    while(scanf("%d%d", &n, &m) != EOF){
        printf("+");
        for(int i = 0; i < n; i++){
            printf("-");
        }
        printf("+\n");
        for(int i = 0; i < m; i++){
            printf("|");
            for(int j = 0; j < n; j++){
                printf(" ");
            }
            printf("|\n");
        }
        printf("+");
        for(int i = 0; i < n; i++){
            printf("-");
        }
        printf("+\n\n");
    }
    return 0;
}
