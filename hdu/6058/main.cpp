#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 5e5 + 7;

int a[MAXN], p[MAXN], t[100], y[100];

struct Node{
    int num;
    Node *pre, *next;
};

Node Q[MAXN];

int main()
{
    int T, n, k, times;
    long long ans, cnt;
    Node* it;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            p[a[i]] = i;
            Q[i].num = a[i];
            Q[i].pre = &Q[i - 1];
            Q[i].next = &Q[i + 1];
        }
        Q[0].num = 0, Q[n + 1].num = n + 1;
        p[0] = 0, p[n + 1] = n + 1;
        ans = 0;
        for(int i = 1; i <= n - k + 1; i++){
            memset(y, 0, sizeof(y));
            for(times = 1, it = &Q[p[i]]; (it->num != 0) && times <= k + 1; times++, it = it->pre){
                y[times] = p[it->num] - p[it->pre->num];
            }
            memset(t, 0, sizeof(t));
            for(times = 1, it = &Q[p[i]]; (it->num != n + 1) && times <= k + 1; times++, it = it->next){
                t[times] = p[it->next->num] - p[it->num];
            }
            Q[p[i]].pre->next = Q[p[i]].next;
            Q[p[i]].next->pre = Q[p[i]].pre;
            cnt = 0;
            for(int j = 1; j <= k; j++) cnt += (long long)y[j] * t[k + 1 - j];
            ans += cnt * i;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
