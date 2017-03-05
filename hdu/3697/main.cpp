#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Cour{
    int A, B;
};

bool comp(const Cour& A, const Cour& B)
{
    if(A.B == B.B) return A.A < B.A;
    return A.B < B.B;
}

Cour C[1010];
int vis[1010];
int n;

int getmax(int x)
{
    int res = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = x; i < C[n-1].B; i += 5)
        for(int j = 0; j < n; j++)
            if(!vis[j] && C[j].A <= i && C[j].B > i){
                res++;
                vis[j] = 1;
                break;
            }
    return res;
}

int main()
{
    int ans, temp, i;

    while(scanf("%d", &n)+1 && n)
    {
        for(int i = 0; i < n; i++) scanf("%d%d", &C[i].A, &C[i].B);
        ans = 0;
        sort(C, C+n, comp);
        for(i = 0; i <= 1000; i++)
        {
            temp = getmax(i);
            if(temp > ans) ans = temp;
        }
        printf("%d\n", ans);
    }
}
