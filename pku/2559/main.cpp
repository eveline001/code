#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    long long h;
    int w;
};

Node stk[100010];
int top;
long long h[100010];

int main()
{
    int n;
    long long ans;

    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; i++) scanf("%lld", &h[i]);
        ans = h[n] = top = stk[0].h = stk[0].w = 0;
        for (int i = 0; i <= n; i++) {
            if (stk[top].h <= h[i]) {
                stk[++top].h = h[i];
                stk[top].w = 1;
            } else {
                int len = 0;
                while (stk[top].h > h[i]) {
                    len += stk[top].w;
                    ans = max(ans, stk[top].h * len);
                    top--;
                }
                stk[++top].h = h[i];
                stk[top].w = len + 1;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
