#include <iostream>
#include <cstdio>

using namespace std;

char buff[100001];
long long num[100001];


int main()
{
    int T, pos;
    long long ans;

    num[0] = 0;
    for(int i = 1; i <= 100000; i++){
        num[i] = num[i - 1] + i;
    }
    scanf("%d", &T);
    getchar();
    for(int t = 1; t <= T; t++){
        gets(buff);
        pos = ans = 0;
        for(int i = 0; buff[i] != '\0'; i++){
            if(buff[i] == 'q'){
                pos++;
            }else{
                ans += num[pos];
                pos = 0;
            }
        }
        ans += num[pos];
        printf("%I64d\n", ans);
    }

    return 0;
}
