#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    char s[4];
    while(gets(s) != NULL){
        sort(s, s + 3);
        printf("%c %c %c\n", s[0], s[1], s[2]);
    }
    return 0;
}
