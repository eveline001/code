#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char s[3000010];

int main()
{
    int T, temp, res;

    scanf("%d", &T);
    getchar();
    for(int cas = 1; cas <= T; cas++){
        gets(s);
        temp = strlen(s);
        if(temp == 0){printf("00\n"); continue;}
        while(temp){
            res = temp & 127;
            temp >>= 7;
            if(temp) res += 128;
            printf("%02X", res);
        }
        for(int i = 0; s[i] != '\0'; i++) printf("%02X", s[i]);
        printf("\n");
    }
    return 0;
}