#include <iostream>
#include <cstdio>

using namespace std;

char s[1001];

int main()
{
    int n, num;

    scanf("%d", &n);
    getchar();
    for(int cas = 1; cas <= n; cas++){
        gets(s);
        num = 0;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] <= '9' && s[i] >= '0'){
                num++;
            }
        }
        printf("%d\n", num);
    }
    return 0;
}
