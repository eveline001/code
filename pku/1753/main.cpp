#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool vis[1 << 16];

int flip(int dp, int x, int y){
    if((dp >> (x * 4 + y)) & 1) dp -= 1 << (x * 4 + y);
        else dp += 1 << (x * 4 + y);
    if(x - 1 >= 0){
        if((dp >> ((x - 1) * 4 + y)) & 1) dp -= 1 << ((x - 1) * 4 + y);
            else dp += 1 << ((x - 1) * 4 + y);
    }
    if(x + 1 <= 3){
        if((dp >> ((x + 1) * 4 + y)) & 1) dp -= 1 << ((x + 1) * 4 + y);
            else dp += 1 << ((x + 1) * 4 + y);
    }
    if(y - 1 >= 0){
        if((dp >> (x * 4 + y - 1)) & 1) dp -= 1 <<  (x * 4 + y - 1);
            else dp += 1 << (x * 4 + y - 1);
    }
    if(y + 1 <= 3){
        if((dp >> (x * 4 + y + 1)) & 1) dp -= 1 << (x * 4 + y + 1);
            else dp += 1 << (x * 4 + y + 1);
    }
    return dp;
}

int stk[1 << 16];
int bfs(int dp){
    if(dp == 0 || dp == 65535) return 0;
    int deep = 1, begin = 0, end = 0, next, num;
    vis[dp] = true;
    stk[begin] = dp;
    while(begin < end + 1){
        num = 0;
        for(int k = begin; k <= end; k++){
            for(int i = 0; i <= 3; i++)
                for(int j = 0; j <= 3; j++){
                    next = flip(stk[k], i, j);
                    if(next == 0 || next == 65535) return deep;
                    if(!vis[next]){
                        vis[next] = true;
                        num++;
                        stk[end + num] = next;
                    }
            }
        }
        deep++;
        begin = end + 1;
        end = end + num;
    }
    return -1;
}

int main()
{
    char buf[5];
    int dp;

    dp = 0;
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < 4; i++){
        gets(buf);
        for(int j= 0; j < 4; j++){
            if(buf[j] == 'b') dp += 1 << (i * 4 + j);
        }
    }
    int ans = bfs(dp);
    if(ans != -1) printf("%d\n", ans);
        else printf("Impossible\n");
}
