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
    // ���Ӳ���д�˷�����֪������Ǹ��Բ������ӹ��ˣ�����
    // fzu��contestΪʲô���Լ��ύ�Ĵ��뻹���ܿ��ˣ�����
    // ˤ������
    // ��˵����֧��utf8��...
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
