#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[10001];

int judge(){
    int res = 0;
    int len = strlen(s + 1);

    for(int i = 1; i <= len; i++){
        for(int p = 2; i * p * p <= len; p++){
            if((s[i] == 'y' && s[i * p] == 'r' && s[i * p *p] == 'x') || (s[i * p * p] == 'y' && s[i * p] == 'r' && s[i] == 'x')){
                res++;
            }
        }
    }
    return res;
}

int main()
{
    int T, ans;

    scanf("%d", &T);
    getchar();
    for(int t = 1; t <= T; t++){
        gets(s + 1);
        ans = judge();
        printf("%d\n", ans);
    }
    return 0;
}
