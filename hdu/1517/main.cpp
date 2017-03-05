#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long n, begin;
    bool flag;

    while(scanf("%I64d", &n) != EOF)
    {
        if(n % 9 == 0) begin = n / 9; else begin = n / 9 + 1;
        flag = true;
        while(begin > 1){
            if(flag){if(begin % 2 == 0) begin = begin / 2; else begin = begin / 2 + 1;}else{if(begin % 9 == 0) begin = begin / 9; else begin = begin/ 9 + 1;}
            flag = !flag;
        }
        if(flag) printf("Stan wins.\n"); else printf("Ollie wins.\n");
    }
    return 0;
}
