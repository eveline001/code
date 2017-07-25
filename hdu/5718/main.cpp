#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char a[10000001];

bool comp(const char a, const char b)
{
    return a > b;
}

void sum(char b, int len)
{
    int i;
    for(i = len-1; i >= 0; i--)
    {
        if(b != '0'){
            if(a[i]-'0' + b-'0' >= 10){
                a[i] = a[i]-'0' + b - 10;
                b = '1';
            }else{
                a[i] = a[i]-'0' + b;
                b = '0';
            }
        }
    }
    if(b != '0') printf("%c", b);
    for(i = 0; i < len; i++) printf("%c", a[i]);
    printf("\n");
}

int main()
{
    int T;
    int l;
    int i;
    char b;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", a);
        l = strlen(a);
        if(l == 1){printf("Uncertain\n"); continue;}
        sort(a, a+l , comp);
        for(i = l-1; i >= 0; i--)if(a[i] != '0'){b = a[i]; a[i] = '0'; break;}
        if(i == 0){printf("Uncertain\n"); continue;}
        a[l-1] = '\0';
        sum(b, l-1);
    }
}
