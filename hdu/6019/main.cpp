#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 7;

int a[MAXN];
set<int> S;

int main()
{
    int T, n, ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        ans = 1;
        S.clear();
        for(int i = 0; i < n; i++){
            if(S.count(a[i])){
                ans++;
                S.clear();
            }
            S.insert(a[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
