// stl
#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

map<int, int> M;

int main()
{
    int n, x;

    while(scanf("%d", &n) != EOF){
        M.clear();
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            M[x]++;
        }
        for(auto it = M.begin(); it != M.end(); ++it){
            if(it->second >= (n + 1) / 2){
                printf("%d\n", it->first);
                break;
            }
        }
    }
    return 0;
}

//dp
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, x, ans, times;

    while(scanf("%d", &n) != EOF){
        times = 0;
        for(int i = 0; i < n; i++){ // cuz n is an odd number and the ans should appear at least (n + 1) / 2 times, thus value of times >= 1
            scanf("%d", &x);
            if(times == 0){
                ans = x;
                times++;
            }else{
                if(ans == x) times++;
                else times--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
