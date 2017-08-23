#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s0[1000000], s1[1000000];

bool GetStr(char* s){
    while(true){
        *s = getchar();
        if(*s == '\n' || *s == '\0' || *s == ' '){*s = '\0'; return true;}
        if(*s == EOF) return false;
        s++;
    }
}

int main()
{
    int p0, p1;
    bool ans, point;

    while(true){
        if(!GetStr(s0)) break;
        if(!GetStr(s1)) break;
        ans = true, point = false;
        for(p0 = p1 = 0; s0[p0] != '\0' && s1[p1] != '\0'; p0++, p1++){
            if(s0[p0] == '.' || s1[p1] == '.') point = true;
            if(s0[p0] != s1[p1]){ans = false; break;}
        }
        if(ans){
            if(s0[p0] != '\0'){
                if(s0[p0] == '.' || point) for(; s0[p0] != '\0'; p0++){if(s0[p0] != '0' && s0[p0] != '.'){ans = false; break;}}
                else ans = false;
            }else if(s1[p1] != '\0'){
                if(s1[p1] == '.' || point) for(; s1[p1] != '\0'; p1++){if(s1[p1] != '0' && s1[p1] != '.'){ans = false; break;}}
                else ans = false;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
