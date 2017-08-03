#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[8][32];
int n[2][2][2][2][2][2][2];

int get(int p, int x){
    if(x == 0) return (*(s[0] + p + 1) == 'X' && *(s[0] + p + 2) == 'X') ? 1 : 0;
    if(x == 1) return (*(s[1] + p + 3) == 'X' && *(s[2] + p + 3) == 'X') ? 1 : 0;
    if(x == 2) return (*(s[4] + p + 3) == 'X' && *(s[5] + p + 3) == 'X') ? 1 : 0;
    if(x == 3) return (*(s[6] + p + 1) == 'X' && *(s[6] + p + 2) == 'X') ? 1 : 0;
    if(x == 4) return (*(s[4] + p + 0) == 'X' && *(s[5] + p + 0) == 'X') ? 1 : 0;
    if(x == 5) return (*(s[1] + p + 0) == 'X' && *(s[2] + p + 0) == 'X') ? 1 : 0;
    if(x == 6) return (*(s[3] + p + 1) == 'X' && *(s[3] + p + 2) == 'X') ? 1 : 0;
    return 0;
}

int main()
{
    int T, H1, H2, M1, M2;

    scanf("%d", &T);
    memset(n, -1, sizeof(n));
    n[1][1][1][1][1][1][0] = 0;
    n[0][1][1][0][0][0][0] = 1;
    n[1][1][0][1][1][0][1] = 2;
    n[1][1][1][1][0][0][1] = 3;
    n[0][1][1][0][0][1][1] = 4;
    n[1][0][1][1][0][1][1] = 5;
    n[1][0][1][1][1][1][1] = 6;
    n[1][1][1][0][0][0][0] = 7;
    n[1][1][1][1][1][1][1] = 8;
    n[1][1][1][1][0][1][1] = 9;
    for(int cas = 1; cas <= T; cas++){
        for(int i = 0; i < 7; i++) scanf("%s", s[i]);
        H1 = n[get(0, 0)][get(0, 1)][get(0, 2)][get(0, 3)][get(0, 4)][get(0, 5)][get(0, 6)];
        H2 = n[get(5, 0)][get(5, 1)][get(5, 2)][get(5, 3)][get(5, 4)][get(5, 5)][get(5, 6)];
        M1 = n[get(12, 0)][get(12, 1)][get(12, 2)][get(12, 3)][get(12, 4)][get(12, 5)][get(12, 6)];
        M2 = n[get(17, 0)][get(17, 1)][get(17, 2)][get(17, 3)][get(17, 4)][get(17, 5)][get(17, 6)];
        printf("%d%d:%d%d\n", H1, H2, M1, M2);
    }
    return 0;
}
