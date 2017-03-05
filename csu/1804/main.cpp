#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 1e+9 + 7;

struct ADJ{
    int x;
    int num;
    int *next[100000];
};

int a[100001], b[100001];

ADJ List[100001];

int main()
{
    int n, m;
    int x, y;

    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &a[i], &b[i]);
        }
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &x, &y)

        }
    }
}
