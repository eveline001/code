#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node{
    int pos, time;
};

queue<Node> Q;
int dp[100001];

int bfs(int st, int ed){
    Node s{st, 0};
    while(!Q.empty()) Q.pop();
    Q.push(s);
    dp[st] = 0;
    while(!Q.empty()){
        Node u = Q.front();
        Q.pop();
        if(u.pos == ed) return u.time;
        if(u.pos * 2 <= 100000 && (dp[u.pos * 2] == -1 || dp[u.pos * 2] > u.time + 1)){dp[u.pos * 2] = u.time + 1; Q.push(Node{u.pos * 2, u.time + 1});}
        if(u.pos + 1 <= 100000 && (dp[u.pos + 1] == -1 || dp[u.pos + 1] > u.time + 1)){dp[u.pos + 1] = u.time + 1; Q.push(Node{u.pos + 1, u.time + 1});}
        if(u.pos - 1 >=      0 && (dp[u.pos - 1] == -1 || dp[u.pos - 1] > u.time + 1)){dp[u.pos - 1] = u.time + 1; Q.push(Node{u.pos - 1, u.time + 1});}
    }
    return -1;
}

int main()
{
    int N, K;

    while(scanf("%d%d", &N, &K) != EOF){
        memset(dp, -1, sizeof(dp));
        printf("%d\n", bfs(N, K));
    }
    return 0;
}
