#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int que[200000];
int stk[200000];
int len[200000];

int LowerBound(int L, int R, int x)
{
    int M;
    while(L <= R)
    {
        M = L + ((R - L) >> 1);
        if(stk[M] == x) return M;
        if(stk[M] < x) L = M + 1;
        else R = M - 1;
    }
    return L;
}

int main()
{
    int T, n, top, pos;

    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &que[i]);
        memset(stk, 0, sizeof(stk));
        memset(len, 0, sizeof(len));
        top = 0;
        for(int i = 0; i < n; i++)
        {
            if(que[i] > stk[top]){stk[++top] = que[i]; len[i] = top;}
            else{pos = LowerBound(1, top, que[i]); stk[pos] = que[i]; len[i] = pos;}
        }
        printf("%d", len[0]);
        for(int i = 1; i < n; i++) printf(" %d",len[i]);
        printf("\n");
    }
    return 0;
}
