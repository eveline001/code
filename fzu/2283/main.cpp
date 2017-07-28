#include <iostream>
#include <cstdio>

using namespace std;

char s[4][8];

bool Judge(){
    for(int i = 0; i < 4; i++){
        if((s[i][0] == '.' && s[i][2] == s[4][0] && s[i][4] == s[4][0])
           || (s[i][2] == '.' && s[i][0] == s[4][0] && s[i][4] == s[4][0])
           || (s[i][4] == '.' && s[i][0] == s[4][0] && s[i][2] == s[4][0])
           ) return true;
        if((s[0][i] == '.' && s[1][i] == s[4][0] && s[2][i] == s[4][0])
           || (s[1][i] == '.' && s[0][i] == s[4][0] && s[2][i] == s[4][0])
           || (s[2][i] == '.' && s[0][i] == s[4][0] && s[1][i] == s[4][0])
           ) return true;
    }
    // 老子不想写了反正你知道这就是个脑残题老子过了！！！
    // fzu的contest为什么我自己提交的代码还不能看了！！！
    // 摔！！！
    // 话说你这支持utf8吧...
}

int main()
{
    int T;

    scanf("%d", &T);

    for(int cas = 1; cas <= T; cas++){
        for(int i = 0; i < 4; i++) scanf("%s", s[i]);
        printf("%s\n", Judge() ? "Kim win!" : "Cannot win!");
    }
}
