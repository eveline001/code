#include <iostream>
#include <cstdio>

using namespace std;

char s[100];

int main()
{
    while(gets(s) != NULL){
        for(int i = 0; s[i] != '\0'; i++){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
                if((s[i] <= 'C') || (s[i] >= 'a' && s[i] <= 'c')) printf("%c", s[i] + 23);
                else printf("%c", s[i] - 3);
            }else{
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
