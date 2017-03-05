#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

int que[100001];
bool vis[100001];

bool Judge(int k, int len){
    map<int, int> a, b;

    a.clear();
    for(int i = 0; i < k; i++){
        a[que[i]]++;
    }
    for(int s = k; s < len; s += k){
        b.clear();
        for(int i = 0; i < k; i++){
            b[que[s + i]]++;
        }
        if(a != b){
            return false;
        }
    }

    return true;
}

int main()
{
    int T, len;

    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d", &len);
        for(int i = 0; i < len; i++){
            scanf("%d", &que[i]);
        }
        memset(vis, false, sizeof(vis));
        vis[len] = true;
        for(int i = 1; i <= len / 2; i++){
            if(vis[i]) continue;
            if(len % i == 0 && Judge(i, len)){
                for(int k = i; k < len; k += i){
                    if(!vis[i] && len % k == 0){
                        vis[i] = true;
                    }
                }
            }
        }
        for(int i = 1; i <= len /2; i++){
            if(vis[i]){
                printf("%d ", i);
            }
        }
        printf("%d\n", len);
    }
}
