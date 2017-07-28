#include <iostream>
#include <cstdio>

using namespace std;

char s[4][8];

bool Judge(){
    for(int i = 0; i < 4; i++){
        if((s[i][0] == '.' && s[i][2] == s[3][0] && s[i][4] == s[3][0])
           || (s[i][2] == '.' && s[i][0] == s[3][0] && s[i][4] == s[3][0])
           || (s[i][4] == '.' && s[i][0] == s[3][0] && s[i][2] == s[3][0])
           ) return true;
        if((s[0][i] == '.' && s[1][i] == s[3][0] && s[2][i] == s[3][0])
           || (s[1][i] == '.' && s[0][i] == s[3][0] && s[2][i] == s[3][0])
           || (s[2][i] == '.' && s[0][i] == s[3][0] && s[1][i] == s[3][0])
           ) return true;
    }
    if((s[0][0] == '.' && s[1][2] == s[3][0] && s[2][4] == s[3][0])
       || (s[1][2] == '.' && s[0][0] == s[3][0] && s[2][4] == s[3][0])
       || (s[2][4] == '.' && s[0][0] == s[3][0] && s[1][2] == s[3][0])
       || (s[0][4] == '.' && s[1][2] == s[3][0] && s[2][0] == s[3][0])
       || (s[1][2] == '.' && s[0][4] == s[3][0] && s[2][0] == s[3][0])
       || (s[2][0] == '.' && s[0][4] == s[3][0] && s[1][2] == s[3][0])
       ) return true;
    if(s[1][2] == s[3][0]){
        if((s[0][0] == s[3][0] && s[2][0] == '.' && s[0][4] == '.' && (s[1][0] == '.' || s[0][2] == '.'))
           || (s[0][4] == s[3][0] && s[0][0] == '.' && s[2][4] == '.' && (s[0][2] == '.' || s[1][4] == '.'))
           || (s[2][4] == s[3][0] && s[0][4] == '.' && s[2][0] == '.' && (s[1][4] == '.' || s[2][2] == '.'))
           || (s[2][0] == s[3][0] && s[2][4] == '.' && s[0][0] == '.' && (s[2][2] == '.' || s[1][0] == '.'))
           ) return true;
    }
    return false;
}

int main()
{
    int T;

    scanf("%d", &T);
    getchar();

    for(int cas = 1; cas <= T; cas++){
        for(int i = 0; i < 4; i++) gets(s[i]);
        printf("%s\n", Judge() ? "Kim win!" : "Cannot win!");
    }
    return 0;
}
