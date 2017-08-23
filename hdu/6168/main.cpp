#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

map<int, int> M;
int v[125260], ans[125250], tol, cnt;

int main()
{
    while(scanf("%d", &tol) != EOF){
        M.clear();
        for(int i = 0; i < tol; i++){
            scanf("%d", &v[i]);
            M[v[i]]++;
        }
        sort(v, v + tol);
        ans[0] = v[0], ans[1] = v[1], cnt = 2;
        M[v[0]]--, M[v[1]]--, M[v[0] + v[1]]--;
        for(int i = 2; i < tol; i++){
            if(M[v[i]]){
                for(int it = 0; it < cnt; it++) M[v[i] + ans[it]]--;
                ans[cnt++] = v[i], M[v[i]]--;
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < cnt - 1; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[cnt - 1]);
    }
    return 0;
}
