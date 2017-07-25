#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

set<int> S;
set<int>::iterator it;

int main()
{
    int n, m, x;
    while(scanf("%d%d", &n, &m) != EOF){
        S.clear();
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            S.insert(x);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &x);
            S.insert(x);
        }
        it = S.begin();
        printf("%d", *it);
        ++it;
        for(; it != S.end(); ++it){
            printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}
