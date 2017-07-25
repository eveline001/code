#include <iostream>
#include <cstdio>

using namespace std;

char  buff[51];
char* s;

int main()
{
    int T;

    scanf("%d", &T);
    getchar();
    for(int cas = 1; cas <= T; cas++){
        gets(buff);
        s = buff;
        if((*s > 'z' || *s < 'A' || (*s > 'Z' && *s < 'a')) && *s != '_'){
            puts("no");
            continue;
        }
        s++;
        for(int i = 1; *s != '\0'; i++){
            if((*s > 'z' || *s < '0' || (*s < 'A' && *s > '9') || (*s > 'Z' && *s < 'a')) && *s != '_'){
                puts("no");
                break;
            }
            s++;
        }
        if(*s == '\0'){
            puts("yes");
        }
    }
    return 0;
}
