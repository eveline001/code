#include <iostream>
#include <cstdio>

using namespace std;

void ReSet(int fat[], int dlt[], int n){
    for(int i = 1; i <= n; i++){fat[i] = i; dlt[i] = 0;}
}

int FindFather(int fat[], int dlt[], int x, int depth){
    if(fat[x] == x) return x;
    int fx = FindFather(fat, dlt, fat[x], depth);
    dlt[x] = (dlt[x] + dlt[fat[x]]) % depth;
    fat[x] = fx;
    return fx;
}

int Merge(int fat[], int dlt[], int a, int b, int delta, int depth){
    int fa = FindFather(fat, dlt, a, depth),
        fb = FindFather(fat, dlt, b, depth);

    if(fb == fa) return 0;
    fat[fb] = fa;
    dlt[fb] = (dlt[a] - dlt[b] - delta + 3) % depth;
    return 1;
}

int F[50001], D[50001];

int main()
{
    int N, K, delta, x, y, ans = 0;

    scanf("%d%d", &N, &K);
    ReSet(F, D, N);
    for(int i = 0 ; i < K; i++)
    {
        scanf("%d%d%d", &delta, &x, &y);
        if(x > N || y > N || (x == y && delta == 2)){ans++; continue;}
        if(FindFather(F, D, x, 3) == FindFather(F, D, y, 3) && (D[x] - D[y] + 3) % 3 != delta - 1){ans++; continue;}
        Merge(F, D, x, y, delta - 1, 3);
    }
    printf("%d\n", ans);
}
