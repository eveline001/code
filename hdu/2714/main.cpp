#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int tol, pos, ans;
    char s[12];

    while(gets(s) != NULL){
        tol = 0;
        for(int i = 0; i < 10; i++) if(s[i] == '?'){pos = i; break;}
        for(int i = 0; i < 9; i++) if(s[i] != '?') tol += (10 - i) * (s[i] - '0');
        if(s[9] == 'X') tol += 10; else if(s[9] != '?') tol += s[9] - '0';
        ans = -1;
        for(int i = 0; i < 10; i++) if((tol + i * (10 - pos)) % 11 == 0){ans = i; break;}
        if(pos == 9) if((tol + 10) % 11 == 0) ans = 10;
        if(ans < 10) printf("%d\n", ans); else printf("X\n");
    }
    return 0;
}
