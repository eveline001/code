#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int s[1000001];
bool vis[1001];

int main()
{
    int T, n;

    memset(s, 0, sizeof(s));
    for(int i = 1; i <= 500000; i++){
        for(int j = i + i; j <= 1000000; j += i){
            s[j] += i;
        }
    }
    s[0] = s[1] = 0;
    memset(vis, false, sizeof(vis));
    for(int i = 0; i <= 1000000; i++){
        if(s[i] <= 1000){
            vis[s[i]] = true;
        }
    }
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        if(vis[n]){
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
    return 0;
}
