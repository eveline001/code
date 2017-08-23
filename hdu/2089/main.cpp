//http://blog.csdn.net/wust_zzwh/article/details/52100392
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long DDP[20][2];
int TN[20];

long long DigtialDFS(int pos, int pre, int sta, bool lead, bool limit){
    if(pos == -1) return 1;
    if(!lead && !limit && DDP[pos][sta] != -1) return DDP[pos][sta];
    int up = limit ? TN[pos] : 9;
    long long res = 0;
    for(int i = 0; i <= up; i++){
        if(i == 4 || (pre == 6 && i == 2)) continue;
        res += DigtialDFS(pos - 1, i, i == 6, lead && i == 0, limit && i == TN[pos]);
    }
    if(!limit) DDP[pos][sta] = res;
    return res;
}

long long DigtialDP(int x){
    int pos = 0;
    while(x) TN[pos++] = x % 10, x /= 10;
    return DigtialDFS(pos - 1, -1, 0, true, true);
}

int main()
{
    int n, m;

    memset(DDP, -1LL, sizeof(DDP));
    while(scanf("%d%d", &n, &m) != EOF && (n || m)) printf("%I64d\n", DigtialDP(m) - DigtialDP(n - 1));
    return 0;
}
