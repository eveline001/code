#include <iostream>
#include <cstdio>

using namespace std;

char s[1000000];

int main()
{
    int T, cnt;

    scanf("%d", &T);
    getchar();
    for(int t = 1; t <= T; t++){
        cnt = 0;
        gets(s);
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == '0' || s[i] == '4' || s[i] == '6' || s[i] == '9'){
                cnt++;
            }else if(s[i] == '8'){
                cnt += 2;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
