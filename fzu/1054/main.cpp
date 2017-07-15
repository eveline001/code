#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[210];

int main()
{
    int n;

    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
            gets(s);
            for(int i = strlen(s) - 1; i >= 0; i--) printf("%c", s[i]);
            printf("\n");
        }
    }
    return 0;
}
